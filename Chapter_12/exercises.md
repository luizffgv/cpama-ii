# Chapter 12 exercises

1. a) 14  
   b) 34  
   c) 4  
   d) true  
   e) false

2. Adding two pointers is illegal. It could be fixed by using another formula
   which calculates the difference by subtracting pointers (legal).

   ```c
   middle = low + (high - low) / 2;
   ```

3. The array will be reversed:  
   10, 9, 8, 7, 6, 5, 4, 3, 2, 1.

4. ```c
   #include <stdbool.h>

   void make_empty(int *top_ptr)
   {
       //top_ptr -= contents - top_ptr;
       top_ptr = contents;
   }

   bool is_empty(int *top_ptr)
   {
       return top_ptr <= contents;
   }

   bool is_full(int *top_ptr)
   {
       return top_ptr >= contents[STACK_SIZE];
   }
   ```

5. (a) is illegal. (b), (c) and (d) are true.

6. ```c
   int sum_array(const int *a, int n)
   {
       const int *p;
       int sum;

       sum = 0;
       for (p = a; p < p + n; p++)
           sum += *p;
       return sum;
   } 
   ```
  
7. ```c
   #include <stdbool.h>
   
   bool search(const int a[], int n, int key)
   {
       const int *p = a;
   
       while (*p != key && p < a + n)
           p++;
       
       return p < a + n;
   } 
   ```

8. ```c
   void store_zeros(int *a, int n)
   {
       int *p;

       for (p = a; p < a + n; p++)
           *p = 0;
   }
   ```

9. ```c
   double inner_product(const double *a, const double *b, int n)
   {
       double sum = 0.0;

       for (int count = 0; count++ < n; sum += *a++ * *b--);

       return sum;
   }
   ```

10. ```c
    int *find_middle(int a[], int n) {
        return a + n / 2;
    }
    ```

11. ```c
    int find_largest(int a[], int n)
    {
        int *p, max;

        max = *a;
        for (p = a + 1; p < a + n; p++)
            if (*p > max)
                max = *p;
        return max;
    }
    ```

12. ```c
    void find_two_largest(const int *a, int n, int *largest,
                          int *second_largest)
    {
        *second_largest = *largest = *a;

        for (; a < a + n; ++a)
            if (*a > *largest)
            {
                *second_largest = *largest;
                *largest = *a;
            }
            else if (*a > *second_largest)
                *second_largest = *a;
    }
    ```

13. ```c
    #define N 10
    
    double ident[N][N];
    
    double *p = *ident;
    int count = N;
    
    while (p < *(ident + N))
    {
        if (count == N)
        {
            *p++ = 1;
            count = 0;
        }
        else
        {
            *p++ = 0;
            ++count;
        }
    }
    ```

14. ```c
    search(*temperatures, 168, 32);
    ```

15. ```c
    for (int *p = temperatures[i]; p < temperatures[i] + 24; p++)
        printf("%-3d ", *p);
    ```

16. ```c
    for (int (*p)[24] = temperatures; p < temperatures + 7; p++)
        printf("%d ", find_largest(*p, 24));
    ```

17. ```c
    int sum_two_dimensional_array(const int a[][LEN], int n)
    {
        const int *p;
        int sum = 0;

        for (p = *a; p < *(a + n); p++)
            sum += *p;

        return sum;
    }
    ```

18. ```c
    int evaluate_position(const char (*board)[8])
    {
        int black, white;
        black = white = 0;
    
        for (const char *p = *board; p < *(board + 8); p++)
            switch (*p)
            {
            case 'Q':
                white += 9;
                break;
            case 'R':
                white += 5;
                break;
            case 'B':
            case 'N':
                white += 3;
                break;
            case 'P':
                white += 1;
                break;
            case 'q':
                black += 9;
                break;
            case 'r':
                black += 5;
                break;
            case 'b':
            case 'n':
                black += 3;
                break;
            case 'p':
                black += 1;
                break;
            }
    
        return white - black;
    }
    ```
