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

// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg (divide by 2.20462)
double convertLbsKg(const double* lbs, double* kg) {
    // Conversion factor: 1 pound = 0.453592 kilograms
    double convertedKg = *lbs * LBS_TO_KG;

    // If the kg pointer is not NULL, assign the converted value to it
    if (kg != NULL) {
        *kg = convertedKg;
    }

    // Return the converted value
    return convertedKg;
}

// 9. convert lbs: g (call convertKG, then * 1000)
int convertLbsG(const double* pounds, int* grams) {
    // Check for valid pointer
    if (pounds == NULL || grams == NULL) {
        return -1;  // Error: invalid pointers
    }

    // Conversion: pounds to grams
    *grams = (int)(*pounds * 453.592); // 1 lb = 453.592 grams

    return 0; // Success
}

}

// Function to convert lbs to kg and grams
void convertLbs(const double* pounds, double* kilograms, int* grams) {
    // Convert pounds to kilograms
    if (kilograms != NULL) {
        *kilograms = *pounds / LBS_TO_KG;
    }

    // Convert pounds to grams
    if (grams != NULL) {
        *grams = (int)(*pounds * 1000 / LBS_TO_KG);
    }
}

// Calculate servings
double calculateServings(const int servingSize, const int totalGrams, double* servings) {
    double result = (double)totalGrams / servingSize;

    // Assign to the pointer if it's not NULL
    if (servings != NULL) {
        *servings = result;
    }

    return result;
}

// Calculate cost per serving
double CalcuateCostPerServing(const double* productPrice, const double totalServings) {
    return *productPrice / totalServings;
}

// Calculate cost per calorie
double calculateCostPerCal(const double* productPrice, const double totalCalories) {
    return *productPrice / totalCalories;
}

// Derive a reporting detail record based on the cat food product data
struct ReportData calculateReportData(const struct CatFoodInfo product) {
    struct ReportData reportData;

    // Assigning values directly
    reportData.sku = product.sku;
    reportData.price = product.price;
    reportData.caloriesPerServing = product.caloriesPerServing;
    reportData.weightLbs = product.weightLbs;

    // Calculate and assign other values
    double servings = calculateServings(product.servingSizeGrams, product.totalGrams, NULL);
    reportData.servings = servings;

    double costPerServing = CalcuateCostPerServing(&product.price, servings);
    reportData.costPerServing = costPerServing;

    double costPerCal = calculateCostPerCal(&product.price, product.caloriesPerServing);
    reportData.costPerCal = costPerCal;

    // Convert pounds to kg and grams for reporting
    convertLbs(&product.weightLbs, &reportData.weightKg, NULL);

    return reportData;
}

// Display the formatted table header for the analysis results
void displayReportHeader(void) {
    printf("Analysis Report (Note: Serving = %dg)\n", GRAMS_IN_SERVING);
    printf("---------------\n");
    printf("SKU $Price Bag-lbs Bag-kg Bag-g Cal/Serv Servings $/Serv $/Cal\n");
    printf("------- ---------- ---------- ---------- --------- -------- -------- ------- -------\n");
}

// Display the formatted data row in the analysis table
void displayReportData(const struct ReportData report, const int isCheapest) {
    printf("%07d %10.2lf %10.1lf %10.4lf %9d %8d %8.1lf %7.2lf %7.5lf",
        report.sku, report.price, report.weightLbs, report.weightKg,
        report.caloriesPerServing, report.servings, report.costPerServing,
        report.costPerCal);

    if (isCheapest) {
        printf(" ***");
    }

    printf("\n");
}

// Display the findings (cheapest)
void displayFinalAnalysis(const struct CatFoodInfo cheapestProduct) {
    printf("The cheapest product is:\n");
    printf("SKU: %d\n", cheapestProduct.sku);
    printf("Price: $%.2lf\n", cheapestProduct.price);
    printf("Weight: %.2lf lbs (%.2lf kg)\n", cheapestProduct.weightLbs, cheapestProduct.weightLbs / LBS_TO_KG);
    printf("Calories per Serving: %d\n", cheapestProduct.caloriesPerServing);
}

// ----------------------------------------------------------------------------


// 7. Logic entry point
void start(void) {
    // Create an array to hold the CatFoodInfo structures
    struct CatFoodInfo products[MAX_PRODUCTS];

    // Create an array to hold the ReportData structures
    struct ReportData reportData[MAX_PRODUCTS];

    // Variables to track the cheapest product based on cost per serving
    double cheapestCost = INT_MAX;  // Initialize with a large value
    int cheapestIndex = -1;  // Index of the cheapest product

    // Get data for CatFoodInfo products from user
    for (int i = 0; i < MAX_PRODUCTS; i++) {
        products[i] = getCatFoodInfo(i);  // Get product info based on the index

        // Call calculateReportData to fill the reportData array
        reportData[i] = calculateReportData(products[i]);

        // Determine the cheapest product based on cost per serving
        if (reportData[i].costPerServing < cheapestCost) {
            cheapestCost = reportData[i].costPerServing;
            cheapestIndex = i;
        }
    }

    // Display the CatFoodInfo header
    displayCatFoodHeader();

    // Display the CatFoodInfo product data
    for (int i = 0; i < MAX_PRODUCTS; i++) {
        displayCatFoodData(products[i].sku, &products[i].price, products[i].calories, &products[i].weight);
    }

    // Display the ReportData header
    displayReportHeader();

    // Display the analysis results (i.e., the ReportData array)
    for (int i = 0; i < MAX_PRODUCTS; i++) {
        int isCheapest = (i == cheapestIndex) ? 1 : 0;  // Flag the cheapest product
        displayReportData(reportData[i], isCheapest);  // Display the formatted row
    }

    // Display the final analysis for the cheapest product
    displayFinalAnalysis(products[cheapestIndex]);  // Pass the cheapest product to display the final analysis
}
