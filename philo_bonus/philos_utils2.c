/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumni <mmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 17:15:56 by mmoumni           #+#    #+#             */
/*   Updated: 2022/06/25 21:50:13 by mmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_usleep(long sleep)
{
	long	curtime;

	curtime = get_time_of_day();
	usleep(sleep * 0.9);
	while (get_time_of_day() - curtime < sleep)
		usleep(50);
}

void	check_time(t_philo *philo)
{
	if (get_time_of_day() - philo->last_eat >= philo->rule->time_to_die)
	{
		philo->rule->dead_time = get_time_of_day() - philo->rule->current_time;
		philo->rule->philo_id = philo->philo_id;
		print_state(philo, "is died\n");
		exit(EXIT_FAILURE);
	}
	if (philo->meals == 0)
		exit(EXIT_SUCCESS);
}
