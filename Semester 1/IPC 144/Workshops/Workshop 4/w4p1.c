#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    int apples, oranges, pears, tomatoes;
    printf("Grocery Shopping\n");
    printf("================\n");
    printf("How many APPLES do you need? : ");
    scanf("%d", &apples);
    if apples <= 0 {
        printf("ERROR: Value must be 0 or more.");
    }
    return 0;
}
