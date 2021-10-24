#include<stdio.h>

int main(void)
{
    char sign;
	int num1, denom1, num2, denom2, result_num, result_denom;

	printf("Enter two fractions separated by an operator: ");
	scanf("%d/%d", &num1, &denom1);
    scanf(" %c", &sign);
    scanf("%d/%d", &num2, &denom2);

    switch (sign)
    {
        case '+':
            result_num = num1 * denom2 + num2 * denom1;
	        result_denom = denom1 * denom2;
            break;

        case '-':
            result_num = num1 * denom2 - num2 * denom1;
            result_denom = denom1 * denom2;
            break;

        case '*':
            result_num = num1 * denom2 / (num2 * denom1);
            result_denom = denom1 * denom2;
            break;

        case '/':
            result_num = num1 * denom2 * num2 * denom1;
            result_denom = denom1 * denom2;
            break;
    }

	printf("The result is %d/%d\n", result_num, result_denom);

	return 0;
}
