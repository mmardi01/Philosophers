/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmardi <mmardi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 19:59:05 by mmardi            #+#    #+#             */
/*   Updated: 2022/05/20 15:31:54 by mmardi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	a;
	int	c;

	i = 0;
	a = 1;
	c = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			a = -a;
		i++;
	}
	while ('0' <= str[i] && str[i] <= '9')
	{
		c = c * 10 + (str[i] - '0');
		i++;
	}
	if (str[i] != '\0')
		return (0);
	return (a * c);
}

long long	current_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	current_status(t_ph *philo, char *str, int i)
{
	long long	time;

	pthread_mutex_lock(&philo->data->mutex);
	time = current_time() - philo->data->current;
	printf("%lld %d %s", time, philo->number, str);
	if (i)
		pthread_mutex_unlock(&philo->data->mutex);
}

void	ft_sleep(int time)
{
	long long	t;

	t = current_time();
	while (current_time() - t < time)
		usleep(1);
}
