// philo.h
#ifndef PHILO_H
# define PHILO_H

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <limits.h>

typedef struct s_philo
{
    int id;
    int eating;
    int meals_eaten;
    long long start_time;
    long long last_meal;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    int num_of_philos;
    int num_times_to_eat;
    int *dead;
    pthread_mutex_t *r_fork;
    pthread_mutex_t *l_fork;
    pthread_mutex_t *write_lock;
    pthread_mutex_t *meal_lock;
    pthread_mutex_t *dead_lock;
    pthread_t thread;
} t_philo;

typedef struct s_program
{
    t_philo *philos;
    pthread_mutex_t *mutex_arr;
    pthread_mutex_t write_lock;
    pthread_mutex_t meal_lock;
    pthread_mutex_t dead_lock;
    pthread_t monitor_thread;
    int dead_flag;
} t_program;

// Function prototypes
void input_error(void);
void input_into_struct(t_program *program, char **av);
long long get_time(void);
int ft_atoi(char *str);
int is_valid_str(char *str);
void initialize_philos(t_program *program);
void initialize_mutex(t_program *program);
void *philosophers(void *arg);
void *philosopher_life(void *arg);
void eat(t_philo *philo);
void sleepp(t_philo *philo);
void print_status(t_philo *philo, char *status);
void smart_sleep(long long time);
int monitor(t_philo *philo);
void *monitor_routine(void *arg);

#endif