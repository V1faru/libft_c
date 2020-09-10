/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurtone <amurtone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 13:36:03 by amurtone          #+#    #+#             */
/*   Updated: 2020/03/05 18:10:04 by amurtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void	ifpercent(t_struct *stru)
{
	int nbr;

	if (stru->width != 0 && stru->minus == 0)
	{
		nbr = stru->width - 1;
		if (stru->zero != 0)
			writezeros(nbr);
		else
			writeblanks(nbr);
		write(1, "%", 1);
		stru->printed = stru->printed + nbr + 1;
	}
	else if (stru->width && stru->minus == 1)
	{
		nbr = stru->width - 1;
		write(1, "%", 1);
		writeblanks(nbr);
		stru->printed = stru->printed + nbr + 1;
	}
	else
	{
		write(1, "%", 1);
		stru->printed++;
	}
}

void	ifchar(t_struct *stru, va_list ap)
{
	int				nbr;
	unsigned char	c;

	nbr = 0;
	c = (unsigned char)va_arg(ap, int);
	if (stru->width && stru->minus == 0)
	{
		nbr = stru->width - 1;
		if (stru->zero != 0)
			writezeros(nbr);
		else if (stru->zero == 0)
			writeblanks(nbr);
		write(1, &c, 1);
		stru->printed = stru->printed + nbr;
	}
	else if (stru->width && stru->minus == 1)
	{
		nbr = stru->width - 1;
		write(1, &c, 1);
		writeblanks(nbr);
		stru->printed = stru->printed + nbr;
	}
	else
		write(1, &c, 1);
	stru->printed++;
}
