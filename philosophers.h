/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fefo <fefo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 19:22:41 by fileonar          #+#    #+#             */
/*   Updated: 2025/05/09 00:27:00 by fefo             ###   ########.fr       */
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

//INIT
void		init_state_data(t_state_data *s_data, int argc, char **argv);
int			init_thread(t_state_data *s_data, int argc, char **argv);

//THREADS
int			create_threads(t_philo *philo_data, t_state_data *sdata);
int			threads_maker(t_philo *philo_data, t_state_data *sdata);

//UTILS
int		ft_atoi(const char *str);
int		ft_strlen(char *str);
int		ft_isdigit(char *str);
void	ft_usleep(size_t milliseconds, t_state_data *sdata);
size_t	get_current_time(void);
void	ft_bzero(void *mem, size_t count);
void	*ft_calloc(size_t count, size_t size);

//PHILOSOPHIZER
void	*philosophers_actions(void *philo);
int		set_death(t_state_data *sdata, int i);

//CHECKERS
int 	death_checker(t_state_data *sdata);
int		meal_checker(t_state_data *sdata);
int		time_checker(t_state_data *sdata);
void	*routine_checker(void *arg);
int		checker(t_philo *philo);

//ERRORS
void	error_msg(char *msg);
void	free_and_exit(t_state_data *sdata);
void	philo_msg(t_philo *philo);

int	eating(t_philo *philo);
int	thinking(t_philo *philo);
int	sleeping(t_philo *philo);
void	*philo(void *philo);
#endif