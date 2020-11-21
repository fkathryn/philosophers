/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkathryn <fkathryn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 16:20:30 by fkathryn          #+#    #+#             */
/*   Updated: 2020/11/21 18:23:15 by fkathryn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_three.h"

void		philo_init(t_philos *philos, int i, t_table *table)
{
	philos->philo_id = i;
	philos->number_of_times_each_philosopher_must_eat =
		table->number_of_times_each_philosopher_must_eat;
	philos->table = table;
	philos->last_eat = table->start_time;
}

static void	init_table_param(t_table *table, char **av)
{
	table->someone_died = 0;
	table->number_of_philos = ft_atoi(av[1]);
	table->time_to_die = ft_atoi(av[2]);
	table->time_to_eat = ft_atoi(av[3]);
	table->time_to_sleep = ft_atoi(av[4]);
	if (av[5])
		table->number_of_times_each_philosopher_must_eat = ft_atoi(av[5]);
	else
		table->number_of_times_each_philosopher_must_eat = -1;
}

int			table_init(t_table *table, char **av)
{
	sem_unlink("time");
	sem_unlink("write");
	sem_unlink("death");
	sem_unlink("philo_died");
	sem_unlink("fork");
	init_table_param(table, av);
	if (!(check_param(table)))
		return (print_error("check the parameters\n"));
	if (!(open_semafore(table)))
		return (0);
	return (1);
}
