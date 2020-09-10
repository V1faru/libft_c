/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurtone <amurtone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 04:46:32 by amurtone          #+#    #+#             */
/*   Updated: 2020/03/05 17:47:31 by amurtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

char	*ft_itoa_base_m(uintmax_t nbr, uintmax_t base)
{
	char				*str;
	unsigned long long	n;
	int					i;

	i = 1;
	n = nbr;
	while ((n /= base) >= 1)
		i++;
	if (!(str = (char *)malloc(sizeof(char) * (i + 1))))
		exit(1);
	str[i] = '\0';
	n = nbr;
	while (i-- > 0)
	{
		str[i] = (n % base < 10) ? n % base + '0' : n % base + 'a' - 10;
		n /= base;
	}
	return (str);
}

char	*ft_itoa_base_upper(intmax_t nbr, intmax_t base)
{
	char		*str;
	long long	n;
	int			sign;
	int			i;

	n = (nbr < 0) ? -nbr : nbr;
	sign = (nbr < 0 && base == 10) ? -1 : 0;
	i = (sign == -1) ? 2 : 1;
	while ((n /= base) >= 1)
		i++;
	if (!(str = (char *)malloc(sizeof(char) * (i + 1))))
		exit(1);
	str[i] = '\0';
	n = (nbr < 0) ? -nbr : nbr;
	while (i-- + sign)
	{
		str[i] = (n % base < 10) ? n % base + '0' : n % base + 'A' - 10;
		n /= base;
	}
	(i == 0) ? str[i] = '-' : 0;
	return (str);
}

char	findchar(t_struct *stru)
{
	char	c;

	if (stru->zero && !stru->precisdot)
		c = '0';
	else
		c = ' ';
	return (c);
}
