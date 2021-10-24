#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

void generate_random_walk(char walk[10][10]);
void print_array(char walk[10][10]);

int main(void)
{
    char map[10][10];
    int y, x;

    srand(time(NULL));

    for (y = 0; y < 10; y++)
        for (x = 0; x < 10; x++)
            map[y][x] = '.';

    generate_random_walk(map);
    print_array(map);

    return 0;
}

void generate_random_walk(char walk[10][10])
{
    int i;
    int y, x;
    int direction;
    char step;
    bool direction_available[4] = {1, 1, 1, 1};

    step = 'A';
    x = y = 0;
    walk[x][y] = step++;

    while (step <= 'Z')
    {
        direction_available[0] = (walk[y+1][x] == '.' && y < 9) ? true : false;
        direction_available[1] = (walk[y-1][x] == '.' && y > 0) ? true : false;
        direction_available[2] = (walk[y][x+1] == '.' && x < 9) ? true : false;
        direction_available[3] = (walk[y][x-1] == '.' && x > 0) ? true : false;

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
            walk[y][x] = step++;
        }
    }
}

void print_array(char walk[10][10])
{
    int y, x;

    for (y = 0; y < 10; y++)
    {
        for (x = 0; x < 10; x++)
            printf("%2c", walk[y][x]);
        printf("\n");
    }
}