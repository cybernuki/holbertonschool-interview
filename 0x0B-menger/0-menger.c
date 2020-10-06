#include "menger.h"
#include <unistd.h>

void menger(int level)
{
    char **sponge = NULL;
    size_t size = pow(3, level);

    sponge = startSponge(size);
    if (!sponge)
        return;

    recordLevel(sponge, level, 0, 0, 0, size, size);
    printRecord(sponge, size);
    /*get size to allocate memory*/

    /* */
    closeSponge(sponge, size);
}

void recordLevel(char **sponge, int level, size_t i, size_t j, short center,
                 size_t limitI, size_t limitJ)
{
    size_t grid = pow(3, level - 1), iteration = 0;
    size_t prev_j = j, prev_i = i, prev_center = center;

    if (!level)
    {
        sponge[i][j] = center ? ' ' : '#';
        return;
    }

    for (i = prev_i; i < limitI; i += grid)
    {
        for (j = prev_j; j < limitJ; j += grid, iteration++)
        {
            center = prev_center;
            if (!center && iteration == 4)
                center = 1;
            recordLevel(sponge, level - 1, i, j, center, i + grid, j + grid);
        }
    }
}

void printRecord(char **sponge, size_t size)
{
    size_t i = 0, j = 0;

    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            printf("%c", sponge[i][j]);
            fflush(stdout);
            usleep(9000);
        }

        printf("\n");
    }
}

char **startSponge(size_t size)
{
    size_t i = 0, j = 0;
    char **sponge = calloc(size, sizeof(sponge));

    if (!sponge)
        return (NULL);

    for (i = 0; i < size; i++)
    {
        sponge[i] = calloc(size, sizeof(sponge));
        if (!sponge[i])
        {
            for (j = 0; j < i; j++)
                free(sponge[j]);
            return (NULL);
        }
    }
    return (sponge);
}

void closeSponge(char **sponge, size_t size)
{
    size_t i = 0;

    for (i = 0; i < size; i++)
        free(sponge[i]);
    free(sponge);
}
