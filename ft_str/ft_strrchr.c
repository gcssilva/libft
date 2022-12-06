/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva <gsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 10:48:43 by gsilva            #+#    #+#             */
/*   Updated: 2022/12/06 13:14:42 by gsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	i = ft_strlen((char *)s);
	while ((unsigned char)s[i] != (unsigned char)c && i > 0)
		i--;
	if ((unsigned char)s[i] != (unsigned char)c)
		return (NULL);
	return ((char *)&s[i]);
}
