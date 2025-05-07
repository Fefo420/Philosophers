/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fileonar <fileonar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 19:22:41 by fileonar          #+#    #+#             */
/*   Updated: 2025/05/07 18:10:02 by fileonar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

//LIBS
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <limits.h>
# include <stdbool.h>

# define FAST_SUCCESS 3

//STRUCTS

typedef struct s_philo
{
	int						id;
	int						meal_c;
	int						meal_complete;
	t_state					state;
	long int				start;
	long int				last_eat;
	struct s_state_stuff	*sdata;
	pthread_t				thread;
	pthread_mutex_t			*r_fork;
	pthread_mutex_t			*l_fork;
}	t_philo;

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
	t_philo			*philos;
}	t_state_data;

typedef enum e_state
{
	THINKING,
	EATING,
	SLEEPING,
	DEAD,
	FORKING,
}	t_state;

//PROTOTYPES


#endif