/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fefo <fefo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 16:45:28 by fefo              #+#    #+#             */
/*   Updated: 2025/05/08 03:04:47 by fefo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	init_philo(t_state_data *sdata)
{
	int	i;

	i = 0;
	while (i < sdata->counter_philos)
	{
		sdata->philos[i].id = i + 1;
		sdata->philos[i].meal_c = 0;
		sdata->philos[i].meal_complete = 0;
		sdata->philos[i].state = THINKING;
		sdata->philos[i].start = get_current_time();
		sdata->philos[i].last_eat = get_current_time();
		sdata->philos[i].sdata = sdata;
		sdata->philos[i].r_fork = &sdata->forks[sdata->philos[i].id - 1];
		if (sdata->philos[i].id == sdata->counter_philos)
			sdata->philos[i].l_fork = &sdata->forks[0];
		else
			sdata->philos[i].l_fork = &sdata->forks[sdata->philos[i].id];
		i++;
	}
}

//init the threads
int	init_thread(t_state_data *sdata, int argc, char **argv)
{
	sdata->philos = malloc(sizeof(t_philo) * sdata->counter_philos);
	if (!sdata->philos)
		return (EXIT_FAILURE);
	sdata->forks = malloc(sizeof(pthread_mutex_t) * sdata->counter_philos);
	if (!sdata->forks)
		return (free(sdata->philos), EXIT_FAILURE);
	if (init_mutex(sdata) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	init_philo(sdata);
	return (EXIT_SUCCESS);
}

//init the mutexes
static int	init_mutex(t_state_data *sdata)
{
	int	i;

	i = 0;
	while (i < sdata->counter_philos)
	{
		if (pthread_mutex_init(&(sdata->forks[i]), NULL))
			return (EXIT_FAILURE);
		i++;
	}
	if (pthread_mutex_init(&sdata->msg, NULL)
		|| pthread_mutex_init(&sdata->mutex, NULL)
		|| pthread_mutex_init(&sdata->mutex_eating, NULL)
		|| pthread_mutex_init(&sdata->mutex_sleep, NULL)
		|| pthread_mutex_init(&sdata->mutex_dead, NULL))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

//init the datas for the philos
void	init_state_data(t_state_data *s_data, int argc, char **argv)
{
	s_data->counter_philos = ft_atoi(argv[1]);
	s_data->death_timer = ft_atoi(argv[2]);
	s_data->eat_timer = ft_atoi(argv[3]);
	s_data->sleep_timer = ft_atoi(argv[4]);
	s_data->error = 0;
	s_data->dead = 0;
	s_data->meals = 0;
	if (argc == 6)
		s_data->meal_counter = ft_atoi(argv[5]);
	else
		s_data->meal_counter = -1;
}

