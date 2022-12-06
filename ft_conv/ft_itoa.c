/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva <gsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 08:20:28 by gsilva            #+#    #+#             */
/*   Updated: 2022/12/06 13:17:31 by gsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static int	ft_nbrlen(long n)
{
	int		nbrlen;

	if (n == 0)
		return (1);
	nbrlen = 0;
	if (n < 0)
	{
		nbrlen += 1;
		n *= -1;
	}
	while (n > 0)
	{
		nbrlen += 1;
		n /= 10;
	}
	return (nbrlen);
}

char	*ft_itoa(int n)
{
	int		l;
	long	nbr;
	char	*itoa;

	nbr = n;
	if (n < 0)
		nbr *= -1;
	l = ft_nbrlen(n);
	itoa = (char *)malloc(l + 1);
	if (!itoa)
		return (NULL);
	if (n < 0)
		itoa[0] = '-';
	else if (n == 0)
		itoa[0] = 48;
	itoa [l] = 0;
	l -= 1;
	while (nbr > 0)
	{
		itoa[l--] = (nbr % 10) + 48;
		nbr /= 10;
	}
	return (itoa);
}
