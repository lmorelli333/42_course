/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmorelli <lmorelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 12:02:16 by lmorelli          #+#    #+#             */
/*   Updated: 2023/07/26 20:53:28 by lmorelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	init_philos(t_general *general)
{
	int	i;

	i = 0;
	while (i < general->philo_nb)
	{
		general->philos[i].general = general;
		general->philos[i].death_time = general->time_to_die;
		general->philos[i].eat_time = general->start_time;
		general->philos[i].position = i + 1;
		general->philos[i].eating_flag = 0;
		general->philos[i].meals_counter = 0;
		general->philos[i].max_meals = general->meals_nb;
		pthread_mutex_init(&general->philos[i].lock, NULL);
		i++;
	}
}

static int	init_forks(t_general *general)
{
	int	i;

	i = -1;
	while (++i < general->philo_nb)
		pthread_mutex_init(&general->forks[i], NULL);
	general->philos[0].left_fork = &general->forks[0];
	general->philos[0].right_fork = &general->forks[general->philo_nb - 1];
	i = 0;
	while (++i < general->philo_nb)
	{
		general->philos[i].left_fork = &general->forks[i];
		general->philos[i].right_fork = &general->forks[i - 1];
	}
	return (0);
}

static int	init_general(t_general *general, int ac, char **av)
{
	general->philo_nb = (int) ft_atoi(av[1]);
	general->time_to_die = (u_int64_t) ft_atoi(av[2]);
	general->time_to_eat = (u_int64_t) ft_atoi(av[3]);
	general->time_to_sleep = (u_int64_t) ft_atoi(av[4]);
	general->meals_nb = -1;
	if (ac == 6)
		general->meals_nb = (int) ft_atoi(av[5]);
	if (general->philo_nb <= 0 || general->time_to_die < 0
		|| general->time_to_eat < 0 || general->time_to_sleep < 0)
		return (error("ERROR", NULL));
	general->start_time = get_time();
	general->full_belly = 0;
	general->dead_flag = 0;
	pthread_mutex_init(&general->lock, NULL);
	pthread_mutex_init(&general->output, NULL);
	return (0);
}

int	initialize(t_general *general, int ac, char **av)
{
	if (init_general(general, ac, av))
		return (1);
	general->thread = malloc(sizeof(pthread_t) * general->philo_nb);
	if (!general->thread)
		return (error("ERROR", general));
	general->philos = malloc(sizeof(t_philo) * general->philo_nb);
	if (!general->philos)
		return (error("ERROR", general));
	general->forks = malloc(sizeof(pthread_mutex_t) * general->philo_nb);
	if (!general->forks)
		return (error("ERROR", general));
	if (init_forks(general))
		return (1);
	init_philos(general);
	return (0);
}
