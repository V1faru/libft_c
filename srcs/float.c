/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurtone <amurtone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 15:57:23 by amurtone          #+#    #+#             */
/*   Updated: 2020/09/10 16:52:55 by amurtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

long double		power(intmax_t n, int i)
{
	long			k;
	long double		res;

	res = n;
	k = 0;
	if (i == 0)
		return (1);
	while (k < i - 1)
	{
		res = res * n;
		k++;
	}
	return (res);
}

t_struct2		formatfloat3(t_struct2 fstru, t_struct *stru)
{
	if (fstru.fl == 0)
		fstru.zeros--;
	fstru.hash = 0;
	if (stru->hash)
		fstru.hash = 1;
	if (stru->hash && ft_strlen(fstru.s2) > 0)
		fstru.hash = 0;
	fstru.dot = 0;
	if ((ft_strlen(fstru.s2) > 0 && fstru.precision != 0) || stru->hash)
		fstru.dot = 1;
	if (fstru.precision != 0)
		fstru.padding = stru->width - stru->precision - fstru.beforedcmnbr
		- fstru.hash - fstru.signint - fstru.dot;
	else
		fstru.padding = stru->width - stru->precision - fstru.beforedcmnbr
		- fstru.hash - fstru.signint - fstru.dot - 1;
	fstru.zeros = fstru.zeros - fstru.precisionaddon;
	if (stru->minus == 0)
		ralignedfloat(stru, fstru);
	else if (stru->minus == 1)
		lalignedfloat(stru, fstru);
	return (fstru);
}

t_struct2		formatfloat2(t_struct2 fstru, t_struct *stru, long double n)
{
	if (stru->precisdot == 1 && stru->precision >= 0)
		fstru.precision = stru->precision;
	fstru.i = (long long)n;
	fstru.s1 = ft_itoa_base_m(fstru.i, 10);
	n = n - (long double)fstru.i;
	fstru.precisionaddon = 0;
	if (n == 0)
		fstru.precisionaddon = fstru.precision - 1;
	n = (n * power(10, fstru.precision));
	fstru.fl = (n >= 0) ? (long)(n + 0.5) : (long)(n - 0.5);
	if (fstru.fl == power(10, fstru.precision) && fstru.fl != 0)
	{
		fstru.s1 = ft_itoa_base_m(fstru.i + 1, 10);
		fstru.fl = 0;
		if (fstru.fl == 0)
			fstru.precisionaddon = fstru.precision - 1;
	}
	fstru.s2 = ft_itoa_base_m(fstru.fl, 10);
	if (fstru.precision != 0)
		fstru.zeros = fstru.precision - signed_nbr_len(fstru.fl, 10);
	else
		fstru.zeros = 0;
	fstru.beforedcmnbr = signed_nbr_len(n, 10);
	return (fstru);
}

void			formatfloat(long double n, t_struct *stru)
{
	t_struct2		fstru;

	fstru.signint = 0;
	if (stru->plus)
		fstru.signint = 1;
	fstru.sign = ' ';
	if (n < 0)
	{
		fstru.sign = '-';
		n = -n;
		fstru.signint = 1;
	}
	else if (n > 0 && stru->plus)
		fstru.sign = '+';
	fstru.precision = 6;
	if (stru->zero == 1)
		fstru.c = '0';
	else
		fstru.c = ' ';
	if (stru->minus)
		fstru.c = ' ';
	fstru = formatfloat2(fstru, stru, n);
	fstru = formatfloat3(fstru, stru);
	free(fstru.s1);
	free(fstru.s2);
}

void			iffloat(t_struct *stru, va_list ap)
{
	long double		n;

	n = 0;
	if (stru->length == 0)
		n = (long double)va_arg(ap, double);
	else if (stru->length == BIGL)
		n = (long double)va_arg(ap, long double);
	formatfloat(n, stru);
}
