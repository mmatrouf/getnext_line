/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatrouf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/01 00:20:13 by mmatrouf          #+#    #+#             */
/*   Updated: 2019/06/17 19:23:48 by mmatrouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static	int		chrendl(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	return (i);
}

static	char	*ft_khwi(char *str, char *tmp)
{
	ft_strdel(&str);
	return (tmp);
}

int				get_next_line(const int fd, char **line)
{
	static char	*s[4864];
	char		buffer[BUFF_SIZE + (BUFF_SIZE > 0)];
	int			rd;
	int			i;

	i = 0;
	rd = 0;
	if (!line || fd < 0 || read(fd, buffer, 0) == -1)
		return (-1);
	!s[fd] ? s[fd] = ft_strnew(0) : 0;
	while (!ft_strchr(s[fd], '\n') && (rd = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[rd] = '\0';
		s[fd] = ft_khwi(s[fd], ft_strjoin(s[fd], buffer));
	}
	if (s[fd][0] == '\0' && rd == 0)
		return (0);
	i = chrendl(s[fd]);
	*line = ft_strsub(s[fd], 0, i);
	if (s[fd][i] == '\n')
		s[fd] = ft_khwi(s[fd], ft_strdup(s[fd] + i + 1));
	else
		s[fd] = ft_khwi(s[fd], ft_strdup(""));
	return (1);
}
