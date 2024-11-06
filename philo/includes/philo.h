/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarrizo <lcarrizo@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 21:26:44 by lcarrizo          #+#    #+#             */
/*   Updated: 2024/11/05 10:44:05 by lcarrizo         ###    ###london.com    */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "./errors.h"
# include <limits.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

# define NRO_PHILOS 0
# define TIME_DIE 1
# define TIME_EAT 2
# define TIME_SLEEP 3
# define N_MEALS 4

// object philosopher
typedef struct s_philo
{
	int				id;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				is_eating;
	int				n_meals;
	int				times_eaten;
	int				is_dead;
	int				fork_l;
	int				fork_r;
	long			last_meal_time;
}					t_philo;

// object program
typedef struct s_data
{
	int				n_philos;
	int				philo_died;
	int				n_meals_to_eat;
	long			init_time;
	pthread_mutex_t	message;
	t_philo			*philos;
}					t_data;

// functions
long				ft_atol(const char *nbr);
long				get_time_in_ms(void);
int					ft_atoi(const char *nptr);
int					format_args(char **argv, int argc, int ar[]);
int					is_numeric(char *str);
int					exit_philo(int status);
int					error_message(int errtype, int errnum);
int					check_args(int *ar, int argc);
void				*philo_actions(void *arg);
void				print_action(t_philo *philo, const char *action);

#endif
