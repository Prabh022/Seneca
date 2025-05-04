// storage.h

#ifndef STORAGE_H
#define STORAGE_H

#include "expense.h"

#define MAX_EXPENSES 1000
#define DATA_FILE "expenses.dat"

int loadExpenses(Expense expenses[]);
void saveExpenses(Expense expenses[], int count);
int generateUniqueId();

#endif
