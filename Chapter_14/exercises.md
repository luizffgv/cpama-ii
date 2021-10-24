# Chapter 14 exercises

1. ```c
   #define A(x) ((x) * (x) * (x))
   #define B(n) ((n) % 4)
   #define C(x,y) ((x) * (y) < 100 ? 1 : 0)

   // A doesn't work properly when the argument has side effects.
   ```

2. ```c
   #define NELEMS(a) (sizeof(a) / sizeof(a[0]))
   ```

3. a) `4`  
   b) `4`  
   c) `DOUBLE(x) (2*(x))`

4. a) Doesn't work correcty as the right operand of a division.  
      Can be fixed by using parentheses around the entire operation, like
      `((x + y))/2`.  
      Operands should also have parentheses, so `(((x) + (y)) / 2)`.

   b) Also doesn't work correctly as the right operand of a division.  
      Should be `((x) * (y))`.

5. a) D  
   b) 2

6. ```c
   #define DISP(f,x) printf(#f "(%g) = %g\n", (x), f(x))
   #define DISP2(f,x,y) printf(#f "(%g,%g) = %g\n", (x), (y), f((x),(y)))
   ```

7. a)

   ```c
   long long_max(long x, long y)
   {
       return x > y ? x : y;
   }
   ```

   b) It will try to use `unsigned long` as a function name, which is illegal
      because it contains spaces.

   c) Creating a new identifier for the type using `typedef`.

8. ```c
   #define xstr(s) str(s)
   #define str(s) #s
   #define LINE_FILE "Line " xstr(__LINE__) " of file " xstr(__FILE__)

   // Search for "argument prescan".
   ```

9. ```c
   #define CHECK(x,y,n) (((x) >= 0 && (x) < (n) && (y) >= 0 && (y) < (n)) ? 1 : 0)

   #define MAX(x,y) ((x) > (y) ? (x) : (y))
   #define MIN(x,y) ((x) < (y) ? (x) : (y))
   #define MEDIAN(x,y,z) (((x) > MAX((y),(z))) ? \
                           MAX((y),(z)) : \
                           ((x) > MIN((y),(z))) ? \
                             ((x)) : MIN((y),(z)))

   #define POLYNOMIAL(x) (  3 * (x) * (x) * (x) * (x) * (x) \
                          + 2 * (x) * (x) * (x) * (x) \
                          - 5 * (x) * (x) * (x) \
                          - (x) * (x) \
                          + 7 * (x) \
                          - 6) \
   ```

10. Firstly, a parametrized marco does not define `__func__`.  
    It is also not suitable for arguments that have side effects, and you can't
    take the address of a macro (see pointers to functions in chapter 17).

11. ```c
    #include<stdio.h>

    #define ERROR(...) fprintf(stderr, __VA_ARGS__)
    ```

12. c) `#ifndef M`  
    e) `#if !defined(M)`

13. a)

    ```c




    void f(void);

    int main(void)
    {
        f();



        return 0;
    }

    void f(void)
    {



        printf("N is undefined\n");

    }
    ```

    b) N is undefined

14. ```c








    int main(void)
    {
        int a[= 10], i, j, k, m; // Error


        i = j;




        i = 10 * j+1;
        i = (x,y) x-y(j, k); // Error
        i = ((((j)*(j)))*(((j)*(j))))
        i = (((j)*(j))*(j));
        i = jk; // Error
        puts("i" "j");


        i = SQR(j);

        i = (j);

        return 0;
    }
    ```

15. ```c
    #ifdef ENGLISH
    puts("Insert disk 1");
    #elif defined FRENCH
    puts("Inserez Le Disque 1");
    #elif defined SPANISH
    puts("Inserte El Disco 1");
    #endif
    ```

16. `#pragma ident "foo"`
