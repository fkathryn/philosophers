/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkathryn <fkathryn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 02:55:55 by fkathryn          #+#    #+#             */
/*   Updated: 2020/11/21 18:40:17 by fkathryn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_three.h"

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
	if (flag != 1)
		sem_post(philo->table->sem_death);
	free(str);
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
		sem_wait(philo->table->sem_time);
		write_status(philo, " died\n", 1);
		philo->table->someone_died = 1;
		sem_post(philo->table->sem_philo_died);
	}
	sem_post(philo->table->sem_philo_died);
	return (NULL);
}

void	start_routine(t_philos *philo)
{
	pthread_t	thread_death;

	pthread_create(&thread_death, NULL, check_death, philo);
	philo->last_eat = get_current_time();
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
}

void	forks_create(t_table *table)
{
	pid_t		philo;
	int			philos[table->number_of_philos];
	t_philos	philosopher[table->number_of_philos];
	int			i;

	i = 0;
	sem_wait(table->sem_philo_died);
	table->start_time = get_current_time();
	while (i < table->number_of_philos)
	{
		philo = fork();
		if (philo == 0)
		{
			philo_init(&philosopher[i], i, table);
			start_routine(&philosopher[i]);
			exit(0);
		}
		else
			philos[i++] = philo;
	}
	sem_wait(table->sem_philo_died);
	i = 0;
	while (i < table->number_of_philos)
		kill(philos[i++], SIGKILL);
}

int		main(int ac, char **av)
{
	t_table table;

	if (ac != 5 && ac != 6)
		return (print_error("check the number of parameters\n"));
	if (!(table_init(&table, av)))
		return (0);
	forks_create(&table);
	close_semafore(&table);
	return (0);
}
