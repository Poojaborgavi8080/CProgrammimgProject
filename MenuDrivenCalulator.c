#include <stdio.h>

void printMenu() {
    printf("\n ______________________________________");
    printf("\nWelcome to Simple Calculator...");
    printf("\nWhich arithmetic operation do you want to perform?");
    printf("\n1. Addition");
    printf("\n2. Subtraction");
    printf("\n3. Multiplication");
    printf("\n4. Division");
    printf("\n5. Modulus");
    printf("\n6. Exit");
}

int main() {
    int x, y, choice;

    while (1) {
        printMenu();
        printf("\n\nNow, enter your choice: ");
        scanf("%d", &choice);

        if (choice == 6) {
            printf("\nExiting the program. Thank you!\n");
            break;
        }

        printf("\nEnter first number: ");
        scanf("%d", &x);
        printf("Enter second number: ");
        scanf("%d", &y);

        switch (choice) {
            case 1:
                printf("Addition is: %d\n", x + y);
                break;
            case 2:
                printf("Subtraction is: %d\n", x - y);
                break;
            case 3:
                printf("Multiplication is: %d\n", x * y);
                break;
            case 4:
                if (y != 0)
                    printf("Division is: %d\n", x / y);
                else
                    printf("Error: Division by zero is not allowed.\n");
                break;
            case 5:
                if (y != 0)
                    printf("Modulus is: %d\n", x % y);
                else
                    printf("Error: Modulus by zero is not allowed.\n");
                break;
            default:
                printf("Please enter a valid choice (1-6).\n");
        }
    }

    return 0;
}
