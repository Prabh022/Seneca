#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include "w8p1.h"

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int* value)
{
    int input;

    do {
        scanf("%d", &input);

        if (input <= 0) {
            printf("ERROR: Enter a positive value: ");
        }

    } while (input <= 0);

    // Assign to pointer if it's not NULL
    if (value != NULL) {
        *value = input;
    }

    return input;
}


// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double* value)
{
    double input;

    do {
        scanf("%lf", &input);

        if (input <= 0.0) {
            printf("ERROR: Enter a positive value: ");
        }

    } while (input <= 0.0);

    // Assign to pointer if it's not NULL
    if (value != NULL) {
        *value = input;
    }

    return input;
}

// 3. Opening Message (include the number of products that need entering)
void openingMessage(const int numProducts)
{
    printf("Cat Food Cost Analysis\n");
    printf("======================\n");
    printf("Enter the details for %d dry food bags for analysis\n", numProducts);
    printf("NOTE: A 'serving' is %dg", GRAMS_IN_SERVING);
}

// 4. Get user input for the details of cat food product
struct CatFoodInfo getCatFoodInfo(const int productNum) {
    struct CatFoodInfo info;  // Create a struct to hold product info

    printf("\nCat Food Product #%d\n", productNum + 1); // productNum is 0-based index
    printf("--------------------\n");

    printf("SKU           : ");
    getIntPositive(&info.sku);  // get value via argument

    printf("PRICE         : $");
    info.price = getDoublePositive(NULL);  // get value via return (passing NULL)

    printf("WEIGHT (LBS)  : ");
    info.weight = getDoublePositive(NULL);  // get value via return (passing NULL)

    printf("CALORIES/SERV.: ");
    info.calories = getIntPositive(NULL);  // get value via return (passing NULL)

    return info;
}

// 5. Display the formatted table header
void displayCatFoodHeader(void)
{
	printf("SKU         $Price    Bag-lbs Cal/Serv\n");
	printf("------- ---------- ---------- --------\n");
}

// 6. Display a formatted record of cat food data
void displayCatFoodData(int sku, double* price, int calories, double* weight)
{
    // Display the cat food data in the specified format
    printf("%07d %10.2lf %10.1lf %8d\n", sku, *price, *weight, calories);
}

// 7. Logic entry point
void start(void) {
    // Create an array to hold the CatFoodInfo structures
    struct CatFoodInfo products[MAX_PRODUCTS];

    // Example: Assuming you are filling the array with data and then displaying it
    for (int i = 0; i < MAX_PRODUCTS; i++) {
        products[i] = getCatFoodInfo(i);  // Pass zero-based index
    }

    // Display header
    displayCatFoodHeader();

    // Display product data (fix the calls to displayCatFoodData)
    for (int i = 0; i < MAX_PRODUCTS; i++) {
        displayCatFoodData(products[i].sku, &products[i].price, products[i].calories, &products[i].weight);
    }
}

