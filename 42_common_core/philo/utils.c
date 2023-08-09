/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmorelli <lmorelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 11:50:37 by lmorelli          #+#    #+#             */
/*   Updated: 2023/08/07 18:18:35 by lmorelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	s;
	int	res;

	i = 0;
	s = 1;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			s *= -1;
		i++;
	}
	res = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10;
		res = res + str[i] - '0';
		i++;
	}
	return (res * s);
}

int	ft_usleep(useconds_t time)
{
	u_int64_t	start;

	start = get_time();
	while ((get_time() - start) < time)
		usleep(100);
	return (0);
}

u_int64_t	get_time(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
		return (error("gettimeofday() FAILURE\n", NULL));
	return ((tv.tv_sec * (u_int64_t)1000) + (tv.tv_usec / 1000));
}

int	error(char *str, t_general *general)
{
	printf("%s\n", str);
	if (general)
		destroy_and_free(general);
	return (1);
}

void	destroy_and_free(t_general *general)
{
	int	i;

	i = -1;
	while (++i < general->philo_nb)
	{
		pthread_mutex_destroy(&general->forks[i]);
		pthread_mutex_destroy(&general->philos[i].lock);
	}
	pthread_mutex_destroy(&general->output);
	pthread_mutex_destroy(&general->lock);
	if (general->thread)
		free(general->thread);
	if (general->forks)
		free(general->forks);
	if (general->philos)
		free(general->philos);
}
