#include <stdio.h>

int main(void)
{
  int i, j, n;

  printf("This program prints a table of squares.\n");
  printf("Enter number of entries in table: ");
  scanf("%d", &n);
  getchar();

  for (i = 1, j = 1; i <= n; i++, j++)
  {
    printf("%10d%10d\n", i, i * i);

    if(j == 24)
    {
        printf("Press ENTER to continue...");
        getchar();
        j = 0;
    }
  }

  return 0;

}


