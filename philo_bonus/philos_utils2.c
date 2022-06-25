/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumni <mmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 17:15:56 by mmoumni           #+#    #+#             */
/*   Updated: 2022/06/25 08:55:49 by mmoumni          ###   ########.fr       */
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
