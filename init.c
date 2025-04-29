/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fefo <fefo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 16:45:28 by fefo              #+#    #+#             */
/*   Updated: 2025/04/29 08:52:26 by fefo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

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
