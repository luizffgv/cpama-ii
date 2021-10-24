# Chapter 17 exercises

1. ```c
   #include <stdio.h>
   #include <stdlib.h>

   void *my_malloc(int size)
   {
       void *ptr = malloc(size);

       if (!ptr)
       {
           fprintf(stderr, "Malloc failed.");
           exit(EXIT_FAILURE);
       }
       return ptr;
   }
   ```

2. ```c
   #include <stdlib.h>
   #include <string.h>

   char *duplicate(const char *src)
   {
       char *dest = malloc(strlen(src) + 1);

       if (!dest)
           return NULL;
       return strcpy(dest, src);
   }
   ```

3. ```c
   #include <stdlib.h>

   int *create_array(int n, int initial_value)
   {
       int *array = malloc(sizeof(*array) * n);
       int *p = array;

       if (!array)
           return NULL;
       for (; n; --n)
           *p++ = initial_value;
       return array;
   }

4. ```c
   #include <stdlib.h>

   struct rectangle *rect = malloc(sizeof(*rect));
   rect->upper_left = (struct point) {10, 25};
   rect->lower_right = (struct point) {20, 15};
   ```

5. (b) and (c).

6. ```c
   struct node *delete_from_list(struct node *list, int n)
   {
       struct node *cur = list;

       if (cur->value == n)  /* n found at first node */
       {
           list = cur->next;
           free(cur);
           return list;
       }

       if (cur->value != n)
       while (cur->next && cur->next->value != n)
           cur = cur->next;

       if (cur->next == NULL)  /* n was not found */
           return list;

       struct node *temp = cur->next;  /* n was found */
       cur->next = cur->next->next;
       free(temp);
       return list;
   }
   ```

7. `free(p)` frees `p` before `p = p->next` is executed, so accessing `p` will
   be undefined. A simple fix would be the use of a temporary pointer:

   ```c
   p = first;
   while (p != NULL)
   {
       struct node *temp = p;
       p = p->next;
       free(temp);
   }
   ```

8. ```c
   #include <stdbool.h>
   #include <stdio.h>
   #include <stdlib.h>

   void make_empty(struct node **start)
   {
       struct node *temp;
       while (*start != NULL)
       {
           temp   = *start;
           *start = (*start)->next;
           free(temp);
       }
   }

   int is_empty(struct node *start)
   {
       return (start == NULL);
   }

   bool push(struct node **start, int i)
   {
       struct node *node_new = malloc(sizeof(*node_new));
       if (node_new == NULL)
           return false;

       node_new->next = *start;
       node_new->value = i;
       *start = node_new;
       return true;
   }

   int pop(struct node **start)
   {
       int value;
       struct node *temp;

       if (is_empty(*start))
       {
           fputs("Stack underflow\n", stderr);
           exit(EXIT_FAILURE);
       }

       value  = (*start)->value;
       temp   = *start;
       *start = (*start)->next;
       free(temp);

       return value;
   }
   ```

9. True. `(&x)` is a pointer to `x`, so using the `->` operator on it will yield
   the same result as using the `.` operator on `x`.

10. ```c
    #include <stdio.h>

    void print_part(struct part *p)
    {
        printf("Part number: %d\n", p->number);
        printf("Part name: %s\n", p->name);
        printf("Quantity on hand: %d\n", p->on_hand);
    }

11. ```c
    int count_occurrences(struct node *list, int n)
    {
        int count = 0;

        while (list != NULL)
        {
            if (list->value == n)
                ++count;
            list = list->next;
        }

        return count;
    }
    ```

12. ```c
    #include <stdlib.h>

    struct node *find_last(struct node *list, int n)
    {
        struct node *last = NULL;

        while (list != NULL)
        {
            if (list->value == n)
                last = list;
            list = list->next;
        }

        return last;
    }
    ```

13. It doesn't check whether `prev` is `NULL` or not after the loop.  
    Fixed version:

    ```c
    struct node *insert_into_ordered_list(struct node *list,
                                          struct node *new_node)
    {
        struct node *cur = list, *prev = NULL;

        while (cur != NULL && cur->value <= new_node->value) {
            prev = cur;
            cur = cur->next;
        }

        if (prev == NULL)                /* Insert at start */
        {
            new_node->next = list;
            return new_node;
        }
        prev->next = new_node;           /* Insert elsewhere */
        new_node->next = cur;
        return list;
    }
    ```

14. ```c
    void delete_from_list(struct node **list, int n)
    {
        struct node *cur, *prev;

        for (cur = *list, prev = NULL;
             cur != NULL && cur->value != n;
             prev = cur, cur = cur->next)
            ;

        if (cur == NULL)
            return;
        if (prev == NULL)
            *list = list->next;
        else
            prev->next = cur->next;
        free(cur);
    }
    ```

15. Output: `Answer: 3`  
    The program prints the smallest positive integer value that makes `f2`
    evaluate to `0`.

16. ```c
    int sum(int (*f)(int), int start, int end)
    {
        int value = 0;

        while (start <= end)
        {
            value += (*f)(start);
            ++start;
        }

        return value;
    }
    ```

17. ```c
    qsort(a + 50, 50, sizeof(a[0]), compare);
    ```

18. ```c
    int compare_parts(const void *p, const void *q)
    {
        const struct part *p1 = p;
        const struct part *q1 = q;

        if (p1->number > q1->number)
            return -1;
        if (p1->number == q1->number)
            return 0;
        return 1;
    }
    ```

19. ```c
    void func_call(char *name)
    {
        for (int i = 0; i < sizeof(file_cmd) / sizeof(file_cmd[0]); ++i)
            if (strcmp(file_cmd[i].cmd_name, name) == 0)
            {
                (*file_cmd[i].cmd_pointer)();
                return;
                // Could be return (*file_cmd[i].cmd_pointer)();
            }
    }
    ```
