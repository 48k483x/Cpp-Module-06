#include "philo.h"
# include <limits.h>

int ft_strlen(char *str)
{
    int i = 0;
    while (str[i])
        i++;
    return i;
}

int is_valid_str(char *str)
{
    int i = 0;
    int space = 0;

    while (str[i])
    {
        if (str[i] >= '0' && str[i] <= '9')
            i++;
        else if (str[i] == ' ')
        {
            i++;
            space++;
        }
        else
            return 0;
    }
    if (ft_strlen(str) == space)
        return 0;
    return 1;
}

int ft_atoi(char *str)
{
    int i = 0;
    long res = 0;

    while (str[i])
    {
        res = res * 10 + (str[i] - '0');
        if (res > INT_MAX)
            return -1;  // Return -1 for overflow
        i++;
    }
    return (int)res;
}