/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fefo <fefo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 22:03:45 by fileonar          #+#    #+#             */
/*   Updated: 2025/05/08 23:33:53 by fefo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
//SEND THIS TOMORROW
int		set_death(t_state_data *sdata, int i)
{
	long	now;

	pthread_mutex_lock(&sdata->mutex);
	pthread_mutex_lock(&sdata->mutex_eating);
	now = get_current_time();
	if (now - sdata->philos[i].last_eat >= sdata->death_timer
		&& sdata->philos[i].state != EATING)
	{
		pthread_mutex_lock(&sdata->mutex_dead);
		sdata->dead = 1;
		pthread_mutex_unlock(&sdata->mutex_dead);
		sdata->philos[i].state = DEAD;
		pthread_mutex_unlock(&sdata->mutex_eating);
		pthread_mutex_unlock(&sdata->mutex);
		pthread_mutex_lock(&sdata->msg);
		printf("%ld %d died\n", get_current_time() - sdata->philos[i].start,
			sdata->philos[i].id);
		pthread_mutex_unlock(&sdata->msg);
		return (1);
	}
	pthread_mutex_unlock(&sdata->mutex_eating);
	pthread_mutex_unlock(&sdata->mutex);
	return (0);

}

void	*philosophers_actions(void *philo)
{
	t_philo	*philo_data;

	philo_data = (t_philo *)philo;
	if (philo_data->id % 2)
		ft_usleep((philo_data->sdata->eat_timer / 2), philo_data->sdata);
	while (1)
	{
		if (eating(philo_data) || checker(philo_data))
			break ;
		if (sleeping(philo_data) || checker(philo_data))
			break ;
		if (thinking(philo_data) || checker(philo_data))
			break ;
	}
	return (NULL);
}