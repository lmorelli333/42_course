/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmorelli <lmorelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 12:27:26 by lmorelli          #+#    #+#             */
/*   Updated: 2023/08/07 18:16:02 by lmorelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*max_portion(void *philo_ptr)
{
	t_philo	*philo;

	philo = (t_philo *) philo_ptr;
	while (philo->general->dead_flag == 0)
	{
		pthread_mutex_lock(&philo->lock);
		if (philo->general->full_belly >= philo->general->philo_nb)
			philo->general->dead_flag = 1;
		pthread_mutex_unlock(&philo->lock);
	}
	return (NULL);
}

static int	create_threads(t_general *general)
{
	int			i;
	pthread_t	thread;

	if (general->meals_nb > 0)
		if (pthread_create(&thread, NULL, &max_portion, &general->philos[0]))
			return (error("ERROR", general));
	i = -1;
	while (++i < general->philo_nb)
	{
		if (pthread_create(&general->thread[i], NULL,
				&actions, &general->philos[i]))
			return (error("ERROR", general));
		ft_usleep(1);
	}
	i = -1;
	while (++i < general->philo_nb)
		if (pthread_join(general->thread[i], NULL))
			return (error("ERROR", general));
	return (0);
}

static int	one_philo(t_general *general)
{
	general->start_time = get_time();
	if (pthread_create(&general->thread[0], NULL,
			&actions, &general->philos[0]))
		return (error("ERROR", general));
	pthread_detach(general->thread[0]);
	while (general->dead_flag == 0)
		ft_usleep(0);
	destroy_and_free(general);
	return (0);
}

static int	input_check(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] == ' ')
				j++;
			if ((av[i][j] < '0' || av[i][j] > '9'))
				return (error("ERROR", NULL));
			j++;
		}
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_general	general;

	if (ac < 5 || ac > 6)
		return (1);
	if (input_check(av))
		return (1);
	if (initialize(&general, ac, av))
		return (1);
	if (general.philo_nb == 1)
		return (one_philo(&general));
	if (create_threads(&general))
		return (1);
	destroy_and_free(&general);
	return (0);
}
