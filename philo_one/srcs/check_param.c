/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_param.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkathryn <fkathryn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 17:21:49 by fkathryn          #+#    #+#             */
/*   Updated: 2020/11/20 15:56:52 by fkathryn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_one.h"

int		print_error(char *str)
{
	write(1, str, ft_strlen(str));
	return (0);
}

int		check_param(t_table *table)
{
	if (table->number_of_philos <= 1)
		return (0);
	if (table->time_to_die <= 0)
		return (0);
	if (table->time_to_eat <= 0)
		return (0);
	if (table->time_to_sleep <= 0)
		return (0);
	if (table->number_of_times_each_philosopher_must_eat == 0)
		return (0);
	return (1);
}
