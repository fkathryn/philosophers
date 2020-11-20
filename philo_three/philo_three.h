/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_three.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkathryn <fkathryn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 02:56:14 by fkathryn          #+#    #+#             */
/*   Updated: 2020/11/20 02:58:45 by fkathryn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_TWO_H
# define PHILO_TWO_H

# include <pthread.h>
# include <semaphore.h>
# include <sys/time.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

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
	sem_t				*sem_death;
	sem_t				*sem_waiter;
}						t_table;

typedef struct			s_philos {
	t_table				*table;
	int					philo_id;
	long				last_eat;
	int					number_of_times_each_philosopher_must_eat;
}						t_philos;

#endif