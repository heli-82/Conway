#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

const int HEIGHT = 10;
const int WIDTH = 10;

void process(bool grid[HEIGHT][WIDTH]) {
    bool newgrid[HEIGHT][WIDTH];
    memset(newgrid, 0, sizeof(bool) * HEIGHT * WIDTH);
    int neighbours;
    for (int y = 0; y < WIDTH; y++) {
        for (int x = 0; x < WIDTH; x++) {
            neighbours = 0;
            if (y > 0) {
                if (x > 0)
                    neighbours += grid[y - 1][x - 1];
                neighbours += grid[y - 1][x];
                if (x < WIDTH - 1)
                    neighbours += grid[y - 1][x + 1];
            }
            if (x > 0)
                neighbours += grid[y][x - 1];
            if (x < WIDTH - 1)
                neighbours += grid[y][x + 1];
            if (y < HEIGHT - 1) {
                if (x > 0)
                    neighbours += grid[y + 1][x - 1];
                neighbours += grid[y + 1][x];
                if (x < WIDTH - 1)
                    neighbours += grid[y + 1][x + 1];
            }

            if (grid[y][x]) {
                if (neighbours == 2 || neighbours == 3) {
                    newgrid[y][x] = 1;
                } else {
                    newgrid[y][x] = 0;
                }
            } else {
                if (neighbours == 3) {
                    newgrid[y][x] = 1;
                } else {
                    newgrid[y][x] = 0;
                }
            }
        }
    }
    memcpy(grid, newgrid, sizeof(bool) * WIDTH * HEIGHT);
}

int main() {
    bool grid[HEIGHT][WIDTH];
    memset(grid, 0, sizeof(bool) * HEIGHT * WIDTH);
    grid[3][3]=1;
    grid[3][4]=1;
    grid[3][5]=1;
    grid[4][4]=1;
    grid[5][4]=1;
    while (1) {
        system("clear");
        for (int y = 0; y < HEIGHT; y++) {
            for (int x = 0; x < WIDTH; x++) {
                if (grid[y][x])
                    printf("X");
                else
                    printf(" ");
            }
            printf("\n");
        }
        process(grid);

        sleep(1);
    }

    return 0;
}