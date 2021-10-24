#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100
#define WORD_MAX_SIZE 21

int compare(const void *p, const void *q);
int read_line(char str[], int n);

int main(void)
{
    int words_num = 0;
    int len;
    char *words[MAX_WORDS] = {NULL};  // Size could also be realloc'ed
    char word_buf[WORD_MAX_SIZE];

    while (1)
    {
        printf("Enter word: ");
        if(!(len = read_line(word_buf, WORD_MAX_SIZE)))
            break;
        words[words_num] = malloc(len + 1);
        strcpy(words[words_num], word_buf);
        ++words_num;
    }

    qsort(words, words_num, sizeof(words[0]), compare);

    printf("In sorted order:");
    for (char **p = words; p < words + words_num; ++p)
        printf(" %s", *p);
    putchar('\n');
}

int compare(const void *p, const void *q)
{
    return strcmp(*(char **)p, *(char **)q);
}

int read_line(char str[], int n)
{
    int ch, i = 0;

    while ((ch = getchar()) != '\n')
        if (i < n)
            str[i++] = ch;
    str[i] = '\0';
    return i;
}