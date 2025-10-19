#include <stdio.h>
#include <stdlib.h>

// Define the structure for each day
typedef struct {
    char *dayName;
    int date;
    char *activity;
} Day;

// Function to create a calendar (array of 7 days)
Day* createCalendar() {
    Day *week = (Day*)malloc(7 * sizeof(Day));
    if (week == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    return week;
}

// Function to read the details of each day
void readCalendar(Day *week) {
    for (int i = 0; i < 7; i++) {
        week[i].dayName = (char*)malloc(20 * sizeof(char));
        week[i].activity = (char*)malloc(100 * sizeof(char));

        if (week[i].dayName == NULL || week[i].activity == NULL) {
            printf("Memory allocation failed!\n");
            exit(1);
        }

        printf("Enter name of day %d: ", i + 1);
        scanf("%s", week[i].dayName);

        printf("Enter date for %s: ", week[i].dayName);
        scanf("%d", &week[i].date);

        printf("Enter activity for %s: ", week[i].dayName);
        getchar(); // clear newline left by previous scanf
        scanf("%[^\n]", week[i].activity);
    }
}

// Function to display the calendar
void displayCalendar(Day *week) {
    printf("\n========== WEEK ACTIVITY DETAILS ==========\n");
    for (int i = 0; i < 7; i++) {
        printf("%s (%d): %s\n", week[i].dayName, week[i].date, week[i].activity);
    }
    printf("===========================================\n");
}

// Main function
int main() {
    Day *week = createCalendar();
    printf("\n--- CREATE YOUR WEEKLY CALENDAR ---\n");
    
    readCalendar(week);
    displayCalendar(week);

    // Free allocated memory
    for (int i = 0; i < 7; i++) {
        free(week[i].dayName);
        free(week[i].activity);
    }
    free(week);

    return 0;
}