/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumni <mmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 08:53:58 by mmoumni           #+#    #+#             */
/*   Updated: 2022/06/25 08:57:25 by mmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

t_philo_rule	*pars_args(char *t_die, char *t_eat, char *t_sleep, char *m_eat)
{
	t_philo_rule	*rule;
	int				nb_m_eat;

	nb_m_eat = -1;
	if (m_eat != NULL)
		nb_m_eat = ft_atoi(m_eat);
	rule = (t_philo_rule *)malloc(sizeof(t_philo_rule));
	if (!rule)
		return (NULL);
	rule->time_to_die = ft_atoi(t_die);
	rule->time_to_eat = ft_atoi(t_eat);
	rule->time_to_sleep = ft_atoi(t_sleep);
	rule->nb_of_each_philo_must_eat = nb_m_eat;
	rule->is_died = 0;
	return (rule);
}

int main(int ac, char **av)
{
    
}