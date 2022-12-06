/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva <gsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 22:30:31 by gsilva            #+#    #+#             */
/*   Updated: 2022/12/06 13:17:24 by gsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_atoi(const char *str)
{
	long int	s;
	long int	nbr;

	s = 1;
	nbr = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			s = -s;
		str++;
	}
	while (*str >= 48 && *str <= 57)
	{
		nbr = nbr * 10 + (*str++ - 48);
		if (nbr > 2147483648)
		{
			if (s > 0)
				return (-1);
			return (0);
		}
	}
	return (nbr * s);
}
