/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarrizo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 11:42:57 by lcarrizo          #+#    #+#             */
/*   Updated: 2024/09/03 14:39:21 by lcarrizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h" // IWYU pragma: keep

int	error_message(int errtype, int errnum)
{
	if (errtype == INIT_ERR)
		return (print_error_message(errnum));
	return (errnum);
}
