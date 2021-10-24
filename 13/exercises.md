# Chapter 13 exercises

1. (b) `%c` specifier requires an argument of type `char`, but got an argument
       of type `char *`.  
   (c) `%s` specifier requires an argument of type `char *`, but got an argument
       of type `char`.  
   (e) `printf` requires an argument of type `char *`, but got an argument of
       type `char`.  
   (h) `putchar` requires an argument of type `char`, but got an argument of type
       `char *`.  
   (i) `puts` requires an argument of type `char *`, but got an argument of type
       `char`.  
   (j) `puts` already inserts a new-line, so `\n` will cause it to put two
       new-line characters.

2. (a) ILLEGAL. `putchar` requires an argument of type `char`, but got an
       argument of type `char *`.  
   (b) Output: a  
   (c) Output: abc  
   (d) ILLEGAL. `puts` requires an argument of type `char *`, but got an
       argument of type char.

3. `i` will be `12`,  
   `s` will be `abc34`,  
   `j` will be `56`.

4. a)

   ```c
   int read_line(char str[], int n)
   {
       int ch, i = 0;

       while (isspace(ch = getchar()));
       do
       {
           if (i < n)
               str[i++] = ch;
       } while ((ch = getchar()) != '\n');

       str[i] = '\0';
       return i;
   }
   ```

   b)

   ```c
   int read_line(char str[], int n)
   {
       int ch, i = 0;

       while ((ch = getchar()) != '\n' && !isspace(ch))
           if (i < n)
               str[i++] = ch;
       str[i] = '\0';
       return i;
   }
   ```

   c)

   ```c
   int read_line(char str[], int n)
   {
       int i = 0;

       while (i < n && (str[i++] = getchar()) != '\n');
       str[i] = '\0';
       return i;
   }
   ```

   d)

   ```c
   int read_line(char str[], int n)
   {
       int ch, i = 0;

       while (i < n && (ch = getchar()) != '\n')
           str[i++] = ch;
       str[i] = '\0';
       return i;
   }
   ```

5. a)

   ```c
   #include <ctype.h>

   void capitalize(char p[])
   {
       int i = 0;

       while (p[i])
       {
           p[i] = toupper(p[i]);
           ++i;
       }
   }
   ```

   b)

   ```c
   #include <ctype.h>

   void capitalize(char p[])
   {
       while (*p)
       {
           *p = toupper(*p);
           ++p;
       }
   }
   ```

6. ```c
   #include <string.h>

   void censor(char *p)
   {
       while (*p)
       {
           if (*p == 'f' && p[1] == 'o' && p[2] == 'o')
           {
               *p = p[1] = p[2] = 'x';
               p += 3;
           }
           else ++p;
       }
   }
   ```

7. (d) because the effect of strcat depends on the string's content.

8. tired-or-wired?

9. computers

10. `char *q` doesn't point to or allocate memory for the copied string.

11. ```c
    int strcmp(char *s, char *t)
    {
        for (; *s == *t; ++s, ++t)
            if (*s == '\0')
                return 0;
        return *s - *t;
    }
    ```

12. ```c
    #include <string.h>

    void get_extension(const char *file_name, char *extension)
    {
        const char *p = file_name + strlen(file_name);

        while (--p >= file_name)
        {
            if (*p == '.')
            {
                strcpy(extension, p + 1);
                return;
            }
        }

        *extension = '\0';
    }
    ```

13. ```c
    #include <string.h>

    void build_index_url(const char *domain, char *index_url)
    {
        strcpy(index_url, "http://www.");
        strcat(index_url, domain);
        strcat(index_url, "/index.html");
    }
    ```

14. Grinch (assuming the ASCII charset is used).

15. a) 3
    b) 0
    c) The index of the first character of `s` that doesn't appear in `t`.  If
       such character isn't found, the function returns the index of the
       terminating null character of `s`.

16. ```c
    int count_spaces(const char *s)
    {
        int count = 0;

        while (*s)
            if (*s++ == ' ')
                count++;
        return count;
    }
    ```

17. ```c
    #include <ctype.h>
    #include <stdbool.h>
    #include <stdio.h>

    bool test_extension(const char *file_name,
                        const char *extension)
    {
        int length = 0;

        while (file_name[length])
            ++length;
        while (file_name[--length] != '.')
            if (!length) return false;
        file_name += length;
        while (*file_name)
            if (toupper(*++file_name) != toupper(*extension++))
            return false;
        return true;
    }

    int main(void)
    {
        char file_name[64], file_ext[32];

        scanf("%s", file_name);
        scanf("%s", file_ext);

        printf("%d", test_extension(file_name, file_ext));

        return 0;
    }
    ```

18. ```c
    #include <stdio.h>

    void remove_filename(char *url)
    {
        char *slash = NULL;

        while (*url)
        {
            if (*url == '/')
                slash = url;
            ++url;
        }

        if (slash)
            *slash = '\0';
    }

    int main(void)
    {
        char site[64];

        scanf("%s", site);

        remove_filename(site);

        printf("%s", site);

        return 0;
    }
    ```
