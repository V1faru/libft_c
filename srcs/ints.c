/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ints.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurtone <amurtone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 15:20:31 by amurtone          #+#    #+#             */
/*   Updated: 2020/09/10 16:53:42 by amurtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		szandw(t_struct *stru, char c, char signc, int sign)
{
	if (stru->width > 0 && c == '0')
	{
		if (stru->space)
		{
			stru->printed += write(1, " ", 1);
			stru->space = 0;
		}
		if (signc != '\0')
			stru->printed += write(1, &signc, 1);
		sign -= sign;
	}
	return (sign);
}

void	ralignedint(t_struct *stru, int intlength, char *str, int sign)
{
	char	signc;
	char	c;

	if (stru->zero && !stru->precisdot)
		c = '0';
	else
		c = ' ';
	signc = '\0';
	if (sign == POSITIVE)
		signc = '+';
	else if (sign == NEGATIVE)
		signc = '-';
	sign = szandw(stru, c, signc, sign);
	while (stru->width-- > 0)
		stru->printed += write(1, &c, 1);
	if (stru->space != 0)
		stru->printed += write(1, " ", 1);
	if (sign != 0 && signc != '\0')
		stru->printed += write(1, &signc, 1);
	while (stru->precision-- > 0)
		stru->printed += write(1, "0", 1);
	stru->printed += write(1, str, intlength);
}

void	lalignedint(t_struct *stru, int intlength, char *str, int sign)
{
	if (stru->space)
		stru->printed += write(1, " ", 1);
	if (sign == POSITIVE)
		stru->printed += write(1, "+", 1);
	else if (sign == NEGATIVE)
		stru->printed += write(1, "-", 1);
	while (stru->precision > 0)
	{
		stru->printed += write(1, "0", 1);
		stru->precision--;
	}
	stru->printed += write(1, str, intlength);
	while (stru->width > 0)
	{
		stru->printed += write(1, " ", 1);
		stru->width--;
	}
}

void	formatint(intmax_t n, t_struct *stru, int sign)
{
	int		intlength;
	char	*str;

	if (stru->space && sign != 0)
		stru->space = 0;
	str = ft_itoa_base_upper(n, 10);
	intlength = signed_nbr_len(n, 10);
	if (n == 0)
		intlength = 1;
	if (stru->precisdot == 1 && stru->precision == 0 && n == 0)
		intlength = 0;
	if (stru->precisdot && stru->precision > intlength)
		stru->precision = stru->precision - intlength;
	else
		stru->precision = 0;
	if (sign != 0)
		stru->width = stru->width - (stru->precision
		+ intlength + 1 + stru->space);
	else
		stru->width = stru->width - (stru->precision + intlength + stru->space);
	if (stru->minus == 0)
		ralignedint(stru, intlength, str, sign);
	if (stru->minus == 1)
		lalignedint(stru, intlength, str, sign);
	free(str);
}

void	ifint(t_struct *stru, va_list ap, int sign, intmax_t n)
{
	if (stru->length == 0)
		n = (int)va_arg(ap, int);
	else if (stru->length == HH)
		n = (signed char)va_arg(ap, int);
	else if (stru->length == H)
		n = (short int)va_arg(ap, int);
	else if (stru->length == LL)
		n = (long long int)va_arg(ap, long long int);
	else if (stru->length == L)
		n = (long int)va_arg(ap, long int);
	if (stru->plus && n >= 0)
		sign = POSITIVE;
	else if (n < 0)
	{
		sign = NEGATIVE;
		n = n * -1;
	}
	if (n == LLONG_MIN)
	{
		stru->printed += write(1, "-9223372036854775808", 20);
		return ;
	}
	formatint(n, stru, sign);
}
