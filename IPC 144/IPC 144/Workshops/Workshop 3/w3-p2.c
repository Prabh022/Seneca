    /*/////////////////////////////////////////////////////////////////////////
                              Workshop - #3 (P2)
    Full Name  :
    Student ID#:
    Email      :
    Section    :

    Authenticity Declaration:
    I declare this submission is the result of my own work and has not been
    shared with any other student or 3rd party content provider. This submitted
    piece of work is entirely of my own creation.
    ////////////////////////////////////////////////////////////////////////

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
    // You will need this when converting from grams to pounds (lbs)
    //const double GRAMS_IN_LBS = 453.5924;
    char cofeetype1, cofeetype2, cofeetype3;
    int bagweight1, bagweight2, bagweight3;
    char bestServedWithCream1, bestServedWithCream2, bestServedwithCream3;

    printf("Take a Break - Cofee Shop\n");
    printf("=========================\n");

    printf("\n\n");
    printf("Enter the cofee product information being sold today\n\n");
    printf("COFFEE - 1...\n");
    printf("Type ([L]ight, [M]edium, [R]ich): %c\n", cofeetype1);
    printf("Bag weight (g): %d\n", bagweight1);
    printf("Best Served with cream ([Y]es, [N]o): %c\n\n", bestServedWithCream1);

    printf("COFFEE - 2...\n");
    printf("Type ([L]ight, [M]edium, [R]ich): %c\n", cofeetype2);
    printf("Bag weight (g): %d\n", bagweight2);
    printf("Best Served with cream ([Y]es, [N]o): %c\n\n", bestServedWithCream2);

    printf("COFFEE - 3...\n");
    printf("Type ([L]ight, [M]edium, [R]ich): %c\n", cofeetype3);
    printf("Bag weight (g): %d\n", bagweight3);
    printf("Best Served with cream ([Y]es, [N]o): %c\n\n", bestServedwithCream3);



    return 0;
}


  

    Provided formatting parts for printf statements:

    As described in step-7
    ======================
    printf(" 1 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n",

    As described in step-10
    =======================
    printf(" 1|       %d         |      %d      |   %d   |\n",

    |*/

#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

int main() {
    const double GRAMS_IN_LBS = 453.5924;
    // Step 1: Variable declarations
    char coffeeType1, coffeeType2, coffeeType3;
    int bagWeight1, bagWeight2, bagWeight3;
    char bestServedWithCream1, bestServedWithCream2, bestServedWithCream3;
    char prefCoffeeStrength;
    char prefCream;
    int prefServings;

    // Step 2: Product data input
    printf("Enter the coffee product information being sold today...\n");

    printf("COFFEE-1...\n");
    printf("Type ([L]ight,[M]edium,[R]ich): ");
    scanf(" %c", &coffeeType1);
    printf("Bag weight (g): ");
    scanf("%d", &bagWeight1);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &bestServedWithCream1);

    printf("COFFEE-2...\n");
    printf("Type ([L]ight,[M]edium,[R]ich): ");
    scanf(" %c", &coffeeType2);
    printf("Bag weight (g): ");
    scanf("%d", &bagWeight2);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &bestServedWithCream2);

    printf("COFFEE-3...\n");
    printf("Type ([L]ight,[M]edium,[R]ich): ");
    scanf(" %c", &coffeeType3);
    printf("Bag weight (g): ");
    scanf("%d", &bagWeight3);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &bestServedWithCream3);

    // Step 3: Display product data in a tabular format
    printf("---+------------------------+---------------+-------+\n");
    printf(" | Coffee | Packaged | Best |\n");
    printf(" | Type | Bag Weight | Served|\n");
    printf(" +------------------------+---------------+ With |\n");
    printf("ID | Light | Medium | Rich | (G) | Lbs | Cream |\n");
    printf("---+------------------------+---------------+-------|\n");
    printf(" 1 | %d | %d | %d | %4d | %6.3lf | %d |\n",
        (coffeeType1 == 'l' || coffeeType1 == 'L'), (coffeeType1 == 'm' || coffeeType1 == 'M'), (coffeeType1 == 'r' || coffeeType1 == 'R'),
        bagWeight1, bagWeight1 * GRAMS_IN_LBS, (bestServedWithCream1 == 'y' || bestServedWithCream1 == 'Y'));
    printf(" 2 | %d | %d | %d | %4d | %6.3lf | %d |\n",
        (coffeeType2 == 'l' || coffeeType2 == 'L'), (coffeeType2 == 'm' || coffeeType2 == 'M'), (coffeeType2 == 'r' || coffeeType2 == 'R'),
        bagWeight2, bagWeight2 * GRAMS_IN_LBS, (bestServedWithCream2 == 'y' || bestServedWithCream2 == 'Y'));
    printf(" 3 | %d | %d | %d | %4d | %6.3lf | %d |\n",
        (coffeeType3 == 'l' || coffeeType3 == 'L'), (coffeeType3 == 'm' || coffeeType3 == 'M'), (coffeeType3 == 'r' || coffeeType3 == 'R'),
        bagWeight3, bagWeight3 * GRAMS_IN_LBS, (bestServedWithCream3 == 'y' || bestServedWithCream3 == 'Y'));

    // Step 4: Customer preferences input (1st scenario)
    printf("Enter how you like your coffee...\n");
    printf("Coffee strength ([L]ight, [M]edium, [R]ich): ");
    scanf(" %c", &prefCoffeeStrength);
    printf("Do you like your coffee with cream ([Y]es,[N]o): ");
    scanf(" %c", &prefCream);
    printf("Typical number of daily servings: ");
    scanf("%d", &prefServings);

    // Step 5: Display preference match results
    printf("The below table shows how your preferences align to the available products:\n");
    printf("--------------------+-------------+-------+\n");
    printf(" | Coffee | Packaged | With |\n");
    printf("ID| Type | Bag Weight | Cream |\n");
    printf("--+-----------------+-------------+-------+\n");
    printf(" 1| %d | %d | %d |\n",
        (prefCoffeeStrength == coffeeType1 || prefCoffeeStrength == coffeeType1),
        (prefServings >= 1 && prefServings <= 4 && bagWeight1 == 250),
        (prefCream == bestServedWithCream1));

    // Step 6: Repeat for 2nd preference scenario

    return 0;
}

