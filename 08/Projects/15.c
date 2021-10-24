#include <stdio.h>

#define LENGTH 80

int main(void)
{
    int length = 0;
    int i;
    int shift;
    char message[LENGTH+1];
    char buf;

    printf("Enter message to be encrypted: ");
    while ((buf = getchar()) != '\n')
        message[length++] = buf;

    printf("Enter shift amount (1-25): ");
    scanf("%d", &shift);

    for (i = 0; i < length; i++)
    {
        if (message[i] >= 97 && message[i] <= 122)
            message[i] = ((message[i] - 'a') + shift) % 26 + 'a';
        if (message[i] >= 65 && message[i] <= 90)
            message[i] = ((message[i] - 'A') + shift) % 26 + 'A';

        putchar(message[i]);
    }
    printf("\n");

    return 0;
}
