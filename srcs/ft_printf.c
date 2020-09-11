/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurtone <amurtone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 13:21:31 by amurtone          #+#    #+#             */
/*   Updated: 2020/09/10 16:53:29 by amurtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	initialize(t_struct *stru)
{
	stru->i = 0;
	stru->printed = 0;
	stru->len = 0;
	stru->minus = 0;
	stru->plus = 0;
	stru->space = 0;
	stru->zero = 0;
	stru->hash = 0;
	stru->width = 0;
	stru->precisdot = 0;
	stru->precision = 0;
	stru->length = 0;
}

void	reinitialize(t_struct *stru)
{
	stru->len = 0;
	stru->minus = 0;
	stru->plus = 0;
	stru->space = 0;
	stru->zero = 0;
	stru->hash = 0;
	stru->width = 0;
	stru->precisdot = 0;
	stru->precision = 0;
	stru->length = 0;
}

int		ft_printf(const char *fmt, ...)
{
	va_list		ap;
	int			result;
	int			fmtlen;
	t_struct	*stru;

	fmtlen = ft_strlen(fmt);
	if (!(stru = (t_struct *)malloc(sizeof(t_struct))))
		exit(1);
	initialize(stru);
	stru->fmt = (char *)fmt;
	va_start(ap, fmt);
	if (!fmt[0])
	{
		ft_error();
		return (0);
	}
	if (fmtlen == 1 && fmt[0] == '%')
		return (0);
	else
		result = ft_fmtparse(fmt, stru, ap, 0);
	va_end(ap);
	free(stru);
	return (result);
}
