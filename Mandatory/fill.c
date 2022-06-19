/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmardi <mmardi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 20:58:45 by mmardi            #+#    #+#             */
/*   Updated: 2022/05/20 17:03:22 by mmardi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	fill_args(t_data *data, char **av, int ac)
{
	data->ph_nb = ft_atoi(av[1]);
	data->t_die = ft_atoi(av[2]);
	data->t_eat = ft_atoi(av[3]);
	data->t_sleep = ft_atoi(av[4]);
	if (ac == 6)
		data->eat_nb = ft_atoi(av[5]);
	else
		data->eat_nb = -1;
}

void	fill_data(t_data *data)
{
	int	i;

	i = 0;
	data->philo = malloc(sizeof(t_ph) * data->ph_nb);
	data->forks = malloc(sizeof(pthread_mutex_t) * data->ph_nb);
	data->last_eat = malloc(sizeof(long long) * data->ph_nb);
	while (i < data->ph_nb)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		data->philo[i].number = i + 1;
		data->philo[i].data = data;
		data->philo[i].flag = 0;
		data->die = 0;
		i++;
	}
}
