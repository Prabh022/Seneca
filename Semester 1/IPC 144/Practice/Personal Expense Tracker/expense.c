// expense.c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include "expense.h"
#include "storage.h"

void addExpense() {
    Expense expenses[MAX_EXPENSES];
    int count = loadExpenses(expenses);

    Expense e;
    e.id = generateUniqueId();
    printf("Enter category: ");
    scanf("%s", e.category);
    printf("Enter amount: ");
    scanf("%f", &e.amount);
    printf("Enter date (YYYY-MM-DD): ");
    scanf("%s", e.date);
    printf("Enter description: ");
    getchar();  // flush newline
    fgets(e.description, sizeof(e.description), stdin);
    strtok(e.description, "\n");  // remove trailing newline

    expenses[count++] = e;
    saveExpenses(expenses, count);

    printf("Expense added with ID: %d\n", e.id);
}

void viewExpenses() {
    Expense expenses[MAX_EXPENSES];
    int count = loadExpenses(expenses);

    printf("\n--- All Expenses ---\n");
    for (int i = 0; i < count; i++) {
        printf("ID: %d | %s | $%.2f | %s\n  %s\n",
            expenses[i].id, expenses[i].category,
            expenses[i].amount, expenses[i].date,
            expenses[i].description);
    }
}

void editExpense() {
    Expense expenses[MAX_EXPENSES];
    int count = loadExpenses(expenses);

    int id;
    printf("Enter ID to edit: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (expenses[i].id == id) {
            printf("Editing Expense ID %d\n", id);
            printf("Enter new category: ");
            scanf("%s", expenses[i].category);
            printf("Enter new amount: ");
            scanf("%f", &expenses[i].amount);
            printf("Enter new date (YYYY-MM-DD): ");
            scanf("%s", expenses[i].date);
            printf("Enter new description: ");
            getchar();
            fgets(expenses[i].description, sizeof(expenses[i].description), stdin);
            strtok(expenses[i].description, "\n");
            saveExpenses(expenses, count);
            printf("Updated successfully.\n");
            return;
        }
    }
    printf("Expense ID not found.\n");
}

void deleteExpense() {
    Expense expenses[MAX_EXPENSES];
    int count = loadExpenses(expenses);

    int id;
    printf("Enter ID to delete: ");
    scanf("%d", &id);

    int found = 0;
    for (int i = 0; i < count; i++) {
        if (expenses[i].id == id) {
            for (int j = i; j < count - 1; j++) {
                expenses[j] = expenses[j + 1];
            }
            count--;
            found = 1;
            break;
        }
    }

    if (found) {
        saveExpenses(expenses, count);
        printf("Expense deleted.\n");
    }
    else {
        printf("Expense ID not found.\n");
    }
}

void showSummary() {
    Expense expenses[MAX_EXPENSES];
    int count = loadExpenses(expenses);

    float total = 0, max = 0, min = 1e9;
    for (int i = 0; i < count; i++) {
        total += expenses[i].amount;
        if (expenses[i].amount > max) max = expenses[i].amount;
        if (expenses[i].amount < min) min = expenses[i].amount;
    }

    printf("Total spent: $%.2f\n", total);
    printf("Highest expense: $%.2f\n", max);
    printf("Lowest expense: $%.2f\n", min);
}
