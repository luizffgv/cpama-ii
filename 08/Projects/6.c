#include <stdio.h>

int main(void)
{
    char buf;

    do
    {
        scanf("%c", &buf);
        if (buf == '\n') break;
        if (buf >= 'a' && buf <= 'z')
            (buf -= 'a' - 'A');

        switch (buf)
        {
            case 'A':
                buf = '4';
                break;
            case 'B':
                buf = '8';
                break;
            case 'E':
                buf = '3';
                break;
            case 'I':
                buf = '1';
                break;
            case 'O':
                buf = '0';
                break;
            case 'S':
                buf = '5';
                break;
        }

        printf("%c", buf);
    }
    while (buf != '\n');
    printf("!!!!!!\n");

    return 0;
}
