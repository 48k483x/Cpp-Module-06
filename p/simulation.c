#include "philo.h"

void initialize_philos(t_program *program)
{
    int i = 0;
    long long start_time = get_time();

    while (i < program->philos->num_of_philos)
    {
        program->philos[i].id = i + 1;
        program->philos[i].eating = 0;
        program->philos[i].meals_eaten = 0;
        program->philos[i].start_time = start_time;
        program->philos[i].last_meal = start_time;
        program->philos[i].time_to_die = program->philos->time_to_die;
        program->philos[i].time_to_eat = program->philos->time_to_eat;
        program->philos[i].time_to_sleep = program->philos->time_to_sleep;
        program->philos[i].num_of_philos = program->philos->num_of_philos;
        program->philos[i].num_times_to_eat = program->philos->num_times_to_eat;
        program->philos[i].dead = &program->dead_flag;
        program->philos[i].write_lock = &program->write_lock;
        program->philos[i].meal_lock = &program->meal_lock;
        program->philos[i].dead_lock = &program->dead_lock;
        program->philos[i].r_fork = &program->mutex_arr[i];
        program->philos[i].l_fork = &program->mutex_arr[(i + 1) % program->philos->num_of_philos];
        i++;
    }
}

void initialize_mutex(t_program *program)
{
    int i = 0;
    pthread_mutex_init(&program->write_lock, NULL);
    pthread_mutex_init(&program->meal_lock, NULL);
    pthread_mutex_init(&program->dead_lock, NULL);
    while (i < program->philos->num_of_philos)
    {
        pthread_mutex_init(&program->mutex_arr[i], NULL);
        i++;
    }
}

void *philosophers(void *arg)
{
    t_program *program = (t_program *)arg;
    int i = 0;

    while (i < program->philos->num_of_philos)
    {
        if (pthread_create(&program->philos[i].thread, NULL, philosopher_life, &program->philos[i]) != 0)
        {
            printf("Error : Thread creation failed\n");
            program->dead_flag = 1;
            return NULL;
        }
        i++;
    }
    if (pthread_create(&program->monitor_thread, NULL, monitor_routine, program) != 0)
    {
        printf("Error : Monitor thread creation failed\n");
        program->dead_flag = 1;
        return NULL;
    }

    i = 0;
    while (i < program->philos->num_of_philos)
    {
        pthread_join(program->philos[i].thread, NULL);
        i++;
    }
    pthread_join(program->monitor_thread, NULL);

    return NULL;
}

void *philosopher_life(void *arg)
{
    t_philo *philo = (t_philo *)arg;

    if (philo->id % 2 == 0)
        usleep(1000);  // Slight delay for even-numbered philosophers

    while (!*(philo->dead))
    {
        eat(philo);
        if (*(philo->dead) || (philo->num_times_to_eat != -1 && philo->meals_eaten >= philo->num_times_to_eat))
            break;
        print_status(philo, "is thinking");
        sleepp(philo);
    }
    return NULL;
}

void eat(t_philo *philo)
{
    pthread_mutex_lock(philo->r_fork);
    print_status(philo, "has taken a fork");
    pthread_mutex_lock(philo->l_fork);
    print_status(philo, "has taken a fork");

    pthread_mutex_lock(philo->meal_lock);
    philo->eating = 1;
    philo->last_meal = get_time();
    print_status(philo, "is eating");
    pthread_mutex_unlock(philo->meal_lock);

    smart_sleep(philo->time_to_eat);
    philo->meals_eaten++;

    pthread_mutex_lock(philo->meal_lock);
    philo->eating = 0;
    pthread_mutex_unlock(philo->meal_lock);

    pthread_mutex_unlock(philo->l_fork);
    pthread_mutex_unlock(philo->r_fork);
}

void sleepp(t_philo *philo)
{
    print_status(philo, "is sleeping");
    smart_sleep(philo->time_to_sleep);
}

void print_status(t_philo *philo, char *status)
{
    pthread_mutex_lock(philo->write_lock);
    if (!*(philo->dead))
        printf("%lld %d %s\n", get_time() - philo->start_time, philo->id, status);
    pthread_mutex_unlock(philo->write_lock);
}

void smart_sleep(long long time)
{
    long long start = get_time();
    while (get_time() - start < time)
        usleep(100);
}

int monitor(t_philo *philo)
{
    pthread_mutex_lock(philo->meal_lock);
    if (get_time() - philo->last_meal > philo->time_to_die && !philo->eating)
    {
        pthread_mutex_unlock(philo->meal_lock);
        pthread_mutex_lock(philo->write_lock);
        printf("%lld %d died\n", get_time() - philo->start_time, philo->id);
        pthread_mutex_unlock(philo->write_lock);
        pthread_mutex_lock(philo->dead_lock);
        *(philo->dead) = 1;
        pthread_mutex_unlock(philo->dead_lock);
        return 1;
    }
    pthread_mutex_unlock(philo->meal_lock);
    return 0;
}

void *monitor_routine(void *arg)
{
    t_program *program = (t_program *)arg;
    int i;
    int all_ate = 0;

    while (!program->dead_flag && !all_ate)
    {
        i = 0;
        all_ate = (program->philos->num_times_to_eat != -1);
        while (i < program->philos->num_of_philos)
        {
            if (monitor(&program->philos[i]))
                return NULL;
            if (program->philos->num_times_to_eat != -1 &&
                program->philos[i].meals_eaten < program->philos->num_times_to_eat)
                all_ate = 0;
            i++;
        }
        usleep(1000);  // Small sleep to reduce CPU usage
    }
    return NULL;
}
