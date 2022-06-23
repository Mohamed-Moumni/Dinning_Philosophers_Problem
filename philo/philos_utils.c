/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumni <mmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 15:16:47 by mmoumni           #+#    #+#             */
/*   Updated: 2022/06/21 11:57:21 by mmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_time_of_day(void)
{
	struct timeval	tp;
	long			time_in_ms;

	gettimeofday(&tp, NULL);
	time_in_ms = tp.tv_sec * 1000 + tp.tv_usec / 1000;
	return (time_in_ms);
}

void	print_state(t_philo *philo, char *state, int condition)
{
	long	time;

	pthread_mutex_lock(&philo->rule->print_mutex);
	if (condition == 0)
	{
		time = get_time_of_day() - philo->rule->current_time;
		printf("%ld %d %s\n", time, philo->philo_id, state);
		pthread_mutex_unlock(&philo->rule->print_mutex);
	}
	if (condition == 1)
		printf("%ld %d %s\n", philo->rule->dead_time, philo->philo_id, state);
	if (condition == 2)
		printf("%s", state);
}

int	check_time(t_philo *philo)
{
	if (get_time_of_day() - philo->last_eat >= philo->rule->time_to_die)
	{
		philo->rule->dead_time = get_time_of_day() - philo->rule->current_time;
		philo->rule->philo_id = philo->philo_id;
		print_state(philo, "is died\n", 1);
		return (1);
	}
	if (philo->rule->meals_count == 0)
	{
		print_state(philo, "All philosphers ate\n", 2);
		return (1);
	}
	return (0);
}
