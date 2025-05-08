/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fefo <fefo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 19:22:41 by fileonar          #+#    #+#             */
/*   Updated: 2025/05/08 03:05:23 by fefo             ###   ########.fr       */
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

//ENUM
typedef enum e_state
{
	THINKING,
	EATING,
	SLEEPING,
	DEAD,
	FORKING,
}	t_state;

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
	t_philo			*philos;
	pthread_mutex_t	*forks;	
	pthread_mutex_t	msg;
	pthread_mutex_t	mutex;
	pthread_mutex_t	mutex_dead;
	pthread_mutex_t	mutex_eating;
	pthread_mutex_t	mutex_sleep;
}	t_state_data;



//PROTOTYPES

//INIT
void		init_state_data(t_state_data *s_data, int argc, char **argv);
int			init_thread(t_state_data *s_data, int argc, char **argv);
static void	init_philo(t_state_data *sdata);

//THREADS
int	create_threads(t_philo *philo_data, t_state_data *sdata);
int	threads_checker(t_philo *philo_data, t_state_data *sdata);

//UTILS
int		ft_atoi(const char *str);
int		ft_strlen(char *str);
int		ft_isdigit(char *str);
void	ft_usleep(size_t milliseconds, t_state_data *sdata);
size_t	get_current_time(void);
void	error_msg(char *msg);

//PHILOSOPHIZER
void	*philosophizer(void *philo);
#endif