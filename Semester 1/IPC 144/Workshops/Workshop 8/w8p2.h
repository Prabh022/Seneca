#ifndef CAT_PRODUCTS
#define CAT_PRODUCTS

#define MAX_PRODUCTS 3           // Maximum number of products to analyze
#define GRAMS_IN_SERVING 64 // Number of grams in a suggested serving
#define KG_TO_LBS 2.20462 // conversion factor used for part 2
#define LBS_TO_KG 0.453592 //conversion factor

struct CatFoodInfo {
	unsigned int sku;         // Unique product SKU number
	double price;             // Product price
	int calories;            // Calories served per serving
	double weight;           //Product weight in pound(lbs)
};

struct reportData {
    struct CatFoodInfo productInfo; // Include full CatFoodInfo inside
    double weightKg;            // Product weight in kilograms
    int weightGrams;            // Product weight in grams
    double totalServings;       // Total number of servings per product
    double costPerServing;      // Cost per serving
    double costPerCalorie;      // Cost per calorie per serving
};


// ----------------------------------------------------------------------------
// function prototypes

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int* value);

// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double* value);

// 3. Opening Message (include the number of products that need entering)
void openingMessage(const int numProducts);

// 4. Get user input for the details of cat food product
struct CatFoodInfo getCatFoodInfo(const int productNum);

// 5. Display the formatted table header
void displayCatFoodHeader(void);

// 6. Display a formatted record of cat food data
void displayCatFoodData(int sku, double* price, int calories, double* weight);

// Part 2 Functions

// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg
double convertLbsKg(const double* pounds, double* kilograms);

// 9. convert lbs: g
int convertLbsG(const double* pounds, int* grams);

// 10. convert lbs: kg / g
void convertLbs(const double* pounds, double* kilograms, int* grams);

// 11. calculate: servings based on gPerServ
double calculateServings(const int servingSize, const int totalGrams, double* servings);

// 12. calculate: cost per serving
double CalcuateCostPerServing(const double* productPrice, const double totalServings);

// 13. calculate: cost per calorie
double calculateCostPerCal(const double* productPrice, const double totalCalories);

// 14. Derive a reporting detail record based on the cat food product data
struct ReportData calculateReportData(const struct CatFoodInfo product);


// 15. Display the formatted table header for the analysis results
void displayReportHeader(void);

// 16. Display the formatted data row in the analysis table
void displayReportData(const struct ReportData report, const int isCheapest);

// 17. Display the findings (cheapest)
void displayFinalAnalysis(const struct CatFoodInfo cheapestProduct);

// ----------------------------------------------------------------------------


// 7. Logic entry point
void start(void);

#endif // !CAT_PRODUCTS
