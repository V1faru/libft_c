/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurtone <amurtone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 14:57:22 by amurtone          #+#    #+#             */
/*   Updated: 2020/03/04 16:01:31 by amurtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int		ft_atoi(const char *str)
{
	int		sign;
	int		ans;
	int		len;

	ans = 0;
	sign = 1;
	len = 0;
	while (*str && (*str == '\t' || *str == '\f' || *str == '\r'
				|| *str == '\n' || *str == '\v' || *str == ' '))
		str++;
	sign = (*str == '-') ? -1 : 1;
	(*str == '-' || *str == '+') ? str++ : str;
	while (ft_isdigit(str[len]))
		len++;
	if (len > 19)
		return ((sign > 0) ? -1 : 0);
	while (*str && *str >= 48 && *str <= 57)
		ans = ans * 10 + (*str++ - '0');
	return (sign * ans);
}
