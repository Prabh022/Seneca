#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define MIN_YEAR 2010
#define MAX_YEAR 2021

int main(void) {
    const int JAN = 1;
    const int DEC = 12;
    int month, year;

    printf("General Well-being Log\n");
    printf("=====================\n");

    // Input validation loop
    do {
        printf("Set the year and month for the well-being log (YYYY MM): ");
        scanf("%d %d", &year, &month);

        // Check for valid year and month input
        if (year < MIN_YEAR || year > MAX_YEAR) {
            printf("ERROR: The year must be between 2010 and 2021 inclusive\n");
        }
        if (month < JAN || month > DEC) {
            printf("ERROR: Jan. (1) - Dec. (12)\n");
        }

    } while ((year < MIN_YEAR || year > MAX_YEAR) || (month < JAN || month > DEC));

    printf("\n*** Log date set! ***\n");
    // Map the month number to its 3-character representation
    char* monthName;
    switch (month) {
    case 1:
        monthName = "JAN";
        break;
    case 2: monthName = "FEB"; break;
    case 3: monthName = "MAR"; break;
    case 4: monthName = "APR"; break;
    case 5: monthName = "MAY"; break;
    case 6: monthName = "JUN"; break;
    case 7: monthName = "JUL"; break;
    case 8: monthName = "AUG"; break;
    case 9: monthName = "SEP"; break;
    case 10: monthName = "OCT"; break;
    case 11: monthName = "NOV"; break;
    case 12: monthName = "DEC"; break;
    default: monthName = NULL;
    }

    printf("\nLog starting date: %d-%s-01\n", year, monthName);

    return 0;
}

