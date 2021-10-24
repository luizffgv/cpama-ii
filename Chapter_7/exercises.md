# Chapter 7 exercises

1. a) 63  
   b) 119  
   c) 2748

2. a) floating-point  
   b) floating-point  
   c) illegal (octal cant have 9)  
   d) illegal  
   e) floating-point

3. a) `short unsigned int`  
   b) ILLEGAL - `short float`  
   c) `long double`  
   d) `unsigned long`

4. a) `1 += c;  /* i has type int */`  
   b) `c = 2 * c - 1;`  
   c) `putchar(c);`  
   d) ILLEGAL - `printf(c);`

5. a) `'A'`  
   b) ILLEGAL - `0b1000001`  
   c) `0101`  
   d) `0x41`

6. |    | In my computer | In any computer |
   | -- | -------------- | --------------- |
   | a) | `char`         | `char`          |
   | b) | `short`        | `short`         |
   | c) | `short`        | `short`         |
   | d) | `int`          | `long`          |

7. a) `\0142`
   b) `\0156`
   c) `\0162`
   d) `\0164`

8. `a) \0x62`
   `b) \0x6E`
   `c) \0x72`
   `d) \0x74`

9. `int`. The `char` `'a'` is promoted to `int`.

10. `unsigned int`. `j` is cast to `int`, so the expression doesn't need `long`.

11. `double`. `i` and `f` are promoted to `double`.

12. `i` is promoted to `float`, the expression is therefore evaluated as
    `float`, the expression is converted to `double`, as per assignment
    conversion rules.

13. a) -3, `int`  
    b) 7, `long`  
    c) 6.5, `float`  
    d) 3.75, `double`  
    e) -1, `double`  
    f) 6, `int`

14. No. Some float numbers may be too big to store as int, so really big/small
    numbers may not work properly.

15. ```c
    typedef char Int8;
    typedef short Int16;
    typedef int Int32;
    ```
