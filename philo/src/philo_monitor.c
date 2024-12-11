/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_monitor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarrizo <lcarrizo@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 11:34:49 by lcarrizo          #+#    #+#             */
/*   Updated: 2024/11/27 11:43:27 by lcarrizo         ###    ###london.com    */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"  // IWYU pragma: keep

void	*monitor_philos(void *arg)
{
	int		i;
	t_data	*data;

	data = (t_data *)arg;
	while (data->philo_died == 0)
	{
		i = -1;
		while (++i < data->n_philos)
		{
			if (!data->philos[i].is_eating
				&& get_time_in_ms() - data->philos[i].last_meal_time > data->time_to_die)
			{
				data->philo_died = 1;
				pthread_mutex_lock(&data->message);
				printf("Filosofo %d ha muerto\n", data->philos[i].id);
				pthread_mutex_unlock(&data->message);
				break ;
			}
		}
		usleep(1000);
	}
	return (NULL);
}
