/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumni <mmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 15:16:47 by mmoumni           #+#    #+#             */
/*   Updated: 2022/06/27 19:02:24 by mmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

long	get_time_of_day(void)
{
	struct timeval	tp;
	long			time_in_ms;

	gettimeofday(&tp, NULL);
	time_in_ms = tp.tv_sec * 1000 + tp.tv_usec / 1000;
	return (time_in_ms);
}

void	print_state(t_philo *philo, char *state)
{
	long	time;

	sem_wait(philo->rule->print);
	time = get_time_of_day() - philo->rule->current_time;
	printf("%ld %d %s\n", time, philo->philo_id, state);
	if (ft_strcmp(state, "is died"))
		sem_post(philo->rule->print);
}

void	free_memory(t_philo *philo, t_philo_rule *rules)
{
	free(rules->pids);
	free(rules);
	free(philo);
}
