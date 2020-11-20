/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkathryn <fkathryn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 21:34:31 by fkathryn          #+#    #+#             */
/*   Updated: 2020/11/20 02:48:51 by fkathryn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_two.h"

void	write_status(t_philos *philo, char *s3, int flag)
{
	char *s1;
	char *s2;
	char *str;

	sem_wait(philo->table->sem_write);
	s1 = ft_itoa(get_current_time() - philo->table->start_time);
	s2 = ft_itoa(philo->philo_id + 1);
	str = ft_strjoin(s1, s2, s3);
	free(s1);
	free(s2);
	sem_wait(philo->table->sem_death);
	if (!philo->table->someone_died)
		write(1, str, ft_strlen(str));
	free(str);
	if (flag != 1)
		sem_post(philo->table->sem_death);
	sem_post(philo->table->sem_write);
}

void	*check_death(void *arg)
{
	t_philos *philo;

	philo = (t_philos *)arg;
	while (1)
	{
		sem_wait(philo->table->sem_time);
		if (get_current_time() - philo->last_eat > philo->table->time_to_die)
			break ;
		sem_post(philo->table->sem_time);
	}
	sem_post(philo->table->sem_time);
	if (philo->number_of_times_each_philosopher_must_eat)
	{
		write_status(philo, " died\n", 1);
		philo->table->someone_died = 1;
		sem_post(philo->table->sem_death);
	}
	sem_post(philo->table->sem_death);
	return (NULL);
}

void	*start_routine(void *arg)
{
	t_philos	*philo;
	pthread_t	thread_death;

	philo = (t_philos *)arg;
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
	pthread_join(thread_death, NULL);
	return (NULL);
}

void	start_simulation(t_table *table)
{
	t_philos	philos[table->number_of_philos];
	pthread_t	thread_philo[table->number_of_philos];
	int			i;

	i = 0;
	table->start_time = get_current_time();
	while (i < table->number_of_philos)
	{
		philo_init(&philos[i], i, table);
		pthread_create(&thread_philo[i], NULL,
							start_routine, &philos[i]);
		i++;
	}
	i = 0;
	while (i < table->number_of_philos)
		pthread_join(thread_philo[i++], NULL);
}

int		main(int ac, char **av)
{
	t_table table;

	if (ac != 5 && ac != 6)
		return (print_error("check the number of parameters\n"));
	if (!(table_init(&table, av)))
		return (0);
	start_simulation(&table);
	close_semafore(&table);
	return (0);
}
