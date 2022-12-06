/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva <gsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 10:46:43 by gsilva            #+#    #+#             */
/*   Updated: 2022/12/06 13:16:15 by gsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*a;

	if ((nmemb * size) / size != nmemb)
		return (NULL);
	a = (void *)malloc((nmemb * size));
	if (!a)
		return (NULL);
	ft_bzero(a, (nmemb * size));
	return (a);
}
