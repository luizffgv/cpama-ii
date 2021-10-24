#include<stdio.h>

int main(void)
{
    int number_units, number_tens;

    printf("Enter a two-digit number: ");
    scanf("%1d %1d", &number_tens, &number_units);

    printf("You entered the number ");

    if (number_tens != 1)
    {
        switch (number_tens)
        {
            case 2: printf("twenty");
                    break;
            case 3: printf("thirty");
                    break;
            case 4: printf("forty");
                    break;
            case 5: printf("fifty");
                    break;
            case 6: printf("sixty");
                    break;
            case 7: printf("seventy");
                    break;
            case 8: printf("eighty");
                    break;
            case 9: printf("ninety");
                    break;
        }

        switch (number_units)
        {
            case 1: printf("-one");
                    break;
            case 2: printf("-two");
                    break;
            case 3: printf("-three");
                    break;
            case 4: printf("-four");
                    break;
            case 5: printf("-five");
                    break;
            case 6: printf("-six");
                    break;
            case 7: printf("-seven");
                    break;
            case 8: printf("-eight");
                    break;
            case 9: printf("-nine");
                    break;
        }
    }
    else
    {
        switch (number_units)
        {
            case 0: printf("ten");
                    break;
            case 1: printf("eleven");
                    break;
            case 2: printf("twelve");
                    break;
            case 3: printf("thirteen");
                    break;
            case 4: printf("fourteen");
                    break;
            case 5: printf("fifteen");
                    break;
            case 6: printf("sixteen");
                    break;
            case 7: printf("seventeen");
                    break;
            case 8: printf("eighteeen");
                    break;
            case 9: printf("nineteen");
                    break;
        }
    }

    printf(".\n");

    return 0;
}
