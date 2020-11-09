#include "search.h"

/**
 * linear_skip - do a search by the given value
 * @list: is the given list
 * @value: is the value to be searched
 * Return: the node with the value or null if no found.
 **/
skiplist_t *linear_skip(skiplist_t *list, int value)
{
    skiplist_t *current = list, *express = NULL;

    while (current)
    {
        if (value == current->n)
            return (current);
        express = current->express;
        current = (express && value >= express->n) ? express : current->next;
    }

    return (NULL);
}
