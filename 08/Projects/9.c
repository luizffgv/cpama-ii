#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int main(void)
{
    char map[10][10];
    char step;
    int direction;
    int i, x, y;
    bool direction_available[4] = {1, 1, 1, 1};

    srand(time(NULL));

    for (y = 0; y < 10; y++)
        for (x = 0; x < 10; x++)
            map[y][x] = '.';

    step = 'A';
    x = y = 0;
    map[x][y] = step++;

    while (step <= 'Z')
    {
        direction_available[0] = (map[y+1][x] == '.' && y < 9) ? true : false;
        direction_available[1] = (map[y-1][x] == '.' && y > 0) ? true : false;
        direction_available[2] = (map[y][x+1] == '.' && x < 9) ? true : false;
        direction_available[3] = (map[y][x-1] == '.' && x > 0) ? true : false;

        for (i = 0; i < 4 && direction_available[i] == false; i++);
        if (i >= 4) break;
        else
        {
            do
                direction = rand() % 4;
            while (!direction_available[direction]);

            switch (direction)
            {
                case 0:
                    ++y;
                    break;
                case 1:
                    --y;
                    break;
                case 2:
                    ++x;
                    break;
                case 3:
                    --x;
                    break;
            }
            map[y][x] = step++;
        }
    }

    for (y = 0; y < 10; y++)
    {
        for (x = 0; x < 10; x++)
            printf("%2c", map[y][x]);
        printf("\n");
    }

    return 0;
}
