/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva <gsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 14:42:19 by gsilva            #+#    #+#             */
/*   Updated: 2022/12/06 13:13:45 by gsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strchr(const char *str, int c)
{
	while (*str && (unsigned char)*str != (unsigned char)c)
		str++;
	if ((unsigned char)*str != (unsigned char)c)
		return (NULL);
	return ((char *)str);
}
