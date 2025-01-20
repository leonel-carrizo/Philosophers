/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarrizo <lcarrizo@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 10:06:06 by lcarrizo          #+#    #+#             */
/*   Updated: 2025/01/17 12:52:13 by lcarrizo         ###    ###london.com    */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h" // IWYU pragma: keep

int	init_forks(t_data *data)
{
	int	i;

	data->forks = malloc(sizeof(pthread_mutex_t) * data->n_philos);
	if (!data->forks)
		return (SYS_ERROR);
	i = 0;
	while (i < data->n_philos)
	{
		if (pthread_mutex_init(&data->forks[i], NULL) != 0)
		{
			while (--i >= 0)
				pthread_mutex_destroy(&data->forks[i]);
			free(data->forks);
			return (SYS_ERROR);
		}
		i++;
	}
	return (SUCCESS);
}

static int	allocate_entities(t_data *data, int *ar)
{
	int	i;

	memset(data, 0, sizeof(t_data));
	data->n_philos = ar[NRO_PHILOS];
	data->init_time = get_time_in_ms();
	data->time_to_die = ar[TIME_DIE];
	data->time_to_eat = ar[TIME_EAT];
	data->time_to_sleep = ar[TIME_SLEEP];
	if (ar[N_MEALS])
		data->n_meals_to_eat = ar[N_MEALS];
	data->philos = malloc(sizeof(t_philo) * ar[NRO_PHILOS]);
	if (!data->philos)
		return (SYS_ERROR);
	i = 0;
	while (++i < ar[NRO_PHILOS])
	{
		memset(&data->philos[i], 0, sizeof(t_philo));
		data->philos[i].id = i;
	}
	return (SUCCESS);
}

int	init_data(t_data *data, char **argv, int argc)
{
	int			args_ok;
	int			args_formated;
	static int	ar[MAX_ARGS - 1] = {0};

	args_formated = format_args(argv, argc, ar);
	if (args_formated != SUCCESS)
		return (args_formated);
	args_ok = check_args(ar, argc);
	if (args_ok != SUCCESS)
		return (args_ok);
	if (allocate_entities(data, ar) != SUCCESS)
		return (SYS_ERROR);
	if (init_forks(data) != SUCCESS)
		return (SYS_ERROR);
	return (SUCCESS);
}
