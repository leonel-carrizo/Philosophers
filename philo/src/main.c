/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarrizo <lcarrizo@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 20:59:22 by lcarrizo          #+#    #+#             */
/*   Updated: 2024/09/03 14:54:21 by lcarrizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h" // IWYU pragma: keep

// close program, free memory if necessary
int	exit_philo(int status)
{
	if (status != SUCCESS)
		exit(status);
	exit(EXIT_SUCCESS);
}

// check arguments given
int	check_args(int argc, char *argv[])
{
	int		i;

	(void)argv;
	if (argc < 4 || argc > 5)
		exit_philo(print_error_message(INV_N_ARG));
	i = -1;
	while (argv[i])
	{
		if (ft_isnumeric(argv[i]) != FALSE)
			exit_philo(print_error_message(INV_T_ARG));
	}
	return (SUCCESS);
}

int	main(int argc, char *argv[])
{
	check_args(argc, argv);
	return (EXIT_SUCCESS);
}
