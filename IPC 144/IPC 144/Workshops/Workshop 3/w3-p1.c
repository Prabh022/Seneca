/*

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main(void) {
	const int product1 = 111;
	const int product2 = 222;
	const int product3 = 111;

	const double product1_price = 111.49;
	const double product2_price = 222.99;
	const double product3_price = 334.49;

	const char product1_tax = 'Y';
	const char product2_tax = 'N';
	const char product3_tax = 'N';

	const double average_price = (product1_price + product2_price + product3_price) / 3.0;

	const double test_value = 330.99;

	printf("Product Information\n");
	printf("===================\n");

	printf("Product-1 (ID: %d)\n", product1);
	printf("  Taxed: %c\n", product1_tax);
	printf("  Price: $%.4f\n\n", product1_price);

	printf("Product2 (ID: %d)\n", product2);
	printf("  Taxed: %c\n", product2_tax);
	printf("  Price: $%.4f\n\n", product2_price);

	printf("Product-3 (ID: %d)\n", product3);
	printf("  Taxed: %c\n", product3_tax);
	printf("  Price: $%.4f\n\n", product3_price);

	printf("The average of all prices is : $ % .4f\n", average_price);

	printf("About Relational and Logical Expressions!\n");
	printf("=========================================\n");
	printf("1. These expressions evaluate to TRUE or FALSE\n");
	printf("FALSE: is always represented by integer value 0\n");
	prinf("TRUE: is represented by any integer value other than 0\n\n");

	printf("Some Data Analysis...\n");
	prinf("======================\n");
	printf("1. Is product 1 taxable? -> %d\n\n", product1_tax == 'Y');

	printf("2. Are products 2 and 3 both NOT taxable (N)? -> %d\n\n", (product2_tax == 'N' && product3_tax == 'N'));

	printf("3. Is product 3 less than testValue $%f? -> %d\n\n", test_value, product3_price < test_value);

	printf("4. Is the price of product 3 more than both product 1 and 2 combined? ->%d\n\n", product3_price < (product1_price + product2_price));

	double price_diff = product3_price - product2_price;
	printf("5. Is the price of product 1 equal to or more than the price difference of product 3 LESS product 2? -> %d (price difference: $%.2f)\n", product1_price >= price_diff, price_diff);




	return 0;	
}

*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main(void) {
    // Constants for the products
    const int product1_id = 111;
    const int product2_id = 222;
    const int product3_id = 111;

    const double product1_price = 111.49;
    const double product2_price = 222.99;
    const double product3_price = 334.49;

    const char product1_taxed = 'Y';
    const char product2_taxed = 'N';
    const char product3_taxed = 'N';

    // Variable for average price
    const double average_price = (product1_price + product2_price + product3_price) / 3.0;

    // Variable for the test value (used in test case #3)
    const double test_value = 330.99;

    // Display product information
    printf("Product Information\n");
    printf("===================\n");
    printf("Product-1 (ID:%d)\n", product1_id);
    printf(" Taxed: %c\n", product1_taxed);
    printf(" Price: $%.4f\n", product1_price);

    printf("Product-2 (ID:%d)\n", product2_id);
    printf(" Taxed: %c\n", product2_taxed);
    printf(" Price: $%.4f\n", product2_price);

    printf("Product-3 (ID:%d)\n", product3_id);
    printf(" Taxed: %c\n", product3_taxed);
    printf(" Price: $%.4f\n", product3_price);

    // Display average price
    printf("The average of all prices is: $%.4f\n", average_price);

    // Relational and Logical Expressions
    printf("\nAbout Relational and Logical Expressions!\n");
    printf("========================================\n");
    printf("1. These expressions evaluate to TRUE or FALSE\n");
    printf("2. FALSE: is always represented by integer value 0\n");
    printf("3. TRUE : is represented by any integer value other than 0\n");

    // Some data analysis
    printf("\nSome Data Analysis...\n");
    printf("=====================\n");

    // 1. Is product 1 taxable?
    printf("1. Is product 1 taxable? -> %d\n", product1_taxed == 'Y');

    // 2. Are products 2 and 3 both NOT taxable (N)?
    printf("2. Are products 2 and 3 both NOT taxable (N)? -> %d\n", (product2_taxed == 'N' && product3_taxed == 'N'));

    // 3. Is product 3 less than testValue ($330.99)?
    printf("3. Is product 3 less than testValue ($330.99)? -> %d\n",test_value, product3_price < test_value);

    // 4. Is the price of product 3 more than both product 1 and 2 combined?
    printf("4. Is the price of product 3 more than both product 1 and 2 combined? -> %d\n", product3_price > (product1_price + product2_price));

    // 5. Is the price of product 1 equal to or more than the price difference of product 3 LESS product 2?
    double price_diff = product3_price - product2_price;
    printf("5. Is the price of product 1 equal to or more than the price difference of product 3 LESS product 2? -> %d (price difference: $%.2f)\n", product1_price >= price_diff, price_diff);

    // 6. Is the price of product 2 equal to or more than the average price?
    printf("6. Is the price of product 2 equal to or more than the average price? -> %d\n", product2_price >= average_price);

    // 7. Based on product ID, product 1 is unique
    printf("7. Based on product ID, product 1 is unique -> %d\n", !(product1_id == product3_id));

    // 8. Based on product ID, product 2 is unique
    printf("8. Based on product ID, product 2 is unique -> %d\n", (product2_id != product1_id && product2_id != product3_id));

    // 9. Based on product ID, product 3 is unique
    printf("9. Based on product ID, product 3 is unique -> %d\n", !(product3_id == product1_id));

    return 0;
}
