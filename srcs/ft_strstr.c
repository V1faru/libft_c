/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurtone <amurtone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 11:48:11 by amurtone          #+#    #+#             */
/*   Updated: 2020/09/10 16:57:16 by amurtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	char	*ptr;
	int		n_len;

	ptr = (char *)haystack;
	n_len = ft_strlen(needle);
	if (n_len == 0)
		return (ptr);
	while (*ptr)
	{
		if (*ptr == *needle)
		{
			if (ft_strncmp(needle, ptr, n_len) == 0)
				return (ptr);
		}
		ptr++;
	}
	return (NULL);
}
