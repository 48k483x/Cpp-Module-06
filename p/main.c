#include "philo.h"

int main(int ac, char **av)
{
    t_program program;
    int i = 1;
    if(ac != 5 && ac != 6)
    {
        printf("Error : Wrong number of arguments\n");
        return (1);
    }

    while(av[i])
    {
        if(!is_valid_str(av[i]) || ft_atoi(av[i]) <= 0 || ft_atoi(av[1]) > 200)
        {
            printf("Error : Invalid argument\n");
            return (1);
        }
        i++;
    }
    input_into_struct(&program, av);
    initialize_philos(&program);
    initialize_mutex(&program);
    philosophers(&program);

    // Cleanup resources
    for (i = 0; i < program.philos->num_of_philos; i++)
    {
        pthread_mutex_destroy(&program.mutex_arr[i]);
    }
    pthread_mutex_destroy(&program.write_lock);
    pthread_mutex_destroy(&program.meal_lock);
    pthread_mutex_destroy(&program.dead_lock);
    free(program.mutex_arr);
    free(program.philos);

    return (0);
}
