#include<stdio.h>

int main(void)
{
	int itemNumber, month, day, year;
	float unitPrice;

	printf("Enter item number: ");
	scanf("%d", &itemNumber);

	printf("Enter unit price: ");
	scanf("%f", &unitPrice);

	printf("Enter purchase date (mm/dd/yy) : ");
	scanf("%d/%d/%d", &month, &day, &year);

	printf("Item\t\tUnit\t\tPurchase\n\t\tPrice\t\tDate\n");
	printf("%d\t\t$%7.2f\t%.2d/%.2d/%d", itemNumber, unitPrice, month, day, year);

	return 0;
}