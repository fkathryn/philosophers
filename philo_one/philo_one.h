/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkathryn <fkathryn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 20:41:26 by fkathryn          #+#    #+#             */
/*   Updated: 2020/11/16 19:55:43 by fkathryn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_ONE_H
# define PHILO_ONE_H

# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct			s_table {
	int					number_of_philos;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					number_of_times_each_philosopher_must_eat;
	long				start_time;
	pthread_t			*thread_philos;
	pthread_mutex_t		*fork;
	pthread_mutex_t		*mutex_time;
	pthread_mutex_t		*mutex_write;
}						t_table;

typedef struct			s_philos {
	t_table				*table;
	int					die;
	int					philo_id;
	long				last_eat;
	int					number_of_times_each_philosopher_must_eat;
}						t_philos;

/*
** condition_philo.c
*/

void					sleeping(t_philos *philo);
void					thinking(t_philos *philo);
void					eating(t_philos *philo);

/*
** init.c
*/

void					table_init(t_table *table, char **av);
void					philos_and_forks_init(t_table *table, t_philos *philos);
void					philo_init(t_philos *philos, int i, t_table *table);

/*
** main.c
*/

void					write_status(t_philos *philo, char *s3);

/*
** utils.c
*/

long					get_current_time(void);
void					free_table(t_table *table);
void					ft_usleep(long sec);
int						another_fork(int fork_id, int philos);

/*
** utils_libft.c
*/

int						ft_atoi(const char *nptr);
char					*ft_strjoin(char *s1, char *s2, char *s3);
char					*ft_itoa(long n);
size_t					ft_strlen(const char *s);

#endif
