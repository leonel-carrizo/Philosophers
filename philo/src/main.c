/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarrizo <lcarrizo@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 20:59:22 by lcarrizo          #+#    #+#             */
/*   Updated: 2024/09/04 14:17:55 by lcarrizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h" // IWYU pragma: keep

// check arguments given
int	check_args(int argc, char *argv[])
{
	int		i;

	(void)argv;
	if (argc < 5 || argc > 6)
		exit_philo(print_error_message(INV_N_ARG));
	i = 1;
	while (argv[++i])
	{
		if (is_numeric(argv[i]) == FALSE)
			exit_philo(print_error_message(INV_T_ARG));
	}
	return (SUCCESS);
}

int	main(int argc, char *argv[])
{
	check_args(argc, argv);
	return (EXIT_SUCCESS);
}
