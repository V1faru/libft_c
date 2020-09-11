/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   udecint.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurtone <amurtone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 13:40:16 by amurtone          #+#    #+#             */
/*   Updated: 2020/09/10 16:54:29 by amurtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		rzeroandwidth(t_struct *stru, char c, int sign, char signc)
{
	if (stru->width > 0 && c == '0')
	{
		if (stru->space)
		{
			stru->printed += write(1, " ", 1);
			stru->space = 0;
		}
		if (sign != '\0')
			stru->printed += write(1, &signc, 1);
		sign -= sign;
	}
	return (sign);
}

void	raligneduint(t_struct *stru, int intlen, char *str, int sign)
{
	char	signc;
	char	c;

	c = findchar(stru);
	sign = 0;
	signc = '\0';
	if (stru->width > 0 && c == '0')
		sign = rzeroandwidth(stru, c, sign, signc);
	else if (stru->width <= 0 && signc != '\0')
	{
		stru->printed += write(1, &signc, 1);
		sign -= sign;
	}
	while (stru->width-- > 0)
		stru->printed += write(1, &c, 1);
	if (stru->space != 0)
		stru->printed += write(1, " ", 1);
	if (sign != 0 && signc != '\0')
		stru->printed += write(1, &signc, 1);
	while (stru->precision-- > 0)
		stru->printed += write(1, "0", 1);
	stru->printed += write(1, str, intlen);
}

void	laligneduint(t_struct *stru, int intlen, char *str, int sign)
{
	sign = 0;
	if (stru->space)
		stru->printed += write(1, " ", 1);
	if (sign == POSITIVE)
		stru->printed += write(1, "+", 1);
	else if (sign == NEGATIVE)
		stru->printed += write(1, "-", 1);
	while (stru->precision-- > 0)
		stru->printed += write(1, "0", 1);
	stru->printed += write(1, str, intlen);
	while (stru->width-- > 0)
		stru->printed += write(1, " ", 1);
}

void	formatuint(uintmax_t n, t_struct *stru, int sign)
{
	char	*str;
	int		intlen;

	if (stru->space && sign != 0)
		stru->space = 0;
	str = ft_itoa_base_m(n, 10);
	intlen = unsigned_nbr_len(n, 10);
	if (n == 0)
		intlen = 1;
	if (stru->precisdot && stru->precision == 0)
		intlen = 0;
	if (stru->precisdot && stru->precision > intlen)
		stru->precision = stru->precision - intlen;
	else
		stru->precision = 0;
	if (sign != 0)
		stru->width = stru->width - (stru->precision
		+ intlen + 1 + stru->space);
	else
		stru->width = stru->width - (stru->precision + intlen + stru->space);
	if (stru->minus == 0)
		raligneduint(stru, intlen, str, sign);
	else if (stru->minus == 1)
		laligneduint(stru, intlen, str, sign);
	free(str);
}

void	ifudint(t_struct *stru, va_list ap)
{
	uintmax_t	n;
	int			sign;

	sign = 0;
	n = 0;
	if (stru->space)
		stru->space = 0;
	if (stru->length == 0)
		n = (unsigned int)va_arg(ap, unsigned int);
	else if (stru->length == HH)
		n = (unsigned char)va_arg(ap, int);
	else if (stru->length == H)
		n = (unsigned short int)va_arg(ap, int);
	else if (stru->length == LL)
		n = (unsigned long long int)va_arg(ap, long long int);
	else if (stru->length == L)
		n = (unsigned long int)va_arg(ap, long int);
	if (stru->plus)
		sign = POSITIVE;
	formatuint(n, stru, sign);
}
