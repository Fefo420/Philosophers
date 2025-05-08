/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fefo <fefo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 18:39:54 by fefo              #+#    #+#             */
/*   Updated: 2025/05/09 00:04:03 by fefo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	sleeping(t_philo *philo)
{
	if (death_checker(philo->sdata))
		return (1);
	pthread_mutex_lock(&philo->sdata->mutex);
	philo->state = SLEEPING;
	pthread_mutex_unlock(&philo->sdata->mutex);
	philo_msg(philo);
	ft_usleep(philo->sdata->sleep_timer, philo->sdata);
	return (0);
}

int	thinking(t_philo *philo)
{
	long	tt_think;

	if (death_checker(philo->sdata))
		return (1);
	if (philo->sdata->counter_philos % 2)
	{
		tt_think = (philo->sdata->eat_timer * 2) - philo->sdata->sleep_timer;
		if (tt_think < 0)
			tt_think = 0;
		ft_usleep(tt_think, philo->sdata);
	}
	pthread_mutex_lock(&philo->sdata->mutex);
	philo->state = THINKING;
	pthread_mutex_unlock(&philo->sdata->mutex);
	philo_msg(philo);
	return (0);
}

static int	forking(t_philo *philo)
{
	if (death_checker(philo->sdata))
		return (1);
	pthread_mutex_lock(&philo->sdata->mutex);
	philo->state = FORKING;
	pthread_mutex_unlock(&philo->sdata->mutex);
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->r_fork);
		pthread_mutex_lock(philo->l_fork);
	}
	else
	{
		pthread_mutex_lock(philo->l_fork);
		pthread_mutex_lock(philo->r_fork);
	}
	philo_msg(philo);
	philo_msg(philo);
	return (0);
}

int	eating(t_philo *philo)
{
	if (forking(philo))
	{
		pthread_mutex_unlock(philo->l_fork);
		pthread_mutex_unlock(philo->r_fork);
		return (1);
	}
	if (death_checker(philo->sdata))
	{
		pthread_mutex_unlock(philo->l_fork);
		pthread_mutex_unlock(philo->r_fork);
		return (1);
	}
	pthread_mutex_lock(&philo->sdata->mutex);
	philo->state = EATING;
	pthread_mutex_unlock(&philo->sdata->mutex);
	pthread_mutex_lock(&philo->sdata->mutex_eating);
	philo->last_eat = get_current_time();
	philo->meal_c++;
	pthread_mutex_unlock(&philo->sdata->mutex_eating);
	philo_msg(philo);
	ft_usleep(philo->sdata->eat_timer, philo->sdata);
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
	return (0);
}

void	*philo(void *philo)
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