/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurtone <amurtone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 13:14:30 by amurtone          #+#    #+#             */
/*   Updated: 2020/03/05 17:54:22 by amurtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int		hex_count(unsigned long long n)
{
	int		i;

	i = 0;
	while (n / 16)
	{
		n = n / 16;
		i++;
	}
	return (i);
}

int		ralignedp(int width, int precision, int hex, char *str)
{
	int		i;

	i = 0;
	while (width > 0)
	{
		i += write(1, " ", 1);
		width--;
	}
	i += write(1, "0x", 2);
	while (precision > 0)
	{
		i += write(1, "0", 1);
		precision--;
	}
	i += write(1, str, hex);
	return (i);
}

int		lalignedp(int width, int precision, int hex, char *str)
{
	int		i;

	i = 0;
	i += write(1, "0x", 2);
	while (precision > 0)
	{
		i += write(1, "0", 2);
		precision--;
	}
	i += write(1, str, hex);
	while (width > 0)
	{
		i += write(1, " ", 1);
		width--;
	}
	return (i);
}

void	ifp(t_struct *stru, va_list ap, int oxheading)
{
	int					hex;
	char				*str;
	int					precision;
	int					width;
	unsigned long long	pointer;

	pointer = (unsigned long long)va_arg(ap, void *);
	oxheading = 2;
	hex = hex_count(pointer) + 1;
	str = ft_itoa_base_m(pointer, 16);
	precision = stru->precision - hex;
	width = stru->width - hex - oxheading;
	if (stru->precisdot && stru->precision == 0)
		hex = 0;
	if (stru->minus)
		stru->printed = stru->printed + lalignedp(width, precision, hex, str);
	else
		stru->printed = stru->printed + ralignedp(width, precision, hex, str);
	free(str);
}
