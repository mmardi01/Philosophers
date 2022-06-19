/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmardi <mmardi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 16:39:45 by mmardi            #+#    #+#             */
/*   Updated: 2022/05/21 15:17:09 by mmardi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

#include"philo.h"

void	*rip(void *arg)
{
	int		i;
	t_ph	*philo;

	philo = (t_ph *)arg;
	while (1)
	{
		i = 0;
		while (i < philo->data->ph_nb)
		{
			if (philo[i].data->t_die <= \
			current_time() - philo[i].data->last_eat[i])
			{
				if (philo[i].flag != 1)
					current_status(&philo[i], "Died\n", 0);
				philo[i].data->die = 1;
				break ;
			}
			i++;
		}
		if (philo->data->die == 1)
			break ;
	}
	return (NULL);
}

void	timesleep(t_ph *philo)
{
	current_status(philo, "is sleeping\n", 1);
	ft_sleep(philo->data->t_sleep);
}

void	ft_eat(t_ph *philo)
{
	pthread_mutex_lock(&philo->data->forks[philo->number - 1]);
	current_status(philo, "has taken a fork\n", 1);
	pthread_mutex_lock(&philo->data->forks[philo->number % philo->data->ph_nb]);
	current_status(philo, "has taken a fork\n", 1);
	current_status(philo, "is eating\n", 1);
	philo->data->last_eat[philo->number - 1] = current_time();
	ft_sleep(philo->data->t_eat);
	pthread_mutex_unlock(&philo->data->forks[philo->number - 1]);
	pthread_mutex_unlock(&philo->data->forks[philo->number \
	% philo->data->ph_nb]);
}

void	*action(void *arg)
{
	t_ph	*philo;
	int		eat;

	philo = (t_ph *)arg;
	eat = 0;
	if (philo->number % 2)
		usleep(1000);
	while (1)
	{
		ft_eat(philo);
		eat++;
		if (philo->data->eat_nb != -1)
		{
			if (eat >= philo->data->eat_nb)
			{
				philo->flag = 1;
				break ;
			}
		}
		timesleep(philo);
		think(philo);
	}
	return (NULL);
}

void	ft_philo(t_data *data)
{
	int	i;
	int	*j;

	i = 0;
	data->current = current_time();
	j = 0;
	pthread_mutex_init(&data->mutex, NULL);
	while (i < data->ph_nb)
	{
		data->last_eat[i] = current_time();
		pthread_create(&data->philo[i].ph, NULL, &action, &data->philo[i]);
		i++;
	}
	rip(data->philo);
	i = 0;
	while (i < data->ph_nb && !data->die)
	{
		pthread_join(data->philo[i].ph, NULL);
		i++;
	}
}
