/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 14:36:45 by akremer           #+#    #+#             */
/*   Updated: 2019/10/20 22:20:34 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/get_next_line.h"

static int			full_line(char **scrap, char **line, int fd, int ret)
{
	char	*tmp;
	size_t	i;

	i = 0;
	while (scrap[fd][i] != '\n' && scrap[fd][i] != '\0')
		i++;
	if (scrap[fd][i] == '\n')
	{
		*line = ft_strndup(scrap[fd], i);
		tmp = ft_strdup(scrap[fd] + i + 1);
		free(scrap[fd]);
		scrap[fd] = tmp;
		if (scrap[fd][0] == '\0')
			ft_strdel(&scrap[fd]);
	}
	else if (scrap[fd][i] == '\0')
	{
		if (ret == BUFF_SIZE)
			return (get_next_line(fd, line));
		*line = ft_strdup(scrap[fd]);
		ft_strdel(&scrap[fd]);
	}
	return (1);
}

int					get_next_line(const int fd, char **line)
{
	static char	*scrap[4864];
	char		*buf;
	char		*tmp;
	int			ret;

	buf = ft_memalloc(BUFF_SIZE + 1);
	if (fd < 0 || fd > 4864 || line == NULL || BUFF_SIZE == 0)
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (scrap[fd] == NULL)
			scrap[fd] = ft_strnew(1);
		tmp = ft_strjoin(scrap[fd], buf);
		free(scrap[fd]);
		scrap[fd] = tmp;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	free(buf);
	if (ret < 0)
		return (-1);
	if (ret == 0 && (scrap[fd] == NULL || scrap[fd][0] == '\0'))
		return (0);
	return (full_line(scrap, line, fd, ret));
}
