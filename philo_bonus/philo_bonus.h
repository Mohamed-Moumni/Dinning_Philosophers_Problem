/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumni <mmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 23:21:35 by mmoumni           #+#    #+#             */
/*   Updated: 2022/06/25 09:45:07 by mmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include<stdio.h>
# include<unistd.h>
# include<stdlib.h>
# include<string.h>
# include<pthread.h>
# include<sys/time.h>
# include<semaphore.h>

# define MAX_INT 2147483647
# define MIN_INT -2147483648
# define MAX "2147483647"
# define MIN "2147483648"

typedef struct s_philosophers_rules
{
	sem_t			*sema;
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
	int				*pids;
}t_philo_rule;

typedef struct s_philosophers
{
	pthread_t					pth;
	int							philo_id;
	long						last_eat;
	int							meals;
	t_philo_rule				*rule;
}t_philo;

int		ft_strcmp(char *str1, char *str2);
int		checkcmp(char *num, int plus, int minus);
int		is_integer(char *num);
int		is_number(char *num);
int		check_number(char **num);
int		ft_atoi(const char *str);
void	ft_usleep(long sleep);
long	get_time_of_day(void);
void	print_state(t_philo *philo, char *state);
void	sleeping(t_philo *philo);
void	eating(t_philo *philo);
void	*simulation(void *data);
void    create_process(t_philo *philo, t_philo_rule *rules);
int		ft_strlen(char *str);
#endif
