/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwubneh <mwubneh@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:53:01 by mwubneh           #+#    #+#             */
/*   Updated: 2023/01/17 15:51:44 by mwubneh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdbool.h>

size_t	ft_putnbr(int64_t nbr)
{
	bool	is_neg;
	char	number_str[12];
	char	*cursor;

	if (nbr == 0)
		return (ft_print_str("0"));
	is_neg = nbr < 0;
	if (is_neg)
		nbr = -nbr;
	number_str[11] = '\0';
	cursor = number_str + 10;
	while (nbr != 0)
	{
		*cursor-- = nbr % 10 + '0';
		nbr /= 10;
	}
	if (is_neg)
		*cursor-- = '-';
	return (ft_print_str(cursor + 1));
}

#define SIZE 19

size_t	ft_putnbr_hexa(uintptr_t nbr, char *base)
{
	char	number_str[SIZE];
	char	*cursor;

	if (nbr == 0)
		return (ft_print_str("0"));
	number_str[SIZE - 1] = '\0';
	cursor = number_str + SIZE - 2;
	while (nbr != 0)
	{
		*cursor = base[nbr % 16];
		if (cursor > number_str)
			cursor--;
		nbr /= 16;
	}
	return (ft_print_str(cursor + 1));
}

int	ft_print_point(va_list arg)
{
	size_t	ft_putnbr_hexa_return;

	if (write(1, "0x", 2) == -1)
		return (-1);
	ft_putnbr_hexa_return = ft_putnbr_hexa((uintptr_t) va_arg(arg, void *),
			"0123456789abcdef");
	if (ft_putnbr_hexa_return == (size_t)-1)
		return (-1);
	return (ft_putnbr_hexa_return + 2);
}
