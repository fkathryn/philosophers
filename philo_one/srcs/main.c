/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkathryn <fkathryn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 20:31:12 by fkathryn          #+#    #+#             */
/*   Updated: 2020/11/19 22:39:49 by fkathryn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_one.h"

void	write_status(t_philos *philo, char *s3, int flag)
{
	char *s1;
	char *s2;
	char *str;

	pthread_mutex_lock(philo->table->mutex_write);
	s1 = ft_itoa(get_current_time() - philo->table->start_time);
	s2 = ft_itoa(philo->philo_id + 1);
	str = ft_strjoin(s1, s2, s3);
	free(s1);
	free(s2);
	pthread_mutex_lock(philo->table->mutex_death);
	if (!philo->table->someone_died)
		write(1, str, ft_strlen(str));
	free(str);
	if (flag != 1)
		pthread_mutex_unlock(philo->table->mutex_death);
	pthread_mutex_unlock(philo->table->mutex_write);
}

void	*check_death(void *arg)
{
	t_philos	*philo;

	philo = (t_philos*)arg;
	while (1)
	{
		pthread_mutex_lock(philo->table->mutex_time);
		if (get_current_time() - philo->last_eat > philo->table->time_to_die)
			break ;
		pthread_mutex_unlock(philo->table->mutex_time);
	}
	pthread_mutex_unlock(philo->table->mutex_time);
	if (philo->number_of_times_each_philosopher_must_eat)
	{
		write_status(philo, " died\n", 1);
		philo->table->someone_died = 1;
		pthread_mutex_unlock(philo->table->mutex_death);
	}
	pthread_mutex_unlock(philo->table->mutex_death);
	return (NULL);
}

void	*start_routine(void *arg)
{
	t_philos	*philo;
	pthread_t	thread_death;

	philo = (t_philos*)arg;
	philo->last_eat = get_current_time();
	pthread_create(&thread_death, NULL, check_death, arg);
	while (philo->number_of_times_each_philosopher_must_eat)
	{
		if (philo->table->someone_died)
			break ;
		eating(philo);
		if (philo->table->someone_died)
			break ;
		sleeping(philo);
		if (philo->table->someone_died)
			break ;
		thinking(philo);
		philo->number_of_times_each_philosopher_must_eat--;
	}
	pthread_mutex_unlock(philo->table->mutex_death);
	pthread_join(thread_death, NULL);
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
		i++;
	}
	i = 0;
	while (i < table->number_of_philos)
		pthread_join(table->thread_philos[i++], NULL);
	free(philos);
}

int		main(int ac, char **av)
{
	t_table table;

	if (ac != 5 && ac != 6)
		return (print_error("check the number of parameters\n"));
	if (!(table_init(&table, av)))
		return (0);
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
