#include <stdio.h>
#include <string.h>

// Function prototypes
void create_account();
void deposit_money();
void withdraw_money();
void check_balance();

// File to store account data
const char* ACCOUNT_FILE = "account.dat";

// Account structure
typedef struct {
    char name[50];
    int acc_no;
    float balance;
} Account;

int main() {
    int choice;

    while (1) {
        // Display Menu
        printf("\n--- Bank Management System ---");
        printf("\n1. Create Account");
        printf("\n2. Deposit Money"); 
        printf("\n3. Withdraw Money");
        printf("\n4. Check Balance");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        // Perform actions based on user choice
        switch (choice) {
            case 1:
                create_account();
                break;
            case 2:
                deposit_money();
                break;
            case 3:
                withdraw_money();
                break;
            case 4:
                check_balance();
                break;
            case 5:
                printf("\nClosing the bank. Thanks for your visit!\n");
                return 0;
            default:
                printf("\nInvalid choice. Please try again.\n");
                break;
        }
    }
}

// Function to create a new account
void create_account() {
    Account acc;
    FILE *file = fopen(ACCOUNT_FILE, "ab+");
    if (file == NULL) {
        printf("\nUnable to open file.");
        return;
    }

    // Clear input buffer
    while (getchar() != '\n');

    printf("\nEnter your name: ");
    fgets(acc.name, sizeof(acc.name), stdin);
    acc.name[strcspn(acc.name, "\n")] = '\0';  // Remove newline

    printf("Enter your account number: ");
    scanf("%d", &acc.acc_no);

    acc.balance = 0.0; // Initial balance

    fwrite(&acc, sizeof(acc), 1, file);
    fclose(file);
    printf("\nAccount created successfully!\n");
}

// Function to deposit money into an account
void deposit_money() {
    FILE *file = fopen(ACCOUNT_FILE, "rb+");
    if (file == NULL) {
        printf("\nUnable to open file.");
        return;
    }

    int acc_no;
    float money;
    Account acc;

    printf("\nEnter your account number: ");
    scanf("%d", &acc_no);
    printf("Enter amount to deposit: ");
    scanf("%f", &money);

    while (fread(&acc, sizeof(acc), 1, file)) {
        if (acc.acc_no == acc_no) {
            acc.balance += money;
            fseek(file, -sizeof(acc), SEEK_CUR); // Move file pointer back
            fwrite(&acc, sizeof(acc), 1, file);  // Update record
            fclose(file);
            printf("Successfully deposited Rs. %.2f. New balance: Rs. %.2f\n", money, acc.balance);
            return;
        }
    }

    fclose(file);
    printf("Account number %d not found. Deposit failed.\n", acc_no);
}

// Function to withdraw money from an account
void withdraw_money() {
    FILE *file = fopen(ACCOUNT_FILE, "rb+");
    if (file == NULL) {
        printf("\nUnable to open the file.");
        return;
    }

    int acc_no;
    float money;
    Account acc;

    printf("Enter your account number: ");
    scanf("%d", &acc_no);
    printf("Enter amount to withdraw: ");
    scanf("%f", &money);

    while (fread(&acc, sizeof(acc), 1, file)) {
        if (acc.acc_no == acc_no) {
            if (acc.balance >= money) {
                acc.balance -= money;
                fseek(file, -sizeof(acc), SEEK_CUR);
                fwrite(&acc, sizeof(acc), 1, file);
                fclose(file);
                printf("Successfully withdrew Rs. %.2f. Remaining balance: Rs. %.2f\n", money, acc.balance);
                return;
            } else {
                printf("Insufficient Balance.\n");
                fclose(file);
                return;
            }
        }
    }

    fclose(file);
    printf("Account number %d not found. Withdrawal failed.\n", acc_no);
}

// Function to check the balance of an account
void check_balance() {
    Account acc;
    FILE *file = fopen(ACCOUNT_FILE, "rb");
    if (file == NULL) {
        printf("\nUnable to open file.");
        return;
    }

    int acc_no;
    printf("\nEnter your account number: ");
    scanf("%d", &acc_no);

    while (fread(&acc, sizeof(acc), 1, file)) {
        if (acc.acc_no == acc_no) {
            printf("Account Holder: %s\n", acc.name);
            printf("Your account balance is Rs. %.2f\n", acc.balance);
            fclose(file);
            return;
        }
    }

    fclose(file);
    printf("Account number %d not found.\n", acc_no);
}
