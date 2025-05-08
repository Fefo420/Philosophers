/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fefo <fefo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 10:02:20 by fileonar          #+#    #+#             */
/*   Updated: 2025/05/08 02:57:37 by fefo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	time_checker(t_state_data *sdata)
{
	int		i;

	i = -1;
	if (check_death(sdata))
		return (1);
	while (++i < sdata->counter_philos)
	{
		if (set_death(sdata, i))
			return (1);
	}
	return (0);
}

void *death_checker(t_state_data *sdata)
{
	pthread_mutex_lock(&sdata->mutex_dead);
	if (sdata->dead)
	{
		pthread_mutex_unlock(&sdata->mutex_dead);
		return (1);
	}
	pthread_mutex_unlock(&sdata->mutex_dead);
	return (0);
}

void	*routine_checker(void *arg)
{
	t_state_data	*sdata;
	bool			stop;

	sdata = (t_state_data *)arg;
	stop = false;
	while (stop != true)
	{
		if (time_checker(sdata) || meal_checker(sdata) || death_checker(sdata))
			stop = true;
		usleep(500);
	}
	return (NULL);
}

int	meal_check(t_state_data *sdata)
{
	int	i;

	i = 0;
	if (sdata->meal_counter == -1)
		return (0);
	while (i < sdata->counter_philos)
	{
		pthread_mutex_lock(&sdata->mutex_eating);
		if (sdata->philos[i].meal_c >= sdata->meal_counter && \
				!sdata->philos[i].meal_complete)
		{
			sdata->meals++;
			sdata->philos[i].meal_complete = 1;
		}
		pthread_mutex_unlock(&sdata->mutex_eating);
		printf("Philosopher %d has eaten %d meals\n", \
			sdata->philos[i].id, sdata->philos[i].meal_c);
		i++;
	}
	return(0);
}
int	checker(t_philo *philo)
{
	if (time_checker(philo->sdata))
		return (1);
	if (meal_checker(philo->sdata))
		return (1);
	if (death_checker(philo->sdata))
		return (1);
	return (0);
}