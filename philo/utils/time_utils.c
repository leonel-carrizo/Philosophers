/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarrizo <lcarrizo@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 14:41:30 by lcarrizo          #+#    #+#             */
/*   Updated: 2024/11/07 14:48:06 by lcarrizo         ###    ###london.com    */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/time.h>
#include <time.h>

// Función para convertir milisegundos a formato de fecha y hora legible
void	print_time_from_ms(long ms)
{
	char		buffer[80];
	time_t		seconds;
	struct tm	*timeinfo;

	seconds = ms / 1000;
	timeinfo = localtime(&seconds);
	strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", timeinfo);
	printf("Fecha y hora: %s\n", buffer);
}
