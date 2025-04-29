/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fileonar <fileonar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 19:21:43 by fileonar          #+#    #+#             */
/*   Updated: 2025/03/04 19:26:32 by fileonar         ###   ########.fr       */
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
		if (ft_isdigit(argv[argc]) == EXIT_FAILURE)
			return (error_msg("Arguments must be integers..."), EXIT_FAILURE);
	if (ft_atoi(argv[1]) < 1 || ft_atoi(argv[1]) > 200)
		return (EXIT_FAILURE);
	if (ft_atoi(argv[2]) < 60 || ft_atoi(argv[3]) < 60 || ft_atoi(argv[4]) < 60)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	arguments_check(argc, argv);
	return (0);
}
