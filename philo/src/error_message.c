/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarrizo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 11:42:57 by lcarrizo          #+#    #+#             */
/*   Updated: 2024/09/12 14:34:40 by lcarrizo         ###    ###london.com    */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h" // IWYU pragma: keep

// print an error message. Return the error code.
static int	print_init_error(int errnum)
{
	if (errnum == INV_N_ARG)
		printf("%sInvalid parameters:\n%s%s", BC_RED, C_YELLOW, MS_INV_N_ARG);
	else if (errnum == INV_T_ARG)
		printf("%sInvalid parameters:\n%s%s", BC_RED, C_YELLOW, MS_INV_T_ARG);
	else if (errnum == INV_N_PHILO)
		printf("%sInvalid parameters:\n%s%s%d\n", BC_RED, C_YELLOW,
			MS_INV_N_PHILO, MAX_N_PHILOS);
	else if (errnum == INV_TIME)
		printf("%sInvalid parameters:\n%s%s%d\n", BC_RED, C_YELLOW, MS_INV_TIME,
			MAX_MLSEC);
	else if (errnum == INV_N_MEALS)
		printf("%sInvalid parameters:\n%s%s%d\n", BC_RED, C_YELLOW,
			MS_INV_N_MEAL, MAX_N_MEALS);
	else if (errnum == FAIL_MEM_ALLOC)
		printf("%sSystem Error:\n%s%s\n", BC_RED, C_YELLOW, MS_FAIL_ALLOC);
	return (errnum);
}

int	error_message(int errtype, int errnum)
{
	if (errtype == INIT_ERR)
		return (print_init_error(errnum));
	else if (errtype == SYS_ERROR)
		return (errnum);
	return (errnum);
}
