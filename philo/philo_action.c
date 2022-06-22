/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumni <mmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 14:26:44 by mmoumni           #+#    #+#             */
/*   Updated: 2022/06/22 13:52:17 by mmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*simulation(void *philo_info)
{
	t_philo	*tmp_philo;

	tmp_philo = (t_philo *)philo_info;
	if (tmp_philo->philo_id & 1)
		usleep(500);
	while (1)
	{
		pthread_mutex_lock(&tmp_philo->rule->fork[(tmp_philo->philo_id - 1)]);
		print_state(tmp_philo, "has taken a fork", 0);
		pthread_mutex_lock(&tmp_philo->rule->fork[(tmp_philo->philo_id) % tmp_philo->rule->n]);
		print_state(tmp_philo, "has taken a fork", 0);
		eating(tmp_philo);
		pthread_mutex_unlock(&tmp_philo->rule->fork[(tmp_philo->philo_id) % tmp_philo->rule->n]);
		pthread_mutex_unlock(&tmp_philo->rule->fork[(tmp_philo->philo_id - 1)]);
		sleeping(tmp_philo);
		print_state(tmp_philo, "is thinking", 0);
	}
	return (NULL);
}

void	eating(t_philo *philo)
{
	if (philo->meals == 0)
		philo->rule->meals_count -= 1;
	philo->meals -= 1;
	print_state(philo, "is eating", 0);
	philo->last_eat = get_time_of_day();
	ft_usleep(philo->rule->time_to_eat);
}

void	sleeping(t_philo *philo)
{
	print_state(philo, "is sleeping", 0);
	ft_usleep(philo->rule->time_to_sleep);
}
