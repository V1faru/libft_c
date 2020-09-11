/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurtone <amurtone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 10:02:22 by amurtone          #+#    #+#             */
/*   Updated: 2020/09/10 16:57:16 by amurtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static char		convert(int i)
{
	char	*nbrs;

	nbrs = "0123456789abcdef";
	return (nbrs[i]);
}

char			*ft_itoa_base(unsigned int nbr, int base)
{
	char	c;
	char	*str;

	str = NULL;
	if (nbr >= (unsigned int)base)
		str = ft_itoa_base(nbr / base, base);
	c = convert(nbr % base);
	return (ft_stradd(str, c));
}

char			*ft_itoa_base_unsigned(size_t nbr, int base)
{
	char	c;
	char	*str;

	str = NULL;
	if (nbr >= (size_t)base)
		str = ft_itoa_base_unsigned(nbr / base, base);
	c = convert((nbr % base));
	return (ft_stradd(str, c));
}
