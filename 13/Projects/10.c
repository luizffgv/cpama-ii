#include <stdio.h>
#include <string.h>

void read_line(char *dest, int size);
void reverse_name(char *name);

int main(void)
{
    char name[64];

    read_line(name, sizeof(name));
    reverse_name(name);
    printf("%s\n", name);

    return 0;
}

void read_line(char *dest, int size)
{
    char buf;
    int  i = 0;

    while (i < size - 1)
        if ((buf = getchar()) != '\n')
            dest[i++] = buf;
        else
            break;
    dest[i] = '\0';
}

void reverse_name(char *name)
{
    char  last_char[2] = { [1] = '.' };
    char *last_name    = name;

    while (*last_name == ' ') ++last_name;
    last_char[0] = *last_name;
    while (*last_name++ != ' ')
        ;
    while (*last_name == ' ') ++last_name;

    for (int i = 0; last_name[i]; ++i)
        if (last_name[i] == ' ')
        {
            last_name[i] = '\0';
            break;
        }

    strcat(strcat(strcpy(name, last_name), ", "), last_char);
}