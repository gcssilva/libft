/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva <gsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:10:01 by gsilva            #+#    #+#             */
/*   Updated: 2022/12/06 16:38:25 by gsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static int	ft_print_arg(char c, va_list arg);
static int	print_p(unsigned long n);

int	ft_printf(const char *s, ...)
{
	int		i;
	int		printed;
	va_list	arg;

	i = -1;
	printed = 0;
	va_start(arg, s);
	while (s[++i])
	{
		if (s[i] == '%')
			printed += ft_print_arg(s[++i], arg);
		else
		{
			ft_putchar_fd(s[i], 1);
			printed++;
		}
	}
	va_end(arg);
	return (printed);
}

static int	ft_print_arg(char c, va_list arg)
{
	if (c == 'c')
		return (ft_putchar_fd(va_arg(arg, int), 1));
	if (c == 's')
		return (ft_putstr_fd(va_arg(arg, char *), 1));
	else if (c == 'p')
		return (print_p(va_arg(arg, long int)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr_fd(va_arg(arg, int), 1));
	else if (c == 'u')
		return (ft_putnbr_base(va_arg(arg, unsigned int), "0123456789"));
	else if (c == 'x')
		return (ft_putnbr_base(va_arg(arg, unsigned int), "0123456789abcdef"));
	else if (c == 'X')
		return (ft_putnbr_base(va_arg(arg, unsigned int), "0123456789ABCDEF"));
	else
		return (ft_putchar_fd('%', 1));
}

static int	print_p(unsigned long n)
{
	int	printed;

	if (!n)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	ft_putstr_fd("0x", 1);
	printed = (ft_putnbr_base((n), "0123456789abcdef"));
	return (printed + 2);
}
