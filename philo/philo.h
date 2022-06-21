/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumni <mmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 23:21:35 by mmoumni           #+#    #+#             */
/*   Updated: 2022/06/21 11:50:26 by mmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include<stdio.h>
# include<unistd.h>
# include<stdlib.h>
# include<string.h>
# include<pthread.h>
# include<sys/time.h>

# define MAX_INT 2147483647
# define MIN_INT -2147483648
# define MAX "2147483647"
# define MIN "2147483648"

typedef struct s_philosophers_rules
{
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	*fork;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	int				nb_of_each_philo_must_eat;
	long			current_time;
	int				is_died;
	long			dead_time;
	int				philo_id;
	int				n;
	int				meals_count;
}t_philo_rule;

typedef struct s_philosophers
{
	pthread_t					pth;
	int							philo_id;
	long						last_eat;
	int							meals;
	t_philo_rule				*rule;
}t_philo;

long			get_time_of_day(void);
void			print_state(t_philo *philo_info, char *state, int condition);
int				ft_atoi(const char *str);
int				is_number(char *num);
int				args_errors(char **av);
int				ft_strlen(char *str);
t_philo_rule	*pars_args(char *t_die, char *t_eat, char *t_slep, char *m_et);
t_philo			*philo_init(char *nb_fphilo, t_philo_rule *rules);
void			ft_usleep(long sleep);
int				check_number(char **num);
int				is_number(char *num);
int				is_integer(char *num);
int				checkcmp(char *num, int plus, int minus);
int				ft_strcmp(char *str1, char *str2);
void			*simulation(void *philo_info);
void			eating(t_philo *philo);
void			sleeping(t_philo *philo);
void			create_threads(t_philo *philo, t_philo_rule *rule);
int				check_time(t_philo *phil);
int				check_must_eat(t_philo_rule *rule);
void			free_mutex(t_philo *philo, int n);
int				ft_errors(t_philo **philo, t_philo_rule **rules, char **av);
void			fork_init(t_philo *philo);
#endif
