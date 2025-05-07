/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fileonar <fileonar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 22:09:49 by fileonar          #+#    #+#             */
/*   Updated: 2025/05/07 19:12:00 by fileonar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	threads_checker(t_philo *philo_data, t_state_data *sdata)
{
	int	i;
	int	stop;
	int	threads_made;

	i = 0;
	threads_made = 0;
	while (i < sdata->counter_philos)
	{
		philo_data = &sdata->philos[i];
		pthread_mutex_lock(&sdata->mutex_dead);
		if (stop)
			break ;
		if (pthread_create(&philo_data->thread, NULL,
				&sdata->philos, philo_data))
		{
			error_msg("Something went wrong with create threads...\n");
			break ;
		}
		threads_made++;
		i++;
	}
	return (threads_made);
}