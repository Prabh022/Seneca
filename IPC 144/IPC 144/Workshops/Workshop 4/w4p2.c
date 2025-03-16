#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX_PRODUCTS 5

// Function to pick the products
void pickProducts(int* items, const char* product, int quantity);

int main(void) {
    int apples, oranges, pears, tomatoes, cabbages;
    int continueShopping = 1;

    // Main shopping loop
    while (continueShopping) {
        printf("Grocery Shopping\n");
        printf("================\n");

        // Input how many of each item is needed
        do {
            printf("How many APPLES do you need? : ");
            scanf("%d", &apples);
            if (apples < 0) {
                printf("ERROR: Value must be 0 or more.\n\n");
            }
        } while (apples < 0);

        do {
            printf("How many ORANGES do you need? : ");
            scanf("%d", &oranges);
            if (oranges < 0) {
                printf("ERROR: Value must be 0 or more.\n\n");
            }
        } while (oranges < 0);

        do {
            printf("How many PEARS do you need? : ");
            scanf("%d", &pears);
            if (pears < 0) {
                printf("ERROR: Value must be 0 or more.\n\n");
            }
        } while (pears < 0);

        do {
            printf("How many TOMATOES do you need? : ");
            scanf("%d", &tomatoes);
            if (tomatoes < 0) {
                printf("ERROR: Value must be 0 or more.\n\n");
            }
        } while (tomatoes < 0);

        do {
            printf("How many CABBAGES do you need? : ");
            scanf("%d", &cabbages);
            if (cabbages < 0) {
                printf("ERROR: Value must be 0 or more.\n\n");
            }
        } while (cabbages < 0);

        printf("--------------------------\n");
        printf("Time to pick the products!\n");
        printf("--------------------------\n");

        // Picking apples
        if (apples > 0) {
            pickProducts(&apples, "APPLE", apples);
        }

        // Picking oranges
        if (oranges > 0) {
            pickProducts(&oranges, "ORANGE", oranges);
        }

        // Picking pears
        if (pears > 0) {
            pickProducts(&pears, "PEAR", pears);
        }

        // Picking tomatoes
        if (tomatoes > 0) {
            pickProducts(&tomatoes, "TOMATO", tomatoes);
        }

        // Picking cabbages
        if (cabbages > 0) {
            pickProducts(&cabbages, "CABBAGE", cabbages);
        }

        printf("All the items are picked!\n");

        // Ask if the user wants to shop again
        printf("Do another shopping? (0=NO): ");
        scanf("%d", &continueShopping);
    }

    printf("Your tasks are done for today - enjoy your free time!\n");

    return 0;
}
void pickProducts(int* items, const char* product, int quantity) {
    int picked, remaining = quantity;

    while (remaining > 0) {
        printf("Pick some %s... how many did you pick? : ", product);
        scanf("%d", &picked);

        if (picked > remaining) {
            printf("You picked too many... only %d more %s(S) are needed.\n", remaining, product);
        }
        else if (picked <= 0) {
            printf("ERROR: You must pick at least 1!\n");
        }
        else {
            remaining -= picked;
            if (remaining > 0) {
                printf("Looks like we still need some %s...\n", product);
            }
            else {
                printf("Great, that's the %s done!\n", product);
            }
        }
    }
}
