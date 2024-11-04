/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarrizo <lcarrizo@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 21:10:34 by lcarrizo          #+#    #+#             */
/*   Updated: 2024/09/12 14:38:43 by lcarrizo         ###    ###london.com    */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

# define USLEEP_MAX 4294967294
# define MAX_MLSEC 4294967
# define MAX_N_PHILOS 200
# define MAX_N_MEALS 1000
# define MAX_ARGS 6
# define MIN_ARGS 5

// MESAGE COLORS
# define C_DEFAULT "\033[0;39m"
# define C_BLACK "\033[0;30m"
# define C_RED "\033[0;31m"
# define C_GREEN "\033[0;32m"
# define C_YELLOW "\033[0;33m"
# define C_BLUE "\033[0;34m"
# define C_PURPLE "\033[0;35m"
# define C_CYAN "\033[0;36m"
# define C_WHITE "\033[0;37m"
// Bold colors
# define BC_BLACK "\033[1;30m"
# define BC_RED "\033[1;31m"
# define BC_GREEN "\033[1;32m"
# define BC_YELLOW "\033[1;33m"
# define BC_BLUE "\033[1;34m"
# define BC_PURPLE "\033[1;35m"
# define BC_CYAN "\033[1;36m"
# define BC_WHITE "\033[1;37m"

// TYPE BOOL
# define FALSE 0
# define TRUE 1

// TYPE STATUS
# define SUCCESS 1
# define FAIL 0
# define INIT_ERR 1
# define SYS_ERROR 5

// INIT PROGRAM ERRORS
# define INV_N_ARG 100
# define INV_T_ARG 101
# define INV_N_PHILO 102
# define INV_TIME 103
# define INV_N_MEALS 104

// SYSTEM ERROS
# define FAIL_MEM_ALLOC 141

// ERROR MESSAGES
# define MS_INV_N_ARG \
	"Usage: ./philo <number_of_philosopher> \
<time_to_die time_to_eat> <time_to_sleep> \
[number_of_times_each_philosopher_must_eat]\n"

# define MS_INV_T_ARG \
	"The parameters must be expressed in numbers.\n\
Usage: ./philo <number_of_philosopher>  <time_to_die time_to_eat> \
<time_to_sleep> [number_of_times_each_philosopher_must_eat]\n"

# define MS_INV_N_PHILO "The philosophers must be a number between 1 and "

# define MS_INV_TIME "The time must be a number between 1 and "

# define MS_INV_N_MEAL "The number of meals must be a number between 1 and "

# define MS_FAIL_ALLOC "Failure to allocate memory.\n"

#endif
