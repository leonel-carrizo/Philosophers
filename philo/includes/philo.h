/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarrizo <lcarrizo@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 21:26:44 by lcarrizo          #+#    #+#             */
/*   Updated: 2024/11/07 14:54:13 by lcarrizo         ###    ###london.com    */
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
long				get_time_in_ms(void);
int					format_args(char **argv, int argc, int ar[]);
int					exit_philo(int status);
int					error_message(int errtype, int errnum);
int					check_args(int *ar, int argc);
void				*philo_actions(void *arg);
void				print_action(t_philo *philo, const char *action);

// strting utils
int					ft_atoi(const char *nptr);
int					is_numeric(char *str);
long				ft_atol(const char *nbr);
void				*ft_calloc(size_t nmemb, size_t size);

// times utils
void				print_time_from_ms(long ms);

#endif
