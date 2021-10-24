# Chapter 15 exercises

1. a)
      1. Allows better debugging, since, for example, having multiple files
         allows the program to easily define `DEBUG` for one section only, with
         GCC's `-D`.
      2. Makes it faster to switch between parts of the program. For example,
         you wouldn't need to search where the functions related to X are, just
         open their respective files.

   b)
      1. Compiling and linking the program is harder.
      2. Using multiple files also has its traps. Files require proper
         organization, and programs can have many problems if a small mistake is
         made.

2. b) A header should be a "guide" for the contents of its .c file. Having
      function definitions in a header results in a higher possibility of linker
      errors.

3. Not always. Only if the compiler finds a different local file with the same
   name.

4. a)

   ```text
   Output if DEBUG is defined:  
   Value of i: 1
   Value of j: 2
   Value of k: 3
   Value of i + j: 3  
   Value of 2 * i + j - k: 1
   ```

   b) `Output if debug is not defined:`

   c) The first `printf` calls depend on whether `DEBUG` is defined, and
      `PRINT_DEBUG(...)` becomes an empty line if `DEBUG` is not defined.

   d) Yes, as the preprocessor goes from top to bottom and `#ifdef` only
      verifies the definitions up to that point.

5. ```make
   demo: main.o f1.o f2.o
       gcc -o demo main.o f1.o f2.o

   main.o: main.c f1.h
       gcc -c main.c

   f1.o: f1.c f1.h f2.h
       gcc -c f1.c

   f2.o: f2.c f1.h f2.h
       gcc -c f2.c
   ```

6. a) main.c, f1.c, f2.c.  
   b) f1.c.  
   c) main.c, f1.c, f2.c.  
   d) f1.c, f2.c.
