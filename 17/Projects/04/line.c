#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "line.h"

#define MAX_LINE_LEN 60

struct word
{
    struct word *next;
    char word[];
} *line = NULL;

int line_len = 0;
int num_words = 0;

void clear_line(void)
{
    struct word *cur, *prev;

    prev = cur = line;

    while (prev != NULL)
    {
        prev = cur;
        if (cur)
            cur = cur->next;
        free(prev);
    }

    line = NULL;

    line_len = 0;
    num_words = 0;
}

void add_word(const char *word)
{
    struct word *word_cur;
    struct word *word_new = malloc(sizeof(*word_new) + strlen(word) + 1);
    word_new->next = NULL;
    strcpy(word_new->word, word);
    line_len += strlen(word);

    if (num_words)
        ++line_len; // Space

    if (line == NULL)
        line = word_new;
    else
        for (word_cur = line; word_cur != NULL; word_cur = word_cur->next)
        {
            if (word_cur->next == NULL)
            {
                word_cur->next = word_new;
                break;
            }
        }

    ++num_words;
}

int space_remaining(void)
{
    return MAX_LINE_LEN - line_len;
}

void write_line(void)
{
    int extra_spaces, spaces_to_insert, i, j;
    struct word *word_cur;

    extra_spaces = MAX_LINE_LEN - line_len;

    for (word_cur = line; word_cur != NULL; word_cur = word_cur->next)
    {
        printf("%s ", word_cur->word);

        if (!word_cur->next)
            break;

        spaces_to_insert = extra_spaces / (num_words - 1);
        for (j = 1; j <= spaces_to_insert; j++)
            putchar(' ');
        extra_spaces -= spaces_to_insert;

        --num_words;
    }

    putchar('\n');
}

void flush_line(void)
{
    struct word *word_cur;

    if (line_len > 0)
    {
        for (word_cur = line; word_cur != NULL; word_cur = word_cur->next)
            printf("%s ", word_cur->word);
        putchar('\n');
    }
}