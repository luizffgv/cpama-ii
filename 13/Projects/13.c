#include <stdio.h>

#define LENGTH 80

void encrypt(char *message, int shift);

int main(void)
{
    int  length = 0;
    int  shift;
    char message[LENGTH + 1];
    char buf;

    printf("Enter message to be encrypted: ");
    while ((buf = getchar()) != '\n')
        message[length++] = buf;
    message[length] = '\0';

    printf("Enter shift amount (1-25): ");
    scanf("%d", &shift);

    encrypt(message, shift);

    printf("%s\n", message);

    return 0;
}

void encrypt(char *message, int shift)
{
    while (*message)
    {
        if (*message >= 97 && *message <= 122)
            *message = ((*message - 'a') + shift) % 26 + 'a';
        else if (*message >= 65 && *message <= 90)
            *message = ((*message - 'A') + shift) % 26 + 'A';
        ++message;
    }
}