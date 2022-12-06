/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva <gsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 08:24:43 by gsilva            #+#    #+#             */
/*   Updated: 2022/12/06 13:11:59 by gsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static int	ft_wl(char *s, char c)
{
	int		i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static int	ft_wc(char *s, char c)
{
	int		v;
	int		wc;

	wc = 0;
	while (s && *s)
	{
		while (*s == c)
		{
			v = 0;
			s++;
		}
		while (*s && *s != c)
		{
			s++;
			v = 1;
		}
		if (v == 1)
			wc++;
	}
	return (wc);
}

static char	*ft_chrtrim(char *s, char c)
{
	while (*s == c)
		s++;
	return (s);
}

char	**ft_split(char const *s, char c)
{
	size_t	wc;
	size_t	wl;
	size_t	i;
	char	**split;

	if (!s)
		return (NULL);
	wc = ft_wc((char *)s, c);
	split = (char **)malloc(sizeof(char *) * (wc + 1));
	if (!split)
		return (NULL);
	i = 0;
	while (i < wc)
	{
		s = ft_chrtrim((char *)s, c);
		wl = ft_wl((char *)s, c);
		split[i] = ft_substr((char *)s, 0, wl);
		s = s + wl;
		i++;
	}
	split[i] = 0;
	return (split);
}
