/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarrizo <lcarrizo@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 18:23:51 by lcarrizo          #+#    #+#             */
/*   Updated: 2024/11/26 10:14:43 by lcarrizo         ###    ###london.com    */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h" // IWYU pragma: keep

/* Pre cheks the arguments given and coverts it on integers.
 * saves the integers in ar[] and return true if the format was successfull*/
int	format_args(char **argv, int argc, int ar[])
{
	int		i;
	long	temp;

	if (argc < MIN_ARGS || argc > MAX_ARGS)
		return (INV_N_ARG);
	i = 0;
	while (++i < argc)
	{
		if (is_numeric(argv[i]) == FALSE)
			return (INV_T_ARG);
		temp = ft_atol(argv[i]);
		if (temp >= 1 || temp <= INT_MAX)
			ar[i - 1] = (int)temp;
		else
			return (INV_T_ARG);
	}
	return (SUCCESS);
}

/*checks if the parameters on *ar are between the seted limits
 * return a error code if not and true if ok*/
int	check_args(int *ar, int argc)
{
	if (ar[NRO_PHILOS] > MAX_N_PHILOS || ar[NRO_PHILOS] < 1)
		return (INV_N_PHILO);
	else if ((ar[TIME_DIE] > MAX_MLSEC || ar[TIME_DIE] < 1)
		|| (ar[TIME_EAT] > MAX_MLSEC || ar[TIME_EAT] < 1)
		|| (ar[TIME_SLEEP] > MAX_MLSEC || ar[TIME_SLEEP] < 1))
		return (INV_TIME);
	if (argc == MAX_ARGS)
	{
		if (ar[N_MEALS] > MAX_N_MEALS || ar[4] < 1)
			return (INV_N_MEALS);
	}
	return (SUCCESS);
}

int	clean_exit(t_data *data, int exit_code)
{
	int	i;

	if (data->forks)
	{
		i = -1;
		while (++i < data->n_philos)
			pthread_mutex_destroy(&data->forks[i]);
		free(data->forks);
	}
	if (data->philos)
		free(data->philos);
	return (exit_code);
}

// obtein the current time on miliseconds
long	get_time_in_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}
