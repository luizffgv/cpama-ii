#include <stdio.h>

#define ARRAY_SIZE 10

void selection_sort(int a[], int n);

int main(void)
{
    int i;
    int array[ARRAY_SIZE];

    printf("Enter %d integers: ", ARRAY_SIZE);
    for (i = 0; i < ARRAY_SIZE; i++)
        scanf("%d", &array[i]);

    selection_sort(array, ARRAY_SIZE);

    printf("Sorted array: ");
    for (i = 0; i < ARRAY_SIZE; i++)
        printf("%d ", array[i]);
    printf("\n");

    return 0;
}

void selection_sort(int a[], int n)
{
    int i;
    int temp;
    int largest_index;

    if (n <= 2) return;

    largest_index = 0;
    for (i = 1; i < n; i++)
        if (a[i] > a[largest_index]) largest_index = i;

    temp = a[n-1];
    a[n-1] = a[largest_index];
    a[largest_index] = temp;

    selection_sort(a, n-1);

    return;
}