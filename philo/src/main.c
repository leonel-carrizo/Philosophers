/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarrizo <lcarrizo@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 20:59:22 by lcarrizo          #+#    #+#             */
/*   Updated: 2025/01/17 13:37:59 by lcarrizo         ###    ###london.com    */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h" // IWYU pragma: keep
#include <pthread.h>
#include <string.h>

int	init_threads(t_data *data, pthread_t **threads)
{
	int	i;

	*threads = (pthread_t *)malloc(sizeof(pthread_t) * data->n_philos);
	if (!*threads)
		return (SYS_ERROR);
	i = 0;
	while (i < data->n_philos)
	{
		if (pthread_create(&(*threads)[i], NULL, philo_actions,
			&data) != 0)
		{
			while (--i >= 0)
				pthread_join((*threads)[i], NULL);
			free(*threads);
			return (SYS_ERROR);
		}
		i++;
	}
	return (SUCCESS);
}

int	main(int argc, char *argv[])
{
	int			i;
	int			init;
	t_data		data;
	pthread_t	*philos_threads;
	pthread_t	monitor_thread;

	init = init_data(&data, argv, argc);
	if (init != SUCCESS)
		return (error_message(INIT_ERR, init));
	if (init_threads(&data, &philos_threads) != SUCCESS)
		return (clean_exit(&data, error_message(SYS_ERROR, FAIL_MEM_ALLOC)));
	if (pthread_create(&monitor_thread, NULL, monitor_philos, &data) != 0)
		return (clean_exit(&data, error_message(SYS_ERROR, FAIL_MEM_ALLOC)));
	i = -1;
	while (++i < data.n_philos)
		pthread_join(philos_threads[i], NULL);
	pthread_join(monitor_thread, NULL);
	free(philos_threads);
	return (clean_exit(&data, EXIT_SUCCESS));
}
