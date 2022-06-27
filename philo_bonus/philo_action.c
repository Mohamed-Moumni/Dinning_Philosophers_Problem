/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumni <mmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 14:26:44 by mmoumni           #+#    #+#             */
/*   Updated: 2022/06/27 16:08:35 by mmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*simulation(void *data)
{
	t_philo	*phil;

	phil = (t_philo *)data;
	if (phil->philo_id & 1)
		usleep(500);
	while (1)
	{
		sem_wait(phil->rule->sema);
		print_state(phil, "has taken a fork");
		sem_wait(phil->rule->sema);
		print_state(phil, "has taken a fork");
		eating(phil);
		sem_post(phil->rule->sema);
		sem_post(phil->rule->sema);
		sleeping(phil);
		print_state(phil, "is thinking");
	}
	return (NULL);
}

void	eating(t_philo *philo)
{
	if (philo->meals == 0)
	{
		sem_post(philo->rule->sema);
		sem_post(philo->rule->sema);
		exit (EXIT_SUCCESS);
	}
	philo->meals -= 1;
	print_state(philo, "is eating");
	philo->last_eat = get_time_of_day();
	ft_usleep(philo->rule->time_to_eat);
}

void	sleeping(t_philo *philo)
{
	print_state (philo, "is sleeping");
	ft_usleep (philo->rule->time_to_sleep);
}
