/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmorelli <lmorelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 12:42:37 by lmorelli          #+#    #+#             */
/*   Updated: 2023/08/07 17:45:30 by lmorelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo
{
	struct s_general	*general;
	pthread_t			t;
	pthread_mutex_t		*right_fork;
	pthread_mutex_t		*left_fork;
	u_int64_t			sleep_time;
	u_int64_t			death_time;
	u_int64_t			eat_time;
	int					position;
	int					eating_flag;
	int					meals_counter;
	int					max_meals;
	pthread_mutex_t		lock;
}	t_philo;

typedef struct s_general
{
	t_philo			*philos;
	pthread_t		*thread;
	int				philo_nb;
	int				meals_nb;
	int				dead_flag;
	int				full_belly;
	u_int64_t		time_to_eat;
	u_int64_t		time_to_sleep;
	u_int64_t		start_time;
	u_int64_t		time_to_die;
	pthread_mutex_t	*forks;
	pthread_mutex_t	output;
	pthread_mutex_t	lock;
}	t_general;

int			error(char *str, t_general *general);
int			ft_usleep(useconds_t time);
u_int64_t	get_time(void);
void		destroy_and_free(t_general *general);
int			ft_atoi(const char *str);
int			initialize(t_general *general, int ac, char **av);
void		output_message(char *s, t_philo *philo);
void		*actions(void *philo_ptr);
void		*max_portion(void *philo_ptr);
void		*monitoring(void *philo_ptr);

#endif