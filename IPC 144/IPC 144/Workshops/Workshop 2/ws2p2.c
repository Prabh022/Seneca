#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

// double getdouble(void);

int main(void) {
	int toonie, loonie, quarter, dimes, nickel, pennies;;
	double amount, amountlft, loonlft, quarterlft, dimelft, nickelft, pennieslft, servicefee, balancelft;
	printf("Change Maker Machine\n");
	printf("====================\n");

	printf("Enter dollars and cents amount to convert to coins: $");
	scanf("%lf", &amount);
	servicefee = amount * 0.05;
	balancelft = amount - servicefee;
	printf("Service fee (5.0 percent): %.2lf\n", servicefee);
	printf("Balance to dispense: $%.2lf\n", balancelft);
	toonie = (int)balancelft / 2;
	amountlft = balancelft - (toonie * 2);
	loonie = (int)amountlft / 1;
	loonlft = amountlft - (loonie * 1);
	quarter = (int)(loonlft / 0.25);
	quarterlft = loonlft - (quarter * 0.25);
	dimes = (int)(quarterlft / 0.10);
	dimelft = quarterlft - (dimes * 0.10);
	nickel = (int)(dimelft / 0.05);
	nickelft = dimelft - (nickel * 0.05);
	pennies = (int)(nickelft / 0.01);
	pennieslft = nickelft - (pennies * 0.01);

	printf("\n$2.00 Toonies  X %d (remaining: $%.2lf)\n", toonie, amountlft);
	printf("$1.00 Loonies  X %d (remaining: $%.2lf)\n", loonie, loonlft);
	printf("$0.25 Quarters X %d (remaining: $%.2lf)\n", quarter, quarterlft);
	printf("$0.10 Dimes    X %d (remaining: $%.2lf)\n", dimes, dimelft);
	printf("$0.05 Nickels  X %d (remaining: $%.2lf)\n", nickel, nickelft);
	printf("$0.01 Pennies  X %d (remaining: $%.2lf)\n", pennies, pennieslft);
	printf("\n");
	printf("All coins Dispensed\n");

	return 0;
}