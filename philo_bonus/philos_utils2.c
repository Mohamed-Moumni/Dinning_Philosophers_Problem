/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumni <mmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 17:15:56 by mmoumni           #+#    #+#             */
/*   Updated: 2022/06/26 20:30:28 by mmoumni          ###   ########.fr       */
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
		print_state(philo, "is died");
		exit(EXIT_FAILURE);
	}
	if (philo->meals_check == 1)
	{
		exit (EXIT_SUCCESS);
	}
}

void	waiting_pids(t_philo_rule *rules)
{
	int	status;
	int	i;
	
	i = 0;
	waitpid(-1, &status, 0);
	if (WIFEXITED(status))
	{
		if (WEXITSTATUS(status) == EXIT_FAILURE)
			kill_pids(rules);
		else if (WEXITSTATUS(status) == EXIT_SUCCESS)
		{
			wait_sucess(rules);
		}
	}
}

void	wait_sucess(t_philo_rule *rules)
{
	int i;

	i = 0;
	while (i < rules->n)
	{
		waitpid(-1, NULL, 0);
		i++;
	}
}

void	kill_pids(t_philo_rule *rules)
{
	int	i;

	i = 0;
	while (i < rules->n)
	{
		kill(rules->pids[i], SIGKILL);
		i++;
	}
}
