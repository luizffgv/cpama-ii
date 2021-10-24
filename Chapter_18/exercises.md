# Chapter 18 exercises

1. |    | Storage   | Qualifiers   | Specifier       | Declarators                      | Initializers |
   | -- | --------- | ------------ | --------------- | -------------------------------- | ------------ |
   | a) | `static`  |              | `char`          | `**lookup(int level)`            |              |
   | b) |           | `volatile`   | `unsigned long` | `io_flags`                       |              |
   | c) | `extern`  |              | `char`          | `*file_name[MAX_FILES], path[]`  |              |
   | d) | `static`  | `const`      | `char`          | `token_buf[]`                    | `""`         |

2. a) `extern`  
   b) `static`  
   c) `extern` (makes it not allocate space) and `static`
      (makes its memory duration `static`)

3. a) `static`, file, external  
   b) automatic, block, none
   c) `static`, block, none
   d) automatic, block, none

4. 0 and 50.

5. a) False. Static variables declared inside blocks have block scope
      (but they can be pointed to).  
   b) False. Extern variables declared inside functions have internal or
      external linkage.  
   c) True. Auto can't be used with static variables.  
   d) True. All parameters must have block scope.

6. The variable `n` must have `static` duration, otherwise it will be
   reinitialized every time the function is called.  
   Fixed definition: `static int n = 1`;

7. a) false. Case labels must be actual constant expressions.

8. a) `x` is an array of 10 pointers to functions with an `int` parameter and
      type `char`.  
   b) `x` is a function with an `int` parameter that returns a pointer to an
      array of (5) integers.  
   c) `x` is a function with no parameter that returns a pointer to a function
      with an `int` parameter which returns a `float` pointer.  
   d) `x` is a function that takes two arguments: an `int` and a pointer to a
      `void` function that has an `int` argument.  
      It returns a pointer to a `void` function with an `int` argument.

9. a)

   ```c
   typedef char func(int);
   typedef func *func_ptr;
   typedef func_ptr func_ptr_array[10];

   func_ptr_array x;
   ```

   b)

   ```c
   typedef int int_array[5];
   typedef int_array *func(int);

   func x;
   ```c

   c)

   ```c
   typedef float *func(int);
   typedef func *func_ptr;
   typedef func_ptr ffunc(void);

   ffunc x;
   ```

   d)

   ```c
   typedef void func(int);
   typedef func *func_x(int, *func)

   func_x x;
   ```

10. a)

    ```c
    char *(*p)(char *);
    ```

    b)

    ```c
    void *f(struct t *p, long n)(void);
    ```

    c)

    ```c
    void (*a[4])(void) = {insert, search, update, print};
    ```

    d)

    ```c
    struct t (*b[10])(int, int)
    ```

11. ```c
    int *f(int);
    int (*g(int))(int);
    int (*a[10])(int);
    ```

12. a) `f` takes two arguments: a pointer to a `float` function with a `long`
       parameter, and a `char` pointer.  
       `f` returns a pointer to a function with a `double` parameter and
       `int` return type.

    b) `a = f(b, c);` or `a = f((*b), c);`

13. (a), (c) and (d).

14. (e) None of the above.

15. (a).
