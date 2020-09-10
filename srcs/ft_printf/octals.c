/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   octals.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurtone <amurtone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 12:07:52 by amurtone          #+#    #+#             */
/*   Updated: 2020/03/05 17:46:44 by amurtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void	raligned_octal(t_struct *stru, int width, int octlen, char *str)
{
	char c;

	if (stru->zero && !stru->precisdot)
		c = '0';
	else
		c = ' ';
	while (width-- > 0)
		stru->printed += write(1, &c, 1);
	while (stru->precision-- > 0)
		stru->printed += write(1, "0", 1);
	if (stru->hash == 1)
		stru->printed += write(1, "0", 1);
	stru->printed += write(1, str, octlen);
}

void	laligned_octal(t_struct *stru, int width, int octlen, char *str)
{
	while (stru->precision-- > 0)
		stru->printed += write(1, "0 ", 1);
	if (stru->hash == 1)
		stru->printed += write(1, "0", 1);
	stru->printed += write(1, str, octlen);
	while (width-- > 0)
		stru->printed += write(1, " ", 1);
}

void	formatoctal(uintmax_t n, t_struct *stru)
{
	int		octlen;
	int		width;
	char	*str;

	str = ft_itoa_base_m(n, 8);
	octlen = unsigned_nbr_len(n, 8);
	if (n == 0)
	{
		octlen = 1;
		if (stru->hash == 1)
			octlen = 0;
		if (stru->precisdot && stru->precision == 0)
			octlen = 0;
	}
	if (stru->precisdot && stru->precision > octlen)
		stru->precision = stru->precision - octlen - stru->hash;
	else
		stru->precision = 0;
	width = stru->width - (stru->precision + octlen) - stru->hash;
	if (stru->minus == 0)
		raligned_octal(stru, width, octlen, str);
	else if (stru->minus == 1)
		laligned_octal(stru, width, octlen, str);
	free(str);
}

void	ifoctal(t_struct *stru, va_list ap)
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
	formatoctal(n, stru);
}
