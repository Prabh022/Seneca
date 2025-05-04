#define _CRT_SECURE_NO_WARNINGS
// main.c

#include <stdio.h>
#include "expense.h"

int main() {
    int choice;
    while (1) {
        printf("\n=== Expense Tracker ===\n");
        printf("1. Add Expense\n");
        printf("2. View Expenses\n");
        printf("3. Edit Expense\n");
        printf("4. Delete Expense\n");
        printf("5. Summary Report\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1: addExpense(); break;
        case 2: viewExpenses(); break;
        case 3: editExpense(); break;
        case 4: deleteExpense(); break;
        case 5: showSummary(); break;
        case 6: return 0;
        default: printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}
