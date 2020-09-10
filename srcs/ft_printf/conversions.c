/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurtone <amurtone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 09:53:19 by amurtone          #+#    #+#             */
/*   Updated: 2020/03/05 18:11:30 by amurtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void	ft_conversions(char c, t_struct *stru, va_list ap)
{
	if (c == 'c')
		ifchar(stru, ap);
	else if (c == 's')
		ifstring(stru, ap);
	else if (c == 'p')
		ifp(stru, ap, 2);
	else if (c == 'd' || c == 'i')
		ifint(stru, ap, 0, 0);
	else if (c == 'o')
		ifoctal(stru, ap);
	else if (c == 'u')
		ifudint(stru, ap);
	else if (c == 'x' || c == 'X')
		ifhex(stru, ap, c);
	else if (c == 'f')
		iffloat(stru, ap);
	else if (c == '%')
		ifpercent(stru);
	else if (c == 'b')
		ifbinary(stru, ap);
}
