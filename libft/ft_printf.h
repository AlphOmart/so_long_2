/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwubneh <mwubneh@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 14:22:24 by mwubneh           #+#    #+#             */
/*   Updated: 2023/01/17 14:35:55 by mwubneh          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdint.h>

size_t		ft_putnbr(int64_t nbr);
int			ft_abs(int nbr);
size_t		ft_strlen(const char *str);
int			ft_print_point(va_list arg);
size_t		ft_print_str(const char *str);
int			ft_print_char(char c);
int			ft_printf(const char *str, ...);
size_t		ft_putnbr_hexa(uintptr_t nbr, char *base);

#endif
