/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarrizo <lcarrizo@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 08:45:36 by lcarrizo          #+#    #+#             */
/*   Updated: 2025/01/17 13:39:49 by lcarrizo         ###    ###london.com    */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h" // IWYU pragma: keep

void	print_action(t_philo *philo, const char *action)
{
	pthread_mutex_unlock(&philo->data->message);
	printf("Philosopher %d %s\n", philo->id, action);
	pthread_mutex_unlock(&philo->data->message);
}

void	philo_think(t_philo *philo)
{
	print_action(philo, "Is eating");
}

void	philo_sleep(t_philo *philo)
{
	print_action(philo, "Is Sleeping");
	usleep(philo->data->time_to_eat * 1000);
}

void	philo_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->fork_left);
	print_action(philo, "Has taken the left fork");
	pthread_mutex_lock(philo->fork_right);
	print_action(philo, "Has taken the right fork");
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
	while (philo->is_dead == 0)
	{
		philo_think(philo);
		philo_eat(philo);
		philo_sleep(philo);
	}
	return (NULL);
}
