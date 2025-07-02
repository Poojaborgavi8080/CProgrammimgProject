#include <stdio.h>      // For input-output functions
#include <unistd.h>     // For sleep() function (POSIX systems)
#include <stdlib.h>     // For rand(), srand(), system()
#include <time.h>       // For time() to seed the random number generator

// Constants
const int BAR_LENGTH = 50;    // Length of the progress bar in characters
const int MAX_TASKS = 5;      // Maximum number of tasks

// Structure to store task information
typedef struct {
    int id;         // Unique task ID
    int progress;   // Current progress (0 to 100)
    int step;       // Amount by which progress increases each time
} Task;

// Function declarations
void print_bar(Task task);    // Function to print the progress bar of a task
void clear_screen();          // Function to clear the terminal screen

int main() {
    Task tasks[MAX_TASKS];    // Array of tasks

    // Seed the random number generator with current time
    srand(time(NULL));

    // Initialize tasks with random step values and 0 progress
    for (int i = 0; i < MAX_TASKS; i++) {
        tasks[i].id = i + 1;                     // Task ID: 1 to MAX_TASKS
        tasks[i].progress = 0;                   // Initial progress = 0
        tasks[i].step = rand() % 5 + 1;          // Random step between 1 and 5
    }

    int tasks_incomplete = 1;    // Flag to check if any task is incomplete

    // Main loop runs until all tasks reach 100% progress
    while (tasks_incomplete) {
        tasks_incomplete = 0;   // Assume all tasks complete unless updated
        clear_screen();         // Clear the screen for smooth animation

        for (int i = 0; i < MAX_TASKS; i++) {
            // If task is not yet complete, update progress
            if (tasks[i].progress < 100) {
                tasks[i].progress += tasks[i].step;     // Increase progress
                if (tasks[i].progress > 100)            // Don't exceed 100
                    tasks[i].progress = 100;

                tasks_incomplete = 1;                   // At least one task incomplete
            }

            // Print the progress bar of the task
            print_bar(tasks[i]);
        }

        sleep(1);   // Wait for 1 second before next update
    }

    // All tasks completed
    printf("All tasks completed!\n");
    return 0;
}

// Function to clear the terminal screen
void clear_screen() {
#ifdef _WIN32
    system("cls");     // Clear screen in Windows
#else
    system("clear");   // Clear screen in Unix/Linux/macOS
#endif
}

// Function to print a visual progress bar for a task
void print_bar(Task task) {
    int bars_to_show = (task.progress * BAR_LENGTH) / 100;  // Number of '=' to show

    printf("Task %d: [", task.id);     // Start the progress bar

    for (int i = 0; i < BAR_LENGTH; i++) {
        if (i < bars_to_show)
            printf("=");   // Print completed part
        else
            printf(" ");   // Print remaining space
    }

    printf("] %d%%\n", task.progress);  // Print progress percentage
}
