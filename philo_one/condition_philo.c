/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   condition_philo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkathryn <fkathryn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 02:25:03 by fkathryn          #+#    #+#             */
/*   Updated: 2020/11/16 02:25:25 by fkathryn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	sleeping(t_philos *philo)
{
	write_status(philo, " is sleeping\n");
	ft_usleep(philo->table->time_to_sleep);
}

void	thinking(t_philos *philo)
{
	write_status(philo, " is thinking\n");
}
