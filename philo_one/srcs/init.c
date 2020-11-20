/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkathryn <fkathryn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 23:26:31 by fkathryn          #+#    #+#             */
/*   Updated: 2020/11/19 20:40:19 by fkathryn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_one.h"

void	philo_init(t_philos *philos, int i, t_table *table)
{
	philos->philo_id = i;
	philos->number_of_times_each_philosopher_must_eat =
		table->number_of_times_each_philosopher_must_eat;
	philos->table = table;
	philos->last_eat = table->start_time;
}

void	philos_and_forks_init(t_table *table, t_philos *philos)
{
	int i;

	i = 0;
	while (i < table->number_of_philos)
	{
		philo_init(&philos[i], i, table);
		pthread_mutex_init(&table->fork[i], NULL);
		i++;
	}
}

int		table_init(t_table *table, char **av)
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
	if (!(check_param(table)))
		return (print_error("check the parameters\n"));
	if (!(table->mutex_time = malloc(sizeof(pthread_mutex_t))))
		return (0);
	if (!(table->mutex_write = malloc(sizeof(pthread_mutex_t))))
		return (0);
	if (!(table->mutex_death = malloc(sizeof(pthread_mutex_t))))
		return (0);
	pthread_mutex_init(table->mutex_time, NULL);
	pthread_mutex_init(table->mutex_write, NULL);
	pthread_mutex_init(table->mutex_death, NULL);
	return (1);
}
