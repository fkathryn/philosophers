/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   condition_philo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkathryn <fkathryn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 16:21:56 by fkathryn          #+#    #+#             */
/*   Updated: 2020/11/20 21:45:30 by fkathryn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_three.h"

void	eating(t_philos *philo)
{
	sem_wait(philo->table->sem_fork);
	write_status(philo, " has taken a fork\n", 0);
	sem_post(philo->table->sem_fork);
	sem_wait(philo->table->sem_fork);
	write_status(philo, " has taken a fork\n", 0);
	sem_post(philo->table->sem_fork);
	write_status(philo, " is eating\n", 0);
	sem_wait(philo->table->sem_time);
	philo->last_eat = get_current_time();
	sem_post(philo->table->sem_time);
	ft_usleep(philo->table->time_to_eat);
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
