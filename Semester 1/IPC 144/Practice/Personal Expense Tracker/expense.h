// expense.h

#ifndef EXPENSE_H
#define EXPENSE_H

typedef struct {
    int id;
    char category[20];
    float amount;
    char date[11];         // YYYY-MM-DD
    char description[100];
} Expense;

void addExpense();
void viewExpenses();
void editExpense();
void deleteExpense();
void showSummary();

#endif
