/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_parse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurtone <amurtone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 10:11:04 by amurtone          #+#    #+#             */
/*   Updated: 2020/09/10 16:53:13 by amurtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_fmtparse2(t_struct *stru, int i, const char *fmt, va_list ap)
{
	stru->i = i;
	if (!ft_strchr("cspdiouxXfb%", fmt[i]))
		ft_modifiers(fmt, stru, ap);
	else if (ft_strchr("cspdiouxXfb%", fmt[i]))
	{
		ft_conversions(fmt[i], stru, ap);
		reinitialize(stru);
	}
	return (stru->i - 1);
}

int		ft_fmtparse(const char *fmt, t_struct *stru, va_list ap, int i)
{
	while (fmt[i] != '\0')
	{
		if (fmt[i] != '%' && fmt[i])
			stru->printed += write(1, &fmt[i], 1);
		else if (fmt[i] == '%')
		{
			if (!ft_strchr(ALLSYMBOLS, fmt[i + 1]))
				break ;
			while (ft_strchr(ALLSYMBOLS, fmt[i + 1]))
			{
				i = i + 1;
				if (ft_strchr("cspdiouxXfb%", fmt[i]))
				{
					i = ft_fmtparse2(stru, i, fmt, ap) + 2;
					break ;
				}
				else
					i = ft_fmtparse2(stru, i, fmt, ap);
			}
			continue ;
		}
		i++;
	}
	return (stru->printed);
}
