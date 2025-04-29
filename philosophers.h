/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fefo <fefo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 19:22:41 by fileonar          #+#    #+#             */
/*   Updated: 2025/04/29 08:52:07 by fefo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <limits.h>
# include <string.h>

//STRUCTS
typedef struct s_state_stuff
{
	int				counter_philos;
	long int		death_timer;
	long int		eat_timer;
	long int		sleep_timer;
	int				meal_counter;
	int				dead;
	int				error;
	int				meals;
}	t_state_data;

//PROTOTYPES


#endif