/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva <gsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 16:29:06 by gsilva            #+#    #+#             */
/*   Updated: 2022/12/06 16:01:21 by gsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static char	*add_to_str(char *s1, char *s2);
static void	ft_strclean(char *dest, char *src);
static int	find_nl(char *str);
static int	nl_len(char *str);

char	*get_next_line(int fd)
{
	static char	next[BUFFER_SIZE + 1];
	char		*str;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	str = add_to_str(NULL, next);
	if (find_nl(next))
	{
		ft_strclean(next, &next[nl_len(next)]);
		return (str);
	}
	ft_strclean(next, &next[nl_len(next)]);
	while (read(fd, next, BUFFER_SIZE) > 0)
	{
		str = add_to_str(str, next);
		if (find_nl(next))
			break ;
		ft_strclean(next, &next[nl_len(next)]);
	}
	if (read(fd, next, 0) < 0)
		free(str);
	ft_strclean(next, &next[nl_len(next)]);
	return (str);
}

static char	*add_to_str(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	if (*s2 == 0)
		return (NULL);
	i = 0;
	str = (char *)malloc(nl_len(s1) + nl_len(s2) + 1);
	if (!str)
		return (NULL);
	while (s1 && s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2 && s2[j] && s2[j] != '\n')
		str[i++] = s2[j++];
	if (s2[j] == '\n')
		str[i++] = '\n';
	str[i] = 0;
	if (s1)
		free(s1);
	return (str);
}

static void	ft_strclean(char *dest, char *src)
{
	size_t			i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		src[i++] = 0;
	}
	while (dest[i])
		dest[i++] = 0;
}

static int	find_nl(char *str)
{
	int		i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		return (1);
	return (0);
}

static int	nl_len(char *str)
{
	int	i;

	if (!str || !*str)
		return (0);
	i = 1;
	while (str && str[i] && str[i - 1] != '\n')
		i++;
	return (i);
}
