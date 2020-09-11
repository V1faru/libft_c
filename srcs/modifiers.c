/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifiers.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurtone <amurtone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 09:33:04 by amurtone          #+#    #+#             */
/*   Updated: 2020/09/10 16:53:50 by amurtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	flags(const char *fmt, t_struct *stru)
{
	while (ft_strchr("-+ #0", fmt[stru->i]))
	{
		if (fmt[stru->i] == '-')
			stru->minus = 1;
		if (fmt[stru->i] == '+')
			stru->plus = 1;
		if (fmt[stru->i] == ' ')
			stru->space = 1;
		if (fmt[stru->i] == '#')
			stru->hash = 1;
		if (fmt[stru->i] == '0')
			stru->zero = 1;
		stru->i++;
	}
	if (stru->plus == 1)
		stru->space = 0;
}

void	width(const char *fmt, t_struct *stru, va_list ap)
{
	ft_widthasterisk(fmt, stru, ap);
	if (fmt[stru->i] >= '0' && fmt[stru->i] <= '9')
	{
		stru->width = ft_atoi(&fmt[stru->i]);
		while (fmt[stru->i] >= '0' && fmt[stru->i] <= '9')
		{
			stru->i++;
			if (fmt[stru->i] == '*')
			{
				if (stru->width < 0)
				{
					stru->minus = 1;
					stru->width = -(stru->width);
				}
				while (fmt[stru->i] == '*')
					stru->i++;
			}
		}
	}
}

void	precision(const char *fmt, t_struct *stru, va_list ap, int p)
{
	int		i;

	i = stru->i;
	if (fmt[i] == '.')
	{
		i++;
		stru->precisdot = 1;
		if (fmt[i] >= '0' && fmt[i] <= '9')
		{
			stru->precision = ft_atoi(&fmt[i]);
			while (fmt[i] >= '0' && fmt[i] <= '9')
				i++;
		}
		else if (fmt[stru->i] == '*')
		{
			p = va_arg(ap, int);
			if (p >= 0)
				stru->precision = p;
			else if (p < 0)
				stru->precisdot = 0;
			while (fmt[stru->i] == '*')
				i++;
		}
	}
	stru->i = i;
}

void	length(const char *fmt, t_struct *stru, int i)
{
	i = stru->i;
	if (ft_strchr("hlLjz", fmt[i]))
	{
		if (fmt[i] == 'h')
		{
			if (fmt[i + 1] == 'h')
				stru->length = HH;
			else if (fmt[i - 1] != 'h')
				stru->length = H;
		}
		if (fmt[i] == 'l')
		{
			if (fmt[i + 1] == 'l')
				stru->length = LL;
			else if (fmt[i - 1] != 'l')
				stru->length = L;
		}
		if (fmt[i] == 'L')
			stru->length = BIGL;
	}
	while (ft_strchr("hlLjz", fmt[i]))
		i++;
	stru->i = i;
}

void	ft_modifiers(const char *fmt, t_struct *stru, va_list ap)
{
	flags(fmt, stru);
	width(fmt, stru, ap);
	precision(fmt, stru, ap, 0);
	length(fmt, stru, 0);
}
