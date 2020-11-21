/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_three.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkathryn <fkathryn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 02:56:14 by fkathryn          #+#    #+#             */
/*   Updated: 2020/11/21 22:07:16 by fkathryn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_THREE_H
# define PHILO_THREE_H

# include <pthread.h>
# include <semaphore.h>
# include <sys/time.h>
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>

typedef struct			s_table {
	int					number_of_philos;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					number_of_times_each_philosopher_must_eat;
	long				start_time;
	int					someone_died;
	sem_t				*sem_fork;
	sem_t				*sem_time;
	sem_t				*sem_write;
	sem_t				*sem_waiter;
	sem_t				*sem_death;
	sem_t				*sem_philo_died;
}						t_table;

typedef struct			s_philos {
	t_table				*table;
	int					philo_id;
	long				last_eat;
	int					number_of_times_each_philosopher_must_eat;
}						t_philos;

/*
** condition_philo.c
*/

void					eating(t_philos *philo);
void					sleeping(t_philos *philo);
void					thinking(t_philos *philo);

/*
** check_param.c
*/

int						print_error(char *str);
int						check_param(t_table *table);

/*
** init.c
*/

int						table_init(t_table *table, char **av);
void					philo_init(t_philos *philos, int i, t_table *table);

/*
** libft_utils.c
*/

size_t					ft_strlen(const char *s);
char					*ft_itoa(long n);
char					*ft_strjoin(char *s1, char *s2, char *s3);
int						ft_atoi(const char *nptr);

/*
** utils.c
*/

int						open_semafore(t_table *table);
void					close_semafore(t_table *table);
void					ft_usleep(long sec);
long					get_current_time(void);

void					write_status(t_philos *philo, char *s3, int flag);

#endif
