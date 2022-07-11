#include <stdlib.h>

void    *ft_free_all(char **arr)
{
    int i;

    i = 0;
    if (!arr)
        return (NULL);
    while (arr[i])
    {
        free(arr[i]);
        i++;
    }
    free(arr);
    return (NULL);
}