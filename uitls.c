/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uitls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fileonar <fileonar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 22:13:22 by fefo              #+#    #+#             */
/*   Updated: 2025/05/04 10:53:03 by fileonar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_atoi(const char *str)
{
	int		i;
	int		sgn;
	long	res;

	i = 0;
	sgn = 1;
	res = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || \
					str[i] == '\r' || str[i] == '\v' || str[i] == '\f')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sgn = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	return (res * sgn);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_isdigit(char *str)
{
	while (*str)
	{
		if (!(*str >= '0' && *str <= '9'))
			return (EXIT_FAILURE);
		str++;
	}
	return (EXIT_SUCCESS);
}

void	ft_usleep(size_t milliseconds, t_state_data *sdata)
{
	size_t	start;

	if (check_death(sdata))
		return ;
	start = get_current_time();
	usleep(milliseconds / 4 * 3);
	while ((get_current_time() - start < milliseconds))
		usleep(60);
}

size_t	get_current_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		write(2, "gettimeofday() error\n", 22);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}
