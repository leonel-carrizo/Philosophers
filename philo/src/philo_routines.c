/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarrizo <lcarrizo@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 08:45:36 by lcarrizo          #+#    #+#             */
/*   Updated: 2024/11/27 11:36:35 by lcarrizo         ###    ###london.com    */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h" // IWYU pragma: keep

void	print_action(t_philo *philo, const char *action)
{
	pthread_mutex_unlock(&philo->data->message);
	printf("Filosofo %d %s\n", philo->id, action);
	pthread_mutex_unlock(&philo->data->message);
}

void	philo_think(t_philo *philo)
{
	print_action(philo, "Esta comiendo");
}

void	philo_sleep(t_philo *philo)
{
	print_action(philo, "esta durmiendo");
	usleep(philo->data->time_to_eat * 1000);
}

void	philo_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->fork_left);
	print_action(philo, "Ha tomado el tenedor IZQUIERDO");
	pthread_mutex_lock(philo->fork_right);
	print_action(philo, "Ha tomado el tenedor DERECHO");
	philo->is_eating = 1;
	philo->last_meal_time = get_time_in_ms();
	usleep(philo->data->time_to_eat * 1000);
	philo->is_eating = 1;
	philo->times_eaten++;
	pthread_mutex_unlock(philo->fork_left);
	pthread_mutex_unlock(philo->fork_right);
}

// create routines: thinking, sleeping, eating.
void	*philo_actions(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (philo->data->philo_died == 0)
	{
		philo_think(philo);
		philo_eat(philo);
		philo_sleep(philo);
	}
	return (NULL);
}
