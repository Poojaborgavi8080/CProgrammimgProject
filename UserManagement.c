
#include <stdio.h>         // For standard input/output
#include <string.h>        // For string operations like strcmp, strcspn
#include <unistd.h>        // For Unix-like OS functions (optional, can be removed on Windows)
#include <conio.h>         // For getch(), used to read password without echoing
1
#define MAX_USERS 10               // Maximum number of users that can be registered
#define CREDENTIAL_LENGTH 30       // Maximum length for username and password

// Structure to store user credentials
typedef struct {
    char username[30];
    char password[10];
} User;

// Global array to store all registered users
User users[MAX_USERS];
int user_count = 0;                // Tracks number of registered users

// Function declarations
void register_user();                              // Handles new user registration
int login_user();                                  // Handles user login
void fix_fgets_input(char *);                      // Removes newline from fgets input
void input_credentials(char* username, char* password); // Handles username and password input
void clear_input_buffer();                         // Clears input buffer after scanf

// Main menu loop
int main() {
    int option;            // Menu selection
    int user_index;        // Stores index of logged-in user

    while (1) {
        // Display menu
        printf("\n--- Welcome to User Management ---");
        printf("\n1. Register");
        printf("\n2. Login");
        printf("\n3. Exit");
        printf("\nSelect an option: ");
        
        scanf("%d", &option);       // Read user option
        clear_input_buffer();       // Clear leftover newline to avoid fgets issues

        // Perform selected operation
        switch (option) {
            case 1:
                register_user();    // Register a new user
                break;
            case 2:
                user_index = login_user();   // Try login
                if (user_index >= 0) {
                    printf("\nLogin successful! Welcome, %s\n", users[user_index].username);
                } else {
                    printf("\nLogin failed! Incorrect username or password.\n");
                }
                break;
            case 3:
                printf("\nExiting Program.\n");  // Exit the program
                return 0;
            default:
                printf("\nInvalid option. Please try again.\n");  // Handle invalid input
                break;
        }
    }

    return 0;
}

// Function to register a new user
void register_user() {
    if (user_count == MAX_USERS) {
        // Maximum user limit reached
        printf("\nMaximum %d users supported! Registration full.\n", MAX_USERS);
        return;
    }

    int new_index = user_count;   // Get index for new user

    printf("\nRegister New User:");

    // Get username and password from user
    input_credentials(users[new_index].username, users[new_index].password);

    user_count++;   // Increment the user count

    printf("Registration Successful!\n");
}

// Function to log in a user
int login_user() {
    char username[CREDENTIAL_LENGTH];
    char password[CREDENTIAL_LENGTH];

    // Get login credentials
    input_credentials(username, password);

    // Check if credentials match any registered user
    for (int i = 0; i < user_count; i++) {
        if (strcmp(username, users[i].username) == 0 &&
            strcmp(password, users[i].password) == 0) {
            return i; // Match found, return user index
        }
    }

    return -1; // Login failed
}

// Function to remove trailing newline from fgets input
void fix_fgets_input(char* string) {
    int index = strcspn(string, "\n"); // Find '\n' position
    string[index] = '\0';              // Replace with null character
}

// Function to input both username and password
void input_credentials(char *username, char *password) {
    printf("\nEnter Username: ");
    fgets(username, CREDENTIAL_LENGTH, stdin); // Read username with spaces
    fix_fgets_input(username);                 // Clean newline

    char ch;
    int i = 0;

    printf("Enter Password: ");
    // Read password one character at a time, mask it with '*'
    while ((ch = getch()) != '\r') { // '\r' = Enter key
        if (ch == '\b' && i > 0) {   // Handle backspace
            i--;
            printf("\b \b");         // Erase last '*'
        } else if (i < CREDENTIAL_LENGTH - 1 && ch != '\b') {
            password[i++] = ch;     // Store character
            printf("*");            // Show asterisk
        }
    }
    password[i] = '\0';             // Null-terminate password
    printf("\n");
}

// Function to clear leftover input from stdin buffer (after scanf)
void clear_input_buffer() {
    while (getchar() != '\n');      // Discard characters until newline
}
