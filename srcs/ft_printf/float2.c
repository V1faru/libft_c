/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurtone <amurtone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 16:39:52 by amurtone          #+#    #+#             */
/*   Updated: 2020/03/05 18:00:48 by amurtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void	ralignedfloat3(t_struct *stru, t_struct2 fstru)
{
	if (fstru.dot == 1 || stru->hash)
		stru->printed += write(1, ".", 1);
	while (fstru.zeros > 0 && fstru.precision != 0)
	{
		stru->printed += write(1, "0", 1);
		fstru.zeros--;
		fstru.precision--;
	}
	while (*fstru.s2 && fstru.precision != 0)
	{
		stru->printed += write(1, fstru.s2, 1);
		fstru.s2++;
		fstru.precision--;
	}
	while (fstru.precisionaddon-- > 0)
		stru->printed += write(1, "0", 1);
}

void	ralignedfloat2(t_struct *stru, t_struct2 fstru, char space)
{
	if (stru->precision == 0 && stru->precisdot == 1)
		space = ' ';
	if (stru->precision == 0 && stru->zero == 0 && stru->width != 0)
		space = ' ';
	if (stru->space == 1)
	{
		stru->printed += write(1, &space, 1);
		fstru.padding--;
	}
	while (fstru.padding-- > 0)
		stru->printed += write(1, &fstru.c, 1);
	if (fstru.sign != 'a' && fstru.signint)
		if (fstru.signint == 1 && fstru.sign)
			stru->printed += write(1, &fstru.sign, 1);
	while (*fstru.s1)
	{
		stru->printed += write(1, fstru.s1, 1);
		fstru.s1++;
	}
}

void	ralignedfloat(t_struct *stru, t_struct2 fstru)
{
	char	space;

	space = '0';
	if (fstru.padding > 0 && fstru.c == '0')
	{
		if (fstru.signint == 1 && fstru.sign)
		{
			stru->printed += write(1, &fstru.sign, 1);
			fstru.sign = 'a';
			stru->space = 0;
		}
	}
	if (stru->space == 1 && (stru->zero == 0 || stru->precision))
		space = ' ';
	if (fstru.sign == '-' || stru->precision == 0)
	{
		if (stru->precision == 0 && stru->space)
			stru->space = 1;
		else
			stru->space = 0;
	}
	ralignedfloat2(stru, fstru, space);
	ralignedfloat3(stru, fstru);
}

void	lalignedfloat2(t_struct *stru, t_struct2 fstru)
{
	while (*fstru.s2 && fstru.precision != 0)
	{
		stru->printed += write(1, fstru.s2, 1);
		fstru.s2++;
		fstru.precision--;
	}
	if (stru->space && fstru.sign == '-' && fstru.precision > 0)
	{
		stru->printed += write(1, " ", 1);
		fstru.padding--;
		stru->space = 0;
	}
	while (fstru.precision-- > 0)
		stru->printed += write(1, "0", 1);
	while (fstru.padding-- > 0)
		stru->printed += write(1, &fstru.c, 1);
}

void	lalignedfloat(t_struct *stru, t_struct2 fstru)
{
	if (stru->space && fstru.sign != '-')
	{
		stru->printed += write(1, " ", 1);
		fstru.padding--;
		stru->space = 0;
	}
	if (fstru.signint == 1 && fstru.sign)
		stru->printed += write(1, &fstru.sign, 1);
	while (*fstru.s1)
	{
		stru->printed += write(1, fstru.s1, 1);
		fstru.s1++;
	}
	if (fstru.dot == 1 || stru->hash)
		stru->printed += write(1, ".", 1);
	while (fstru.zeros-- > 0 && fstru.precision-- != 0)
		stru->printed += write(1, "0", 1);
	lalignedfloat2(stru, fstru);
}
