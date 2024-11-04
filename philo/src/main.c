/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarrizo <lcarrizo@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 20:59:22 by lcarrizo          #+#    #+#             */
/*   Updated: 2024/10/17 15:26:13 by lcarrizo         ###    ###london.com    */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h" // IWYU pragma: keep

static int	allocate_entities(t_data *data, int *ar)
{
	int	i;

	memset(data, 0, sizeof(t_data));
	data->n_philos = ar[NRO_PHILOS];
	if (ar[N_MEALS])
		data->n_meals_to_eat = ar[N_MEALS];
	data->init_time = get_time_in_ms();
	data->philo = malloc(sizeof(t_philo) * ar[0]);
	if (!data->philo)
		return (SYS_ERROR);
	i = 0;
	while (i < ar[NRO_PHILOS])
	{
		memset(data->philo, 0, sizeof(t_philo));
		data->philo[i].id = i + 1;
		data->philo[i].time_to_die = ar[TIME_DIE];
		data->philo[i].time_to_eat = ar[TIME_EAT];
		data->philo[i].time_to_sleep = ar[TIME_SLEEP];
		if (ar[N_MEALS])
			data->philo[i].n_meals = ar[N_MEALS];
		i++;
	}
	return (SUCCESS);
}

static int	init_data(t_data *data, char **argv, int argc)
{
	int			args_ok;
	int			args_formated;
	static int	ar[MAX_ARGS - 1] = {0};

	args_formated = format_args(argv, argc, ar);
	if (args_formated != TRUE)
		return (args_formated);
	args_ok = check_args(ar, argc);
	if (args_ok != TRUE)
		return (args_ok);
	if (allocate_entities(data, ar) != SUCCESS)
		return (SYS_ERROR);
	return (SUCCESS);
}

int	main(int argc, char *argv[])
{
	int		init;
	t_data	data;

	init = init_data(&data, argv, argc);
	if (init != SUCCESS)
		return (error_message(INIT_ERR, init));
	printf("time is: %ld\n", data.init_time);
	/*while(mutexes)*/
	/*	free(mutexes);*/
	free(data.philo);
	/*free(forks);*/
	return (EXIT_SUCCESS);
}
