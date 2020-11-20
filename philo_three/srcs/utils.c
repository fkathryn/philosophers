/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkathryn <fkathryn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 16:23:19 by fkathryn          #+#    #+#             */
/*   Updated: 2020/11/20 21:44:25 by fkathryn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_three.h"

int		open_semafore(t_table *table)
{
	if ((table->sem_fork = sem_open("fork", O_CREAT, NULL,\
		table->number_of_philos)) == SEM_FAILED)
		return (0);
	if ((table->sem_time = sem_open("time", O_CREAT, NULL, 1)) == SEM_FAILED)
		return (0);
	if ((table->sem_write = sem_open("write", O_CREAT, NULL, 1)) == SEM_FAILED)
		return (0);
	if ((table->sem_death = sem_open("death", O_CREAT, NULL, 1)) == SEM_FAILED)
		return (0);
	// if ((table->sem_waiter = sem_open("waiter", O_CREAT, NULL,\
	// 	1)) == SEM_FAILED)
		// return (0);
	return (1);
}

void	ft_usleep(long sec)
{
	long fix_time;

	fix_time = get_current_time();
	while (get_current_time() - fix_time < sec)
		usleep(1);
}

void	close_semafore(t_table *table)
{
	sem_close(table->sem_time);
	sem_close(table->sem_write);
	sem_close(table->sem_death);
	// sem_close(table->sem_waiter);
	sem_close(table->sem_fork);
}

long	get_current_time(void)
{
	struct timeval	timeval;

	gettimeofday(&timeval, NULL);
	return ((timeval.tv_sec * 1000) + timeval.tv_usec * 0.001);
}
