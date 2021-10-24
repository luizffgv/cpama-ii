#include <stdio.h>

int main(void)
{
    float grades[5][5];
    float sum, score_high, score_low;

    for (int student = 0; student < 5; student++)
    {
        printf("Enter student %d's grades: ", student+1);
        for (int quiz = 0; quiz < 5; quiz++)
            scanf("%f", &grades[student][quiz]);
    }

    for (int student = 0; student < 5; student++)
    {
        sum = 0;
        for (int quiz = 0; quiz < 5; quiz++)
        {
            sum += grades[student][quiz];
        }
        printf("Student %d score: %4.1f\n", student+1, sum);
        printf("Average: %4.1f\n", sum / 5.0f);
    }
    printf("\n");

    for (int quiz = 0; quiz < 5; quiz++)
    {
        sum = 0;
        score_low = score_high = grades[0][quiz];
        for (int student = 0; student < 5; student++)
        {
            if (grades[student][quiz] < score_low)
                score_low = grades[student][quiz];
            if (grades[student][quiz] > score_high)
                score_high = grades[student][quiz];

            sum += grades[student][quiz];
        }
        printf("Quiz %d average: %4.1f\n", quiz+1, sum / 5.0f);
        printf("High score: %4.1f\n", score_high);
        printf("Low score: %4.1f\n\n", score_low);
    }
    printf("\n");

    return 0;
}
