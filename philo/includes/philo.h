/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarrizo <lcarrizo@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 21:26:44 by lcarrizo          #+#    #+#             */
/*   Updated: 2024/09/04 14:16:53 by lcarrizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "./errors.h"
# include <limits.h> 
# include <pthread.h> 
# include <stdio.h> 
# include <stdlib.h> 
# include <string.h> 
# include <sys/time.h> 
# include <unistd.h> 

// object philosopher
// object fork
// object table

long	ft_atol(const char *nbr);
int		is_numeric(char *str);
int		exit_philo(int status);

#endif
