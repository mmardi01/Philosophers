/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmardi <mmardi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 15:48:04 by mmardi            #+#    #+#             */
/*   Updated: 2022/05/21 16:03:43 by mmardi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	think(t_ph *philo)
{
	current_status(philo, "is thinking\n", 1);
}

void	ft_error(void)
{
	write(2, "Error\n", 6);
}

void	ft_destroy(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->ph_nb)
		pthread_mutex_destroy(&data->forks[i++]);
}

int	ft_check_args(char **str)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (str[i])
	{
		if (ft_atoi(str[i]) <= 0)
		{
			ft_error();
			return (1);
		}
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac < 5 || ac > 6)
	{
		ft_error();
		return (1);
	}
	if (ft_check_args(av))
		return (1);
	fill_args(&data, av, ac);
	fill_data(&data);
	ft_philo(&data);
	ft_destroy(&data);
}
