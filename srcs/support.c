/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurtone <amurtone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 10:00:59 by amurtone          #+#    #+#             */
/*   Updated: 2020/09/10 16:54:16 by amurtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	writeblanks(int n)
{
	while (n > 0)
	{
		write(1, " ", 1);
		n--;
	}
}

void	writezeros(int n)
{
	while (n > 0)
	{
		write(1, "0", 1);
		n--;
	}
}

int		signed_nbr_len(intmax_t n, int base)
{
	int		len;

	len = 0;
	if (n < 0)
	{
		n = -n;
		len++;
	}
	while (n)
	{
		n = n / base;
		len++;
	}
	return (len);
}

int		unsigned_nbr_len(uintmax_t n, int base)
{
	int		len;

	len = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n = n / base;
		len++;
	}
	return (len);
}

void	ft_widthasterisk(const char *fmt, t_struct *stru, va_list ap)
{
	if (fmt[stru->i] == '*')
	{
		stru->width = va_arg(ap, int);
		if (stru->width < 0)
		{
			stru->minus = 1;
			stru->width = -(stru->width);
		}
		while (fmt[stru->i] == '*')
			stru->i++;
	}
}
