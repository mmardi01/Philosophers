/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmardi <mmardi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 15:48:40 by mmardi            #+#    #+#             */
/*   Updated: 2022/05/21 16:06:29 by mmardi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include<pthread.h>
# include <sys/time.h>

typedef struct ph
{
	struct data		*data;
	pthread_t		ph;
	pthread_t		death;
	int				is_eat;
	int				sleeping;
	int				number;
	int				flag;
}t_ph;

typedef struct data
{
	t_ph			*philo;
	pthread_mutex_t	mutex;
	pthread_mutex_t	*forks;
	int				ph_nb;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				eat_nb;
	long long		*last_eat;
	long long		current;
	int				die;
}t_data;

int			ft_atoi(const char *str);
void		fill_args(t_data *data, char **av, int ac);
long long	current_time(void);
void		current_status(t_ph *philo, char *str, int i);
void		fill_data(t_data *data);
void		ft_philo(t_data *data);
void		ft_error(void);
void		ft_sleep(int time);
void		think(t_ph *philo);

#endif