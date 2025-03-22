#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
    double net_income, item_cost[10], total_cost;
    char financing[10];
    int num_items, priority[10], menu_choice, selected_priority;
    int i, total_years, total_months;
    int has_financing = 0;

    printf("+-------------------+\n");
    printf(" Wish list Forecaster\n");
    printf("+-------------------+\n");

    // Get user monthly net income
    do {
        printf("Enter your monthly NET income: $");
        scanf("%lf", &net_income);
        if (net_income < 500.0) {
            printf("ERROR: You must have a consistent monthly income of at least $500.00\n");
        }
        else if (net_income > 400000.0) {
            printf("ERROR: Liar! I'll believe you if you enter a value no more than $400000.00\n");
        }
        printf("\n");
    } while (net_income < 500.0 || net_income > 400000.0);

    // Get the number of items
    do {
        printf("How many wish list items do you want to forecast?: ");
        scanf("%d", &num_items);
        if (num_items < 1 || num_items > 10) {
            printf("ERROR: List is restricted to between 1 and 10 items.\n");
        }
        printf("\n");
    } while (num_items < 1 || num_items > 10);

    // Get the details of each item
    for (i = 0; i < num_items; i++) {
        printf("Item-%d Details:\n", i + 1);

        // Get item cost
        do {
            printf("   Item cost: $");
            scanf("%lf", &item_cost[i]);
            if (item_cost[i] < 100.0) {
                printf("ERROR: Cost must be at least $100.00\n");
            }
        } while (item_cost[i] < 100.0);

        // Get priority level
        do {
            printf("   How important is it to you? [1=must have, 2=important, 3=want]: ");
            scanf("%d", &priority[i]);
            if (priority[i] < 1 || priority[i] > 3) {
                printf("ERROR: Value must be between 1 and 3\n");
            }
        } while (priority[i] < 1 || priority[i] > 3);

        // Get financing option
        do {
            printf("   Does this item have financing options? [y/n]: ");
            scanf(" %c", &financing[i]);
            if (financing[i] != 'y' && financing[i] != 'n') {
                printf("ERROR: Must be a lowercase 'y' or 'n'\n");
            }
        } while (financing[i] != 'y' && financing[i] != 'n');
    }

    // Menu Loop
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

    // Exit message
    printf("Best of luck in all your future endeavours!\n");

    return 0;
}
