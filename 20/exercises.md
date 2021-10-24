# Chapter 20 exercises

1. a) 0  
   b) 0  
   c) 1  
   d) 15

2. XOR the variable with a mask. The bits for which the mask counterpart is 1
   will be toggled, otherwise will remain the same.  
   Example:

   ```c
   // Toggling bit 4 of variable i (in two different ways)

   i ^= 1 << 4;

   i ^= 0x0010;
   ```

3. It swaps their values.

4. ```c
   #define MK_COLOR(r, g, b) ((long) (r) | (g) << 8 | (b) << 16)
   ```

5. ```c
   #define GET_RED(x)   (0xFF & (x))
   #define GET_GREEN(x) (0xFF & (x) >> 8)
   #define GET_BLUE(x)  (0xFF & (x) >> 16)
   ```

6. a)

   ```c
   #include <stdio.h>

   unsigned short swap_bytes(unsigned short i)
   {
       unsigned short temp = i >> 8;
       i <<= 8;

       return i | temp;
   }

   int main(void)
   {
       unsigned short n;

       scanf("%hx", &n);
       printf("%hX\n", swap_bytes(n));

       return 0;
   }
   ```

   b)

   ```c
   #include <stdio.h>

   unsigned short swap_bytes(unsigned short i)
   {
       return i << 8 | i >> 8;
   }

   int main(void)
   {
       unsigned short n;

       scanf("%hx", &n);
       printf("%hX\n", swap_bytes(n));

       return 0;
   }
   ```

7. ```c
   #include <stdio.h>

   unsigned int rotate_left(unsigned int i, int n);
   unsigned int rotate_right(unsigned int i, int n);

   int main(void)
   {
       unsigned int i;
       int n;

       scanf("%x", &i);
       scanf("%d", &n);

       printf("0x%x\n0x%x\n", rotate_left(i, n), rotate_right(i, n));

       return 0;
   }

   unsigned int rotate_left(unsigned int i, int n)
   {
       n %= sizeof(i) * 8;
       return i << n | i >> sizeof(i) * 8 - n;
   }

   unsigned int rotate_right(unsigned int i, int n)
   {
       n %= sizeof(i) * 8;
       return i >> n | i << sizeof(i) * 8 - n;
   }
   ```

8. a) Evaluates to a number in which the lowest `n` bits are `1`.  
   b) Returns a bit field of `i` with size `n`, starting at the `m` bit from
      right to left.

9. a)

   ```c
   int count_ones(unsigned char ch)
   {
       int shifts = sizeof(unsigned char) * 8 - 1;
       int count = 0;

       while (shifts--)
       {
           if (ch & 1)
               ++count;
           ch >>= 1;
       }
       return count;
   }
   ```

   b)

   ```c
   int count_ones(unsigned char ch)
   {
       return (ch & 1) + ((ch >>= 1) & 1) + ((ch >>= 1) & 1) + ((ch >>= 1) & 1)
                       + ((ch >>= 1) & 1) + ((ch >>= 1) & 1) + ((ch >>= 1) & 1)
                       + ((ch >>= 1) & 1);
   }
   ```

10. ```c
    unsigned int reverse_bits(unsigned int n)
    {
        int bits = sizeof(unsigned int) * 8;
        unsigned int reversed = 0;

        while (bits--)
        {
            reversed <<= 1;
            reversed |= n & 1;
            n >>= 1;
        }

        return reversed;
    }
    ```

11. The `==` operator has higher precedence than the `&` operator.  
    `(SHIFT_BIT | CTRL_BIT | ALT_BIT) == 0` is always `0`, so `key_code & 0` is
    always `false`.  
    Parentheses around the `&` operation will fix the precedence problem:

    ```c
    if ((key_code & (SHIFT_BIT | CTRL_BIT | ALT_BIT)) == 0)
        printf("No modifier keys pressed\n");
    ```

12. The `+` operator has higher precedence than `<<`. Replacing `+` with `|`
    or adding parentheses both fix the problem.  
    Fix 1: `return high_byte << 8 | low_byte;`  
    Fix 2: `return (high_byte << 8) + low_byte`;

13. It unsets the least significant set bit of `n`.

14. ```c
    struct fp
    {
        unsigned fraction : 23;
        unsigned exponent : 8;
        unsigned sign     : 1;
    };
    ```

15. a) `flag` has only 1 bit, so the compiler decides whether the bit will be
       used as a sign bit or not.

    b) Using `unsigned` instead of `int`: `unsigned flag: 1;`

16. ```c
    typedef unsigned char BYTE;
    typedef unsigned short WORD;
    typedef unsigned int DWORD; // My unsigned long is 64 bits.

    union {
        struct {
            WORD AX, x, BX, y, CX, z, DX, w;
        } word;
        struct {
            DWORD EAX, EBX, ECX, EDX;
        } dword;
        struct {
            BYTE AH, AL, x[2], BH, BL, y[2], CH, CL, z[2], DH, DL, w[2];
        } byte;
    } regs;

    #include <stdio.h>
    int main(void)
    {
        regs.dword.EAX = 0xA0A1A2A3;
        regs.dword.EBX = 0xB0B1B2B3;
        regs.dword.ECX = 0xC0C1C2C3;
        regs.dword.EDX = 0xD0D1D2D3;

        printf("EAX: %X\n", regs.dword.EAX);
        printf("EBX: %X\n", regs.dword.EBX);
        printf("ECX: %X\n", regs.dword.ECX);
        printf("EDX: %X\n", regs.dword.EDX);
        putchar('\n');
        printf("AX: %hX\n", regs.word.AX);
        printf("BX: %hX\n", regs.word.BX);
        printf("CX: %hX\n", regs.word.CX);
        printf("DX: %hX\n", regs.word.DX);
        putchar('\n');
        printf("AL: %X\n", (unsigned int) regs.byte.AL);
        printf("AH: %X\n", (unsigned int) regs.byte.AH);
        printf("BL: %X\n", (unsigned int) regs.byte.BL);
        printf("BH: %X\n", (unsigned int) regs.byte.BH);
        printf("CL: %X\n", (unsigned int) regs.byte.CL);
        printf("CH: %X\n", (unsigned int) regs.byte.CH);
        printf("DL: %X\n", (unsigned int) regs.byte.DL);
        printf("DH: %X\n", (unsigned int) regs.byte.DH);

        return 0;
    }
    ```
