/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarrizo <lcarrizo@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 20:59:22 by lcarrizo          #+#    #+#             */
/*   Updated: 2024/09/02 14:43:55 by lcarrizo         ###    ###london.com    */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h" // IWYU pragma: keep

void	*comp(void *a)
{
	int	*num;

	num = (int *)a;
	printf("Hola desde el hilo, recibi el numero: %d\n", *num);
	return (NULL);
}

int	main(int argc, char *argv[])
{
	int			n;
	pthread_t	thread1;

	(void)argc;
	(void)argv;
	n = 42;
	if (pthread_create(&thread1, NULL, comp, &n) != 0)
	{
		perror("error muy loco");
		return (1);
	}
	if (pthread_join(thread1, NULL) != 0)
	{
		perror("error mas loco");
		return (2);
	}
	printf("Hilo terminado\n");
	return (EXIT_SUCCESS);
}
