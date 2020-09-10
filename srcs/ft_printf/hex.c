/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurtone <amurtone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 14:17:04 by amurtone          #+#    #+#             */
/*   Updated: 2020/03/05 17:57:37 by amurtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void	rhashzero(t_struct *stru, int hexlen, char *str, char x)
{
	char	c;

	c = findchar(stru);
	if (c == '0' && stru->hash == 2)
	{
		if (stru->hash == 2 && x == 'x')
			stru->printed += write(1, "0x", 2);
		else if (stru->hash == 2 && x == 'X')
			stru->printed += write(1, "0X", 2);
		while (stru->width-- > 0)
			stru->printed += write(1, &c, 1);
		while (stru->precision-- > 0)
			stru->printed += write(1, "0", 1);
		stru->printed += write(1, str, hexlen);
		return ;
	}
}

void	ralignedhex(t_struct *stru, int hexlen, char *str, char x)
{
	char	c;

	c = findchar(stru);
	if (c == '0' && stru->hash == 2)
	{
		rhashzero(stru, hexlen, str, x);
		return ;
	}
	while (stru->width-- > 0)
		stru->printed += write(1, &c, 1);
	if (stru->hash == 2 && x == 'x')
		stru->printed += write(1, "0x", 2);
	else if (stru->hash == 2 && x == 'X')
		stru->printed += write(1, "0X", 2);
	while (stru->precision-- > 0)
		stru->printed += write(1, "0", 1);
	stru->printed += write(1, str, hexlen);
	free(str);
}

void	lalignedhex(t_struct *stru, int hexlen, char *str, char x)
{
	if (stru->hash == 2 && x == 'x')
		stru->printed += write(1, "0x", 2);
	else if (stru->hash == 2 && x == 'X')
		stru->printed += write(1, "0X", 2);
	while (stru->precision-- > 0)
		stru->printed += write(1, "0", 1);
	stru->printed += write(1, str, hexlen);
	while (stru->width-- > 0)
		stru->printed += write(1, " ", 1);
	free(str);
}

void	formathex(uintmax_t n, t_struct *stru, char x, int hexlen)
{
	char	*str;

	if (x == 'x')
		str = ft_itoa_base_m(n, 16);
	else if (x == 'X')
		str = ft_itoa_base_upper(n, 16);
	if (stru->hash)
		stru->hash = 2;
	if (n == 0)
	{
		hexlen = 1;
		if (stru->hash == 2)
			stru->hash = 0;
		if (stru->precisdot && stru->precision == 0)
			hexlen = 0;
	}
	if (stru->precisdot && stru->precision > hexlen)
		stru->precision = stru->precision - hexlen;
	else
		stru->precision = 0;
	stru->width = stru->width - (stru->precision + hexlen) - stru->hash;
	if (stru->minus == 0)
		ralignedhex(stru, hexlen, str, x);
	else if (stru->minus == 1)
		lalignedhex(stru, hexlen, str, x);
}

void	ifhex(t_struct *stru, va_list ap, char x)
{
	uintmax_t	n;
	int			hexlen;

	n = 0;
	if (stru->length == 0)
		n = (unsigned int)va_arg(ap, unsigned int);
	else if (stru->length == HH)
		n = (unsigned char)va_arg(ap, int);
	else if (stru->length == H)
		n = (unsigned short)va_arg(ap, int);
	else if (stru->length == LL)
		n = (unsigned long long int)va_arg(ap, uintmax_t);
	else if (stru->length == L)
		n = (unsigned long int)va_arg(ap, uintmax_t);
	hexlen = unsigned_nbr_len(n, 16);
	formathex(n, stru, x, hexlen);
}
