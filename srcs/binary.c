/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurtone <amurtone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 13:04:54 by amurtone          #+#    #+#             */
/*   Updated: 2020/09/10 16:52:30 by amurtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ralignedb(t_struct *stru, int widthb, int binarylen, char *str)
{
	char	c;

	if (stru->zero && !stru->precision)
		c = '0';
	else
		c = ' ';
	while (widthb-- > 0)
		stru->printed += write(1, &c, 1);
	while (stru->precision-- > 0)
		stru->printed += write(1, "0", 1);
	if (stru->hash == 1)
		stru->printed += write(1, "0", 1);
	stru->printed += write(1, str, binarylen);
}

void	lalignedb(t_struct *stru, int widthb, int binarylen, char *str)
{
	while (stru->precision-- > 0)
		stru->printed += write(1, "0", 1);
	if (stru->hash == 1)
		stru->printed += write(1, "0", 1);
	stru->printed += write(1, str, binarylen);
	while (widthb-- > 0)
		stru->printed += write(1, " ", 1);
}

void	formatbinary(uintmax_t n, t_struct *stru)
{
	int		binarylen;
	int		widthb;
	char	*str;

	str = ft_itoa_base_m(n, 2);
	binarylen = unsigned_nbr_len(n, 2);
	if (n == 0)
	{
		binarylen = 1;
		if (stru->hash == 1)
			binarylen = 0;
		if (stru->precisdot && stru->precision == 0)
			binarylen = 0;
	}
	if (stru->precisdot && stru->precision > binarylen)
		stru->precision = stru->precision - binarylen - stru->hash;
	else
		stru->precision = 0;
	widthb = stru->width - (stru->precision + binarylen) - stru->hash;
	if (stru->minus == 0)
		ralignedb(stru, widthb, binarylen, str);
	else if (stru->minus == 1)
		lalignedb(stru, widthb, binarylen, str);
	free(str);
}

void	ifbinary(t_struct *stru, va_list ap)
{
	unsigned long	n;

	n = 0;
	if (stru->length == 0)
		n = va_arg(ap, unsigned int);
	else if (stru->length == HH)
		n = (unsigned char)va_arg(ap, unsigned int);
	else if (stru->length == H)
		n = (unsigned int)va_arg(ap, unsigned int);
	else if (stru->length == LL)
		n = (unsigned long long)va_arg(ap, unsigned long long);
	else if (stru->length == L)
		n = (unsigned long)va_arg(ap, unsigned long);
	formatbinary(n, stru);
}
