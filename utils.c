/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkathryn <fkathryn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 21:00:40 by fkathryn          #+#    #+#             */
/*   Updated: 2020/11/16 01:35:26 by fkathryn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	ft_usleep(long sec)
{
	long fix_time;

	fix_time = get_current_time();
	while (get_current_time() - fix_time < sec)
		usleep(1000);
}

void	free_table(t_table *table)
{
	free(table->mutex_time);
	free(table->mutex_write);
	free(table->thread_philos);
	free(table->fork);
}

long	get_current_time(void)
{
	struct timeval	timeval;

	gettimeofday(&timeval, NULL);
	return ((timeval.tv_sec * 1000) + timeval.tv_usec * 0.001);
}
