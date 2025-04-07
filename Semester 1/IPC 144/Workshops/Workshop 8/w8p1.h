#ifndef CAT_PRODUCTS
#define CAT_PRODUCTS

#define MAX_PRODUCTS 3           // Maximum number of products to analyze
#define GRAMS_IN_SERVING 64 // Number of grams in a suggested serving


struct CatFoodInfo {
	unsigned int sku;         // Unique product SKU number
	double price;             // Product price
	int calories;            // Calories served per serving
	double weight;           //Product weight in pound(lbs)
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

// 7. Logic entry point
void start(void);

#endif // !CAT_PRODUCTS
