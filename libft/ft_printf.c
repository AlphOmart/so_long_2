/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwubneh <mwubneh@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 21:55:48 by mwubneh           #+#    #+#             */
/*   Updated: 2023/01/17 13:17:31 by mwubneh          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_cont(char c, va_list arg)
{
	if (c == 's')
		return (ft_print_str(va_arg(arg, char *)));
	if (c == '%')
		return (ft_print_char('%'));
	if (c == 'c')
		return (ft_print_char((char) va_arg(arg, int)));
	if (c == 'i' || c == 'd')
		return (ft_putnbr(va_arg(arg, int)));
	if (c == 'u')
		return (ft_putnbr(va_arg(arg, unsigned int)));
	if (c == 'p')
		return (ft_print_point(arg));
	if (c == 'x')
		return (ft_putnbr_hexa(va_arg(arg, unsigned int), "0123456789abcdef"));
	if (c == 'X')
		return (ft_putnbr_hexa(va_arg(arg, unsigned int), "0123456789ABCDEF"));
	return (0);
}

static int	val_format(char c)
{
	if (c == 'c' || c == '%' || c == 's' || c == 'i' || c == 'd'
		|| c == 'x' || c == 'X' || c == 'u' || c == 'p')
		return (1);
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int		len;
	int		len_cont;
	int		i;
	va_list	arg;

	i = 0;
	len = 0;
	va_start(arg, str);
	while (str[i])
	{
		if (str[i] == '%' && val_format(str[i + 1]))
		{
			len_cont = print_cont(str[i +1], arg);
			i++;
		}
		else
			len_cont = ft_print_char(str[i]);
		if (len_cont < 0)
			return (-1);
		else
			len += len_cont;
		i++;
	}
	va_end(arg);
	return (len);
}
