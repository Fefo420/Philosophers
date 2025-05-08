/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fefo <fefo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 09:24:29 by fefo              #+#    #+#             */
/*   Updated: 2025/05/09 00:11:52 by fefo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	error_msg(char *msg)
{
	write(STDERR_FILENO, msg, ft_strlen(msg));
}

void	free_and_exit(t_state_data *sdata)
{
	int	i;

	i = 0;
	if (sdata->philos)
	{
		while (i < sdata->counter_philos)
		{
			pthread_mutex_destroy(&sdata->forks[i]);
			i++;
		}
		free(sdata->philos);
		sdata->philos = NULL;
	}
	if (sdata->forks)
	{
		free(sdata->forks);
		sdata->forks = NULL;
	}
	pthread_mutex_destroy(&sdata->mutex);
	pthread_mutex_destroy(&sdata->mutex_eating);
	pthread_mutex_destroy(&sdata->msg);
	pthread_mutex_destroy(&sdata->mutex_dead);
	pthread_mutex_destroy(&sdata->mutex_sleep);
}

void	philo_msg(t_philo *philo)
{
	if (death_checker(philo->sdata))
		return ;
	pthread_mutex_lock(&philo->sdata->msg);
	pthread_mutex_lock(&philo->sdata->mutex);
	if (philo->state == FORKING)
		printf("%ld %d has taken a fork\n", get_current_time() - philo->start,
			philo->id);
	else if (philo->state == EATING)
		printf("%ld %d is eating\n", get_current_time() - philo->start,
			philo->id);
	else if (philo->state == SLEEPING)
		printf("%ld %d is sleeping\n", get_current_time() - philo->start,
			philo->id);
	else if (philo->state == THINKING)
		printf("%ld %d is thinking\n", get_current_time() - philo->start,
			philo->id);
	pthread_mutex_unlock(&philo->sdata->msg);
	pthread_mutex_unlock(&philo->sdata->mutex);
}