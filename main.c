/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fefo <fefo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 19:21:43 by fileonar          #+#    #+#             */
/*   Updated: 2025/05/09 00:26:55 by fefo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	arguments_check(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
		return (error_msg("Invalid number of arguments..."), EXIT_FAILURE);
	if (argc == 6 && ft_atoi(argv[5]) < 1)
		return (EXIT_SUCCESS);
	while (--argc > 0)
	{
		if (ft_isdigit(argv[argc]) == EXIT_FAILURE)
			return (error_msg("Arguments must be integers..."), EXIT_FAILURE);
	}
	if (ft_atoi(argv[1]) < 1 || ft_atoi(argv[1]) > 200)
		return (EXIT_FAILURE);
	if (ft_atoi(argv[2]) < 60 || ft_atoi(argv[3]) < 60 || ft_atoi(argv[4]) < 60)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static int	philosophize(t_state_data *sdata)
{
	t_philo		*philo_sdata;
	pthread_t	monitor_thread;
	int			threads_made;
	int			i;

	i = 0;
	threads_made = 0;
	philo_sdata = sdata->philos;
	if (pthread_create(&monitor_thread, NULL, &routine_checker, sdata))
		return (error_msg("Something went wrong with monitoring thread...\n"),
			EXIT_FAILURE);
	threads_made = threads_maker(philo_sdata, sdata);
	while (i < threads_made)
	{
		philo_sdata = &sdata->philos[i];
		if (pthread_join(philo_sdata->thread, NULL))
			return (error_msg("Something went wrong with thread join...\n"),
				EXIT_FAILURE);
		i++;
	}
	if (pthread_join(monitor_thread, NULL))
		return (error_msg("Something went wrong with monitor thread\n"),
			EXIT_FAILURE);
	return (free_and_exit(sdata), EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	t_state_data	sdata;
	const int		arg_check_return = arguments_check(argc, argv);

	if (arg_check_return == EXIT_FAILURE)
		return (EXIT_FAILURE);
	else if (arg_check_return == FAST_SUCCESS)
		return (EXIT_SUCCESS);
	init_state_data(&sdata, argc, argv);
	if (init_thread(&sdata, argc, argv) == EXIT_FAILURE)
		return (error_msg("Something went wrong when initializing thread..."),
			EXIT_FAILURE);
	if (philosophize(&sdata))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
	return (0);
}
