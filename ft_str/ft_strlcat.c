/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva <gsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 10:48:31 by gsilva            #+#    #+#             */
/*   Updated: 2022/12/06 13:14:09 by gsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	l;

	if (size == 0)
		return (ft_strlen((char *)src));
	i = ft_strlen(dst);
	j = i;
	if (i > size)
		j = size;
	l = j + ft_strlen((char *)src);
	if (size > i)
	{
		while (*src && i < size - 1)
		{
			dst[i] = *src;
			src++;
			i++;
		}
		dst[i] = 0;
	}
	return (l);
}
