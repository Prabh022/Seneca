#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MIN_YEAR 2012
#define MAX_YEAR 2022
#define LOG_DAYS 3

int main(void) {
    const int JAN = 1, DEC = 12;
    int year, month, valid = 0, day;
    char* monthName = NULL;
    double morningRating, eveningRating;
    double morningTotal = 0.0, eveningTotal = 0.0, overallTotal = 0.0;
    double avgMorning, avgEvening, avgOverall;

    printf("General Well-being Log\n");
    printf("======================\n");

    // Input validation for year and month
    while (!valid) {
        printf("Set the year and month for the well-being log (YYYY MM): ");
        scanf("%d %d", &year, &month);

        if (year < MIN_YEAR || year > MAX_YEAR) {
            printf("ERROR: The year must be between %d and %d inclusive\n", MIN_YEAR, MAX_YEAR);
        }
        if (month < JAN || month > DEC) {
            printf("ERROR: Jan.(%d) - Dec.(%d)\n", JAN, DEC);
        }

        if ((year >= MIN_YEAR && year <= MAX_YEAR) && (month >= JAN && month <= DEC)) {
            valid = 1;
        }
    }

    printf("*** Log date set! ***\n");

    // Get the month name based on the month number
    switch (month) {
    case 1: monthName = "JAN"; break;
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
    default: monthName = "???"; break;
    }

    // Collect morning and evening ratings for LOG_DAYS days
    for (day = 1; day <= LOG_DAYS; day++) {
        printf("%d-%s-%02d\n", year, monthName, day);

        // Morning rating input and validation
        do {
            printf(" Morning rating (0.0-5.0): ");
            scanf("%lf", &morningRating);
            if (morningRating < 0.0 || morningRating > 5.0) {
                printf(" ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
            }
        } while (morningRating < 0.0 || morningRating > 5.0);

        // Evening rating input and validation
        do {
            printf(" Evening rating (0.0-5.0): ");
            scanf("%lf", &eveningRating);
            if (eveningRating < 0.0 || eveningRating > 5.0) {
                printf(" ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
            }
        } while (eveningRating < 0.0 || eveningRating > 5.0);

        // Accumulate the ratings for the day
        morningTotal += morningRating;
        eveningTotal += eveningRating;
    }

    // Calculate totals and averages
    overallTotal = morningTotal + eveningTotal;
    avgMorning = morningTotal / LOG_DAYS;
    avgEvening = eveningTotal / LOG_DAYS;
    avgOverall = overallTotal / (LOG_DAYS * 2);  // Two ratings per day

    // Display the summary
    printf("Summary\n");
    printf("=======\n");
    printf("Morning total rating: %.3lf\n", morningTotal);
    printf("Evening total rating: %.3lf\n", eveningTotal);
    printf("----------------------------\n");
    printf("Overall total rating: %.3lf\n", overallTotal);
    printf("Average morning rating: %.1lf\n", avgMorning);
    printf("Average evening rating: %.1lf\n", avgEvening);
    printf("----------------------------\n");
    printf("Average overall rating: %.1lf\n", avgOverall);

    return 0;
}
