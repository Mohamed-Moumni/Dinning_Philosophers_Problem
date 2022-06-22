/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumni <mmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 12:34:45 by mmoumni           #+#    #+#             */
/*   Updated: 2022/06/22 13:52:06 by mmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

t_philo	*philo_init(char *nb_fphilo, t_philo_rule *rules)
{
	int		n;
	int		i;
	t_philo	*philo_list;

	i = -1;
	n = ft_atoi(nb_fphilo);
	philo_list = malloc(n * sizeof(t_philo));
	if (!philo_list)
		return (NULL);
	while (++i < n)
	{
		philo_list[i].philo_id = i + 1;
		philo_list[i].rule = rules;
		philo_list->meals = rules->nb_of_each_philo_must_eat;
	}
	return (philo_list);
}

void	create_threads(t_philo *philo, t_philo_rule *rule)
{
	int	i;

	i = 0;
	rule->current_time = get_time_of_day();
	while (i < philo->rule->n)
	{
		philo[i].last_eat = rule->current_time;
		if (pthread_create(&philo[i].pth, NULL, simulation, &philo[i]))
			return ;
		pthread_detach(philo[i].pth);
		i++;
	}
	i = 0;
	while (1)
	{
		if (get_time_of_day() - philo[i].last_eat >= philo[i].rule->time_to_die)
		{
			philo[i].rule->dead_time = get_time_of_day() - philo[i].rule->current_time;
			philo[i].rule->philo_id = philo[i].philo_id;
			print_state(&philo[i], "is died\n", 1);
			break ;
		}
		if (philo->rule->meals_count == 0)
		{
			print_state(philo, "All philosphers ate\n", 2);
			break ;
		}
		i++;
		if (i == (philo->rule->n))
			i = 0;
		usleep(100);
	}
}

int	ft_errors(t_philo **philo, t_philo_rule **rules, char **av)
{
	int i;

	i = 0;
	(*rules) = pars_args(av[2], av[3], av[4], av[5]);
	if (rules == NULL)
		return (1);
	(*rules)->n = ft_atoi(av[1]);
	(*rules)->fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * (*rules)->n);
	if ((*rules)->fork == NULL)
		return (1);
	while (i < (*rules)->n)
	{
		if (pthread_mutex_init(&(*rules)->fork[i], NULL))
			return (1);
		i++;
	}
	(*rules)->meals_count = ft_atoi(av[1]);
	(*philo) = philo_init(av[1], *rules);
	if (philo == NULL)
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	t_philo_rule	*rules;
	t_philo			*philo_list;

	rules = NULL;
	philo_list = NULL;
	if (ac < 5 || ac > 6 || check_number(&av[1]))
	{
		write(1, "Error!\n", 7);
		return (0);
	}
	if (ft_errors(&philo_list, &rules, av) != 0)
	{
		printf("Memory Allocation Error or Error in creation of thread\n");
		return (0);
	}
	
	pthread_mutex_init(&philo_list->rule->print_mutex, NULL);
	create_threads(philo_list, rules);
	// free_mutex(philo_list, rules->n);
	return (0);
}
