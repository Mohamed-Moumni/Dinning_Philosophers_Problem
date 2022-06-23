/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumni <mmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 17:15:56 by mmoumni           #+#    #+#             */
/*   Updated: 2022/06/21 12:00:11 by mmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_mutex(t_philo_rule *rules, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		pthread_mutex_destroy(&rules->fork[i]);
		i++;
	}
	pthread_mutex_destroy(&rules->print_mutex);
}

void	ft_usleep(long sleep)
{
	long	curtime;

	curtime = get_time_of_day();
	usleep(sleep * 0.9);
	while (get_time_of_day() - curtime < sleep)
		usleep(50);
}
