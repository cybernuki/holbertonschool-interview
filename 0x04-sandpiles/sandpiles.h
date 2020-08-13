#ifndef SANDPILES_H
#define SANDPILES_H

#include <stdio.h>

#define SIZE 3
#define IN_RANGE(x, y) (x >= 0 && x < 3 && y >= 0 && y < 3)

void sandpiles_sum(int grid1[3][3], int grid2[3][3]);
#endif