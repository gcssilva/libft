/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva <gsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 11:30:40 by gsilva            #+#    #+#             */
/*   Updated: 2022/12/06 16:48:56 by gsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_putstr_fd(char *s, int fd)
{
	int		i;

	i = -1;
	if (!s)
		return (ft_putstr_fd("(null)", 1));
	while (s && s[++i])
		ft_putchar_fd(s[i], fd);
	return (i);
}
