#include<stdio.h>

int main(void)
{
    float num_temp;
    float result = 0;
    char operator;

    printf("Enter an expression: ");
    scanf("%f", &num_temp);
    result += num_temp;

    while (1)
    {
        while ((operator = getchar()) == ' ');
        if (operator == '\n') break;

        scanf("%f", &num_temp);

        switch (operator)
        {
            case '+':
                result += num_temp;
                break;
            case '-':
                result -= num_temp;
                break;
            case '*':
                result *= num_temp;
                break;
            case '/':
                result /= num_temp;
                break;
        }
    }

    printf("Value of expression: %.2f\n", result);

    return 0;
}
