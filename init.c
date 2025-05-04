/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fileonar <fileonar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 16:45:28 by fefo              #+#    #+#             */
/*   Updated: 2025/05/04 13:26:30 by fileonar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	init(t_state_data *s_data, int argc, char **argv)
{
	
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

static void	init_philo(t_state_data *sdata)
{
	int	i;

	i = 0;
	while (i < sdata->philo_count)
	{
		sdata->philo[i].id = i + 1;
		sdata->philo[i].meal_c = 0;
		sdata->philo[i].meal_complete = 0;
		sdata->philo[i].state = THINKING;
		sdata->philo[i].start = get_current_time();
		sdata->philo[i].last_eat = get_current_time();
		sdata->philo[i].sdata = sdata;
		printf("Philosopher %d is created\n", sdata->philo[i].id);
		i++;
	}
}