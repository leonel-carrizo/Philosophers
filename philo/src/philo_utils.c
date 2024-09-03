/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarrizo <lcarrizo@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 18:23:51 by lcarrizo          #+#    #+#             */
/*   Updated: 2024/09/03 14:47:58 by lcarrizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h" // IWYU pragma: keep

long	ft_atol(const char *nbr)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while (*nbr == ' ' || (*nbr >= 9 && *nbr <= 13))
		nbr++;
	if (*nbr == '-' || *nbr == '+')
		if (*nbr++ == '-')
			sign *= -1;
	while (*nbr >= '0' && *nbr <= '9')
	{
		result = result * 10 + (*nbr - '0');
		nbr++;
	}
	return (result * sign);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

/* Checks if the string given have just numbers, return 1 if true */
int	ft_isnumeric(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

// print an error message. Return the error code.
int	print_error_message(int errnum)
{
	if (errnum == INV_N_ARG)
		printf("%sInvalid parameters:\n%s%s", BC_RED, C_YELLOW, MS_INV_N_ARG);
	return (errnum);
}
