#include<stdio.h>

int main(void)
{
    long i, n;

    printf("This program prints a table of squares.\n");
    printf("Enter number of entries in table: ");
    scanf("%ld", &n);

        printf("%10ld%10ld\n", i, i * i);

    return 0;
}

/*
    With int variables, the program works until the user
    types something over 46340.
    46340 squared equals 2147395600, which is the last
    square smaller than or equal to 2147483648, which is
    the upper limit of a signed 32 bits number.
    32 bits equals 4 bytes, so my computer's int is 4 bytes.

    Short variables have stranger side effects.
    When the user inserts something over 32766, the for does
    an infinite loop. I assume that's because a signed short
    can't reach 32768 which is the required minimum value of
    i for the loop to end. When the signed short reaches its
    most significant bit, it becomes negative.

    An input lesser than 32767 is not error-free though.
    The program only works correctly until 181.
    Same principle, 181 is the last number which can be
    squared and result in less than 32767, which means
    we get an incorrect result past that value.
    We can assume that my computer stores short as
    16 bytes, with 1 being the sign bit, so in reality
    we have 2^15 which equals 32768. That's 2 bytes.

    Long variables can be so huge they become a pain in
    the ass to work with.
    An input greater than 3.037.000.499 causes the program
    to print negative squares. In the case of 3.037.000.499,
    the square is 9.223372e18; which matches 2^63: 9.223372e18.
    As per the aforementioned conclusions about previous types,
    I can tell that my computer stores long numbers
    in 64 bits. With 1 being the sign bit, of course.
*/
