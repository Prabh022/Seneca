// storage.c

#include <stdio.h>
#include <stdlib.h>
#include "storage.h"

int loadExpenses(Expense expenses[]) {
    FILE* fp = fopen(DATA_FILE, "rb");
    if (!fp) return 0;

    int count = 0;
    while (fread(&expenses[count], sizeof(Expense), 1, fp)) {
        count++;
    }
    fclose(fp);
    return count;
}

void saveExpenses(Expense expenses[], int count) {
    FILE* fp = fopen(DATA_FILE, "wb");
    for (int i = 0; i < count; i++) {
        fwrite(&expenses[i], sizeof(Expense), 1, fp);
    }
    fclose(fp);
}

int generateUniqueId() {
    static int id = 1000;
    return id++;
}
