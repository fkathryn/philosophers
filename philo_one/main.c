/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkathryn <fkathryn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 20:31:12 by fkathryn          #+#    #+#             */
/*   Updated: 2020/11/16 02:25:53 by fkathryn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	write_status(t_philos *philo, char *s3)
{
	char *s1;
	char *s2;
	char *str;

	s1 = ft_itoa(get_current_time() - philo->table->start_time);
	s2 = ft_itoa(philo->init_id);
	str = ft_strjoin(s1, s2, s3);
	free(s1);
	free(s2);
	//pthread_mutex_lock
	write(1, str, ft_strlen(str));
}

void	*start_routine(void *arg)
{
	t_philos *philo;

	philo = (t_philos*)arg;
	while (philo->number_of_times_each_philosopher_must_eat != 0)
	{
		thinking(philo);
		sleeping(philo);
		philo->number_of_times_each_philosopher_must_eat--;
	}
	return (NULL);
}

void	start_simulation(t_table *table)
{
	t_philos	*philos;
	int			i;

	i = 0;
	if (!(philos = malloc(sizeof(t_philos) * (table->number_of_philos))))
		return ;
	table->start_time = get_current_time();
	philos_and_forks_init(table, philos);
	while (i < table->number_of_philos)
	{
		pthread_create(&table->thread_philos[i], NULL,
							start_routine, &philos[i]);
		++i;
	}
	i = 0;
	while (i < table->number_of_philos)
		pthread_join(table->thread_philos[i++], NULL);
	free(philos);
}

int		main(int ac, char **av)
{
	t_table table;

	if (ac != 5 && ac != 6)// prov param
		return (0);
	table_init(&table, av);
	if (!(table.thread_philos = malloc(sizeof(pthread_t)
								* (table.number_of_philos))))
		return (0);
	if (!(table.fork = malloc(sizeof(pthread_mutex_t)
								* (table.number_of_philos))))
		return (0);
	start_simulation(&table);
	free_table(&table);
	return (0);
}
