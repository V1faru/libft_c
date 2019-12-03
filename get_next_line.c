/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurtone <amurtone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 15:38:18 by amurtone          #+#    #+#             */
/*   Updated: 2019/12/03 15:08:58 by amurtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		get_line(char **str, char **line, const int fd)
{
	int		i;
	char	*tmp;

	i = 0;
	while (str[fd][i] != '\n' && str[fd][i] != '\0')
		i++;
	if (str[fd][i] == '\n')
	{
		if (!(*line = ft_strsub(str[fd], 0, i)))
			return (-1);
		if (!(tmp = ft_strdup(str[fd] + i + 1)))
			return (-1);
		free(str[fd]);
		str[fd] = tmp;
		if (str[fd][0] == '\0')
			ft_strdel(&str[fd]);
	}
	else
	{
		if (!(*line = ft_strdup(str[fd])))
			return (-1);
		ft_strdel(&str[fd]);
	}
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static char		*str[GNL_MAX_FD];
	char			*tmp;
	char			buf[GNL_BUFF_SIZE + 1];
	int				ret;

	if (fd < 0 || fd > GNL_MAX_FD || !line)
		return (-1);
	if (str[fd] == NULL)
		if (!(str[fd] = ft_strnew(0)))
			return (-1);
	while ((!ft_strchr(str[fd], '\n') && (ret = read(fd, buf, GNL_BUFF_SIZE)) > 0))
	{
		buf[ret] = '\0';
		if (!(tmp = ft_strjoin(str[fd], buf)))
			return (-1);
		free(str[fd]);
		str[fd] = tmp;
	}
	if (ret < 0)
		return (-1);
	else if (ret == 0 && (str[fd] == NULL || str[fd][0] == '\0'))
		return (0);
	return (get_line(str, line, fd));
}
