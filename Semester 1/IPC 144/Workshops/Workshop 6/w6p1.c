#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX_ITEMS 10         // Maximum number of wish list items
#define MIN_INCOME 500.00    // Minimum monthly income
#define MAX_INCOME 400000.00 // Maximum monthly income
#define MIN_COST 100.00      // Minimum cost for an item

// Arrays to store item details
double itemCost[MAX_ITEMS];
int itemPriority[MAX_ITEMS];
char itemFinanced[MAX_ITEMS];

// Function prototypes
void intro(void);
double getIncome(void);
int getWishlistCount(void);
void getItemDetails(int count);
void displayItems(int count);
int menu_choice(void);

int main(void) {
    intro();  // Display introduction

    // Get valid monthly net income
    double income = getIncome();

    // Get valid wish list count
    int wishlistCount = getWishlistCount();

    // Get details for each wish list item
    getItemDetails(wishlistCount);

    // Display the list of items and total cost
    displayItems(wishlistCount);

    // Ask how user want to forecast wish list
    menu_choice(void);

    // Exit message
    printf("Best of luck in all your future endeavours!\n");

    return 0;
}

// Display the intro message
void intro(void) {
    printf("+--------------------------+\n");
    printf("+ Wish List Forecaster      |\n");
    printf("+--------------------------+\n");
}

// Get valid income from the user
double getIncome(void) {
    double income;
    do {
        printf("Enter your monthly NET income: $");
        scanf("%lf", &income);
        if (income < MIN_INCOME) {
            printf("ERROR: You must have a consistent monthly income of at least $%.2lf\n", MIN_INCOME);
        }
        else if (income > MAX_INCOME) {
            printf("ERROR: Liar! I'll believe you if you enter a value no more than $%.2lf\n", MAX_INCOME);
        }
    } while (income < MIN_INCOME || income > MAX_INCOME); // Repeat until valid input is entered
    return income;
}

// Get valid wish list count from the user
int getWishlistCount(void) {
    int count;
    do {
        printf("How many wish list items do you want to forecast?: ");
        scanf("%d", &count);
        if (count < 1 || count > MAX_ITEMS) {
            printf("ERROR: List is restricted to between 1 and %d items.\n", MAX_ITEMS);
        }
    } while (count < 1 || count > MAX_ITEMS); // Repeat until valid input is entered
    return count;
}

// Get item details from the user
void getItemDetails(int count) {
    for (int i = 0; i < count; i++) {
        printf("Item-%d Details:\n", i + 1);

        // Get valid item cost
        do {
            printf(" Item cost: $");
            scanf("%lf", &itemCost[i]);
            if (itemCost[i] < MIN_COST) {
                printf("ERROR: Cost must be at least $%.2lf\n", MIN_COST);
            }
        } while (itemCost[i] < MIN_COST); // Repeat until valid input is entered

        // Get valid priority
        do {
            printf(" How important is it to you? [1=must have, 2=important, 3=want]: ");
            scanf("%d", &itemPriority[i]);
            if (itemPriority[i] < 1 || itemPriority[i] > 3) {
                printf("ERROR: Value must be between 1 and 3\n");
            }
        } while (itemPriority[i] < 1 || itemPriority[i] > 3); // Repeat until valid input is entered

        // Get valid financing option
        do {
            printf(" Does this item have financing options? [y/n]: ");
            scanf(" %c", &itemFinanced[i]); // Note the space before %c to skip the newline character
            if (itemFinanced[i] != 'y' && itemFinanced[i] != 'n') {
                printf("ERROR: Must be a lowercase 'y' or 'n'\n");
            }
        } while (itemFinanced[i] != 'y' && itemFinanced[i] != 'n'); // Repeat until valid input is entered
    }
}

// Display the items and their total cost
void displayItems(int count) {
    double totalCost = 0.0;

    // Table header
    printf("\nItem  Priority  Financed  Cost\n");
    printf("----  --------  --------  -----------\n");

    // Display each item
    for (int i = 0; i < count; i++) {
        printf("%4d  %8d  %8c  %11.2lf\n", i + 1, itemPriority[i], itemFinanced[i], itemCost[i]);
        totalCost += itemCost[i];
    }

    // Display total cost
    printf("----  --------  --------  -----------\n");
    printf("                   $%11.2lf\n\n", totalCost);
}

void menu_choice(void) {
    // Menu Loop
    int has_financing = 0;
    do {
        printf("\nHow do you want to forecast your wish list?\n");
        printf("1. All items (no filter)\n");
        printf("2. By priority\n");
        printf("0. Quit/Exit\n");
        printf("Selection: ");
        scanf("%d", &menu_choice);

        // Reset total cost and financing flag
        total_cost = 0.0;
        has_financing = 0;

        // Handle menu options
        if (menu_choice == 1) {
            // Option 1: All items
            for (i = 0; i < num_items; i++) {
                total_cost += item_cost[i];
                if (financing[i] == 'y') {
                    has_financing = 1;
                }
            }
            printf("====================================================\n");
            printf("Filter: All items\n");
            printf("Amount: $%1.2lf\n", total_cost);
        }
        else if (menu_choice == 2) {
            // Option 2: By priority
            do {
                printf("What priority do you want to filter by? [1-3]: ");
                scanf("%d", &selected_priority);
                if (selected_priority < 1 || selected_priority > 3) {
                    printf("ERROR: Value must be between 1 and 3\n");
                }
            } while (selected_priority < 1 || selected_priority > 3);

            for (i = 0; i < num_items; i++) {
                if (priority[i] == selected_priority) {
                    total_cost += item_cost[i];
                    if (financing[i] == 'y') {
                        has_financing = 1;
                    }
                }
            }
            printf("====================================================\n");
            printf("Filter: by priority (%d)\n", selected_priority);
            printf("Amount: $%1.2lf\n", total_cost);
        }
        else if (menu_choice != 0) {
            printf("ERROR: Invalid menu selection.\n");
        }

}


    // Calculate and display forecast if valid selection
    if (menu_choice == 1 || menu_choice == 2) {
        total_years = (int)(total_cost / net_income);
        total_months = (int)((total_cost - (total_years * net_income)) / (net_income / 12));

        printf("Forecast: %d years, %d months\n", total_years, total_months);
        if (has_financing) {
            printf("NOTE: Financing options are available on some items.\n");
            printf("      You can likely reduce the estimated months.\n");
        }
        printf("====================================================\n");
    }
} while (menu_choice != 0);