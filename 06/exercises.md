# Chapter 6 exercises

1. 1 2 4 8 16 32 64 128

2. 9384 938 93 9

3. 5 4 3 2

4. (c) because it increments `i` before the loop body, rather than after.

5. (c) because the condition is evaluated after the body, therefore the body is executed at least once.

6. `for (i = 1; i <= 128; i *= 2)`

7. `for (i = 9384; i > 0; i /= 10)`

8. 10 5 3 2 1 1 1 1 1 (now prints 1 forever)

9. ```c
   i = 10;
   while (i >= 1)
   {
       printf("%d ", i++);
       i/= 2 
   }
   ```

10. Place the label just before the closing `}` of the loop body.
    Replace the continue with `goto label;`  
    Example:

    ```c
    while (condition)
    {
        // Statements
        goto end;
        // Statements
        end: ; // Null statement
    }
    ```

11. 20

12. ```c
    for (d = 2; d * d <= n; d++)
        if (n % d == 0)
            break;
    ```

13. ```c
    for (n = 0; m > 0; n++, m /= 2);
    // Empty body
    ```

14. The `if (...)` is followed by a null statement.  
    Fixed:

    ```c
    if (n % 2 == 0)
        printf("n is even\n");
    ```
