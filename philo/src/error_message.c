/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarrizo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 11:42:57 by lcarrizo          #+#    #+#             */
/*   Updated: 2024/09/04 14:09:58 by lcarrizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h" // IWYU pragma: keep

// print an error message. Return the error code.
int	print_error_message(int errnum)
{
	if (errnum == INV_N_ARG)
		printf("%sInvalid N parameters:\n%s%s", BC_RED, C_YELLOW, MS_INV_N_ARG);
	else if (errnum == INV_T_ARG)
		printf("%sInvalid T parameters:\n%s%s", BC_RED, C_YELLOW, MS_INV_T_ARG);
	return (errnum);
}

int	error_message(int errtype, int errnum)
{
	if (errtype == INIT_ERR)
		return (print_error_message(errnum));
	return (errnum);
}
