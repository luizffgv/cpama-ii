# Chapter 9 exercises

1. ```c
   /* The definition of product should be inside the braces,
     and the 'height' parameter is missing its type.
   */
   
   //Corrected version: 
   
   double triangle_area(double base, double height)
   {
       double product;
       product = base * height;
       return product / 2;
   }
   ```
  
2. ```c
   int check(int x, int y, int n)
   {
       if (x < 0 || x > n - 1) return 0;
       else if (y < 0 || y > n - 1) return 0;
       else return 1;
   }
   
   /* Or */
   
   int check(int x, int y, int n)
   {
       return (x >= 0 && x <= n-1 && y >= 0 && y <= n-1);
   }
   ```

3. ```c
   int gcd(int m, int n)
   {
       int remainder;
       while (n != 0)
       {
           remainder = m % n;
           m = n;
           n = remainder;
       }
   
       return m;
   }
   ```

4. ```c
   int day_of_the_year(int month, int day, int year)
   {
       int days = 0;
       int month_days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
   
       if (month > 2 && year % 4 == 0)
           ++days;
   
       for (month -= 2; month >= 0; month--)
           days += month_days[month];
   
       return days += day;
   }
   ```

5. ```c
   int num_digits(int n)
   {
       int digits = 0;
       while (n > 0)
       {
           ++digits;
           n /= 10;
       }
   
       return digits;
   }
   ```

6. ```c
   int digit(int n, int k)
   {
       /*   Invalid   */
       if (k <= 0) return -1;
   
       while (--k)
           n /= 10;
   
       return n % 10;
   }
   ```

7. All of them are legal.

8. a) valid.  
   b) valid.  
   c) invalid.  
   d) invalid - int in C89, illegal in C99.

9. `i = 1, j = 2`  
   The function doesn't modify its arguments.

10. ```c
    int array_largest(int a[], int n)
    {
        int i = 0;
        int largest = a[i];
    
        for (i = 1; i < n; i++)
            if (a[i] > largest) largest = a[i];
    
        return largest;
    }
    
    int array_average(int a[], int n)
    {
        int i;
        int sum = 0;
    
        for (i = 0; i < n; i++)
            sum += a[i];
    
        return sum / n;
    }
    
    int array_positive(int a[], int n)
    {
        int i;
        int count = 0;
    
        for (i = 0; i < n; i++)
            if (a[i] >= 0) ++count;
    
        return count;
    }
    ```

11. ```c
    float compute_GPA(char grades[], int n)
    {
        int i;
        int sum;
    
        for (i = 0; i < n; i++)
            switch (grades[i])
            {
            case 'A': sum += 4;
            case 'B': sum += 3;
            case 'C': sum += 2;
            case 'D': sum += 1;
            case 'F': sum += 0;
            }
    
        return (float)i / n;
    }
    ```

12. ```c
    double inner_product(double a[], double b[], int n)
    {
        int i;
        double sum = 0;
    
        for (i = 0; i < n; i++)
            sum += a[i] * b[i];
    
        return sum;
    }
    ```

13. ```c
    int evaluate_position(char board[8][8])
    {
        int y, x;
        int white_value, black_value;
    
        for (y = 0; y < 8; y++)
            for (x = 0; x < 8; x++)
                switch (board[y][x])
                {
                case 'Q':
                    white_value += 9;
                    break;
                case 'R':
                    white_value += 5;
                    break;
                case 'B': case 'N':
                    white_value += 3;
                    break;
                case 'P':
                    white_value += 1;
                    break;
                case 'q':
                    black_value += 9;
                    break;
                case 'r':
                    black_value += 5;
                    break;
                case 'b': case 'n':
                    black_value += 3;
                    break;
                case 'p':
                    black_value += 1;
                    break;
                }
    
        return white_value - black_value;
    }
    ```

14. ```c
    /* The program returns false at the first nonzero value found, because false is
       badly placed.
       The fixed version only returns false if ALL values are nonzero */
    
    #include <stdbool.h>
    
    bool has_zero(int a[], int n)
    {
        int i;
    
        for (i = 0; i < n; i++)
            if (a[i] == 0)
                return true;
        return false;
    }
    ```

15. ```c
    double median(double x, double y, double z)
    {
        double median = x;

        if ((x <= y && y <= z) || (z <= y && y <= x))
            median = y;
        else if ((x <= z && z <= y) || (y <= z && z <= x))
            median = z;

        return median;
    }
    ```

16. ```c
    int fact(int n)
    {
        return n <= 1 ? 1 : n * fact(n-1);
    }
    ```

17. ```c
    int fact(int n)
    {
        int result = 1;
        while (n > 1)
            result *= n--;
        
        return result;
    }
    ```

18. ```c
    int gcd(int m, int n)
    {
        if (n == 0)
            return m;
        else return gcd(n, m % n);
    }
    ```

19. ```c
    /*
        Let's assume pb(5) is called.
        5 != 0, so it calls pb(2). After the control returns, it will print 1.
        2 != 0, so it calls pb(1). After the control returns, it will print 0.
        1 != 0, so it calls pb(0). After the control returns, it will print 1.
        0 == 0. The recursion ends and each previous pb prints (n % 2) in
            backwards order, which ends up being the binary representation of
            the first pb call's argument.
        
        Input: 5
        Output: 101
    */

    #include <stdio.h>

    void pb(int n);

    int main(void)
    {
        int number;

        printf("Enter an integer to be converted: ");
        scanf("%d", &number);

        printf("%d in binary: ", number);
        pb(number);

        return 0;
    }

    void pb(int n)
    {
        if (n != 0) {
            pb(n / 2);
            putchar('0' + n % 2);
        }
    }
    ```
