/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmorelli <lmorelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 15:22:57 by lmorelli          #+#    #+#             */
/*   Updated: 2023/08/07 20:37:17 by lmorelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*(char *)s1 - *(char *)s2);
}

void	output_message(char *s, t_philo *philo)
{
	u_int64_t	time;

	pthread_mutex_lock(&philo->general->output);
	time = get_time() - philo->general->start_time;
	if (ft_strcmp("died", s) == 0 && philo->general->dead_flag == 0)
	{
		printf("%llu %d %s\n", time, philo->position, s);
		philo->general->dead_flag = 1;
	}
	if (philo->general->dead_flag == 0)
		printf("%llu %d %s\n", time, philo->position, s);
	pthread_mutex_unlock(&philo->general->output);
}

void	*monitoring(void *philo_ptr)
{
	t_philo	*philo;

	philo = (t_philo *) philo_ptr;
	while (philo->general->dead_flag == 0)
	{
		pthread_mutex_lock(&philo->lock);
		if (((get_time() - philo->eat_time) >= philo->death_time)
			&& philo->eating_flag == 0)
			output_message("died", philo);
		if (philo->meals_counter == philo->general->meals_nb)
		{
			pthread_mutex_lock(&philo->general->lock);
			philo->general->full_belly++;
			philo->meals_counter++;
			pthread_mutex_unlock(&philo->general->lock);
		}
		pthread_mutex_unlock(&philo->lock);
	}
	return (NULL);
}

static void	eat_sleep_think(t_philo *philo)
{
	pthread_mutex_lock(philo->right_fork);
	output_message("has taken a fork", philo);
	pthread_mutex_lock(philo->left_fork);
	output_message("has taken a fork", philo);
	pthread_mutex_lock(&philo->lock);
	philo->eating_flag = 1;
	philo->eat_time = get_time();
	output_message("is eating", philo);
	philo->meals_counter++;
	ft_usleep(philo->general->time_to_eat);
	philo->eating_flag = 0;
	pthread_mutex_unlock(&philo->lock);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
	output_message("is sleeping", philo);
	ft_usleep(philo->general->time_to_sleep);
	output_message("is thinking", philo);
}

void	*actions(void *philo_ptr)
{
	t_philo		*philo;

	philo = (t_philo *)philo_ptr;
	if (pthread_create(&philo->t, NULL, &monitoring, (void *)philo))
		return ((void *)1);
	while (philo->general->dead_flag == 0)
		eat_sleep_think(philo);
	if (pthread_join(philo->t, NULL))
		return ((void *)1);
	return (NULL);
}
