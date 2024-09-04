/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarrizo <lcarrizo@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 21:10:34 by lcarrizo          #+#    #+#             */
/*   Updated: 2024/09/04 14:14:56 by lcarrizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

int	error_message(int errtype, int errnum);
int	print_error_message(int errnum);

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
# define SYS_ERR 2

// INIT PROGRAM ERRORS
# define INV_N_ARG 100
# define INV_T_ARG 101

// ERROR MESSAGES
# define MS_INV_N_ARG "Usage: ./philo <number_of_philosopher>  <time_to_die time_to_eat> \
<time_to_sleep> [number_of_times_each_philosopher_must_eat]\n"
# define MS_INV_T_ARG "The parameters must be time expressed in numbers.\n\
Usage: ./philo <number_of_philosopher>  <time_to_die time_to_eat> \
<time_to_sleep> [number_of_times_each_philosopher_must_eat]\n"

#endif
