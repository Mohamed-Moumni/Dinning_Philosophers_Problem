/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumni <mmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 08:53:58 by mmoumni           #+#    #+#             */
/*   Updated: 2022/06/27 19:13:09 by mmoumni          ###   ########.fr       */
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
		philo_list[i].meals = rules->nb_of_each_philo_must_eat;
	}
	return (philo_list);
}

int	ft_errors(t_philo **philo, t_philo_rule **ru, char **av)
{
	int	i;

	i = 0;
	(*ru) = pars_args(av[2], av[3], av[4], av[5]);
	if ((*ru) == NULL)
		return (1);
	(*ru)->n = ft_atoi(av[1]);
	(*philo) = philo_init(av[1], *ru);
	if ((*philo) == NULL)
	{
		free ((*ru));
		return (1);
	}
	sem_unlink("semaphore");
	(*ru)->sema = sem_open("semaphore", O_CREAT, 0777, (*ru)->n);
	if ((*ru)->sema == NULL)
		return (1);
	sem_unlink("print");
	(*ru)->print = sem_open("print", O_CREAT, 0777, 1);
	if ((*ru)->print == NULL)
		return (1);
	return (0);
}

void	create_process(t_philo *philo, t_philo_rule *rules)
{
	int	i;
	int	pid;

	i = 0;
	rules->pids = (int *)malloc(sizeof(int) * rules->n);
	rules->current_time = get_time_of_day();
	while (i < philo->rule->n)
	{
		pid = fork();
		if (pid == 0)
		{
			philo[i].last_eat = get_time_of_day();
			pthread_create(&philo[i].pth, NULL, simulation, &philo[i]);
			pthread_detach(philo[i].pth);
			while (1)
			{
				check_time(&philo[i]);
				usleep(100);
			}
		}
		else
			rules->pids[i] = pid;
		i++;
	}
	waiting_pids(rules);
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
	if (rules->n == 0)
		return (0);
	create_process(philo_list, rules);
	free_memory(philo_list, rules);
	return (0);
}
