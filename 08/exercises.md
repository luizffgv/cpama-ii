# Chapter 8 exercises

1. Because the first technique doesn't require you to rewrite the expression if
   you change the type of the variable. The second technique does.

   There is also no guarantee that the second method is correct. You have to
   check the type of `a` to verify that the expression is correct.

2. Subtract `'0'` from the character. The ISO standard mandates that digits have
   consecutive values in the underlying charset.

3. ```c
   _Bool weekend[7] = {1, 0, 0, 0, 0, 0, 1};
   ```

4. ```c
   #include<stdbool.h>

   bool weekend[7] = {true, [6] = true};
   ```

5. ```c
   #include <stdio.h>
   
   int main(void)
   {
       int fib_numbers[40] = {0, 1};
   
       for (int i = 2; i < 40; i++)
           fib_numbers[i] = fib_numbers[i-1] + fib_numbers[i-2];
   
       return 0;
   }
   ```

6. ```c
   const int segments[10][7] = { {1, 1, 1, 1, 1, 1, 0},
                                 {0, 1, 1, 0, 0, 0, 0},
                                 {1, 1, 0, 1, 1, 0, 1},
                                 {1, 1, 1, 1, 0, 0, 1},
                                 {0, 1, 1, 0, 0, 1, 1},
                                 {1, 0, 1, 1, 0, 1, 0},
                                 {1, 0, 1, 1, 1, 1, 1},
                                 {1, 1, 1, 0, 0, 0, 0},
                                 {1, 1, 1, 1, 1, 1, 1},
                                 {1, 1, 1, 1, 0, 1, 1} };
   ```

7. ```c
   const int segments[10][7] = { {1, 1, 1, 1, 1, 1},
                                 {0, 1, 1},
                                 {1, 1, 0, 1, 1, 0, 1},
                                 {1, 1, 1, 1, 0, 0, 1},
                                 {0, 1, 1, 0, 0, 1, 1},
                                 {1, 0, 1, 1, 0, 1},
                                 {1, 0, 1, 1, 1, 1, 1},
                                 {1, 1, 1},
                                 {1, 1, 1, 1, 1, 1, 1},
                                 {1, 1, 1, 1, 0, 1, 1} };
   ```

8. ```c
   float temperature_readings[30][24];
   ```

9. ```c
   #include<stdio.h>
   
   int main(void)
   {
       float temperature_readings[30][24];
       float month_average, day_sum;
   
       month_average = 0;
       for (int i = 0; i < 30; i++)
       {
           day_sum = 0;
           for (int j = 0; j < 24; j++)
           {
               day_sum += temperature_readings[i][j];
           }
           month_average += day_sum / 24;
       }
       month_average /= 30;
   
       return 0;
   }
   ```

10. ```c
    char chess_board[8][8] = { {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
                               {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
                               {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
                               {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
                               {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
                               {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
                               {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
                               {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'} };
    ```

11. ```c
    char checker_board[8][8];
    
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            checker_board[i][j] = (i + j) % 2 ? 'R' : 'B';
    ```
