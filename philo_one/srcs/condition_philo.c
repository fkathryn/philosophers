/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   condition_philo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkathryn <fkathryn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 02:25:03 by fkathryn          #+#    #+#             */
/*   Updated: 2020/11/20 00:50:08 by fkathryn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_one.h"

void	take_fork(t_philos *philo, int id1, int id2)
{
	pthread_mutex_lock(&philo->table->fork[id1]);
	write_status(philo, " has taken a fork\n", 0);
	pthread_mutex_lock(&philo->table->fork[id2]);
	write_status(philo, " has taken a fork\n", 0);
}

void	put_fork(t_philos *philo, int id1, int id2)
{
	pthread_mutex_unlock(&philo->table->fork[id2]);
	pthread_mutex_unlock(&philo->table->fork[id1]);
}

void	eating(t_philos *philo)
{
	int fork_id;

	fork_id = another_fork(philo->philo_id, philo->table->number_of_philos);
	if (philo->philo_id % 2 == 0)
		take_fork(philo, philo->philo_id, fork_id);
	else
		take_fork(philo, fork_id, philo->philo_id);
	write_status(philo, " is eating\n", 0);
	pthread_mutex_lock(philo->table->mutex_time);
	philo->last_eat = get_current_time();
	pthread_mutex_unlock(philo->table->mutex_time);
	ft_usleep(philo->table->time_to_eat);
	if (philo->philo_id % 2 == 0)
		put_fork(philo, philo->philo_id, fork_id);
	else
		put_fork(philo, fork_id, philo->philo_id);
}

void	sleeping(t_philos *philo)
{
	write_status(philo, " is sleeping\n", 0);
	ft_usleep(philo->table->time_to_sleep);
}

void	thinking(t_philos *philo)
{
	write_status(philo, " is thinking\n", 0);
}
