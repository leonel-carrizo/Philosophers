/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarrizo <lcarrizo@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 21:26:44 by lcarrizo          #+#    #+#             */
/*   Updated: 2024/09/03 14:54:33 by lcarrizo         ###   ########.fr       */
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
int		ft_isnumeric(char *str);

#endif
