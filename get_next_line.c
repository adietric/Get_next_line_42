/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adietric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 14:17:09 by adietric          #+#    #+#             */
/*   Updated: 2018/11/26 14:18:49 by adietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int					trsf(char **str, char **line)
{
	char					*tmp;
	char					*n;

	if ((n = ft_strchr((const char*)*str, '\n')))
		*n = '\0';
	tmp = *str;
	if (!(*line = ft_strdup((const char*)*str)))
		return (0);
	if (n)
	{
		if (!(*str = ft_strdup((const char*)(n + 1))))
		{
			free(tmp);
			return (0);
		}
	}
	else
	{
		if (!(*str = ft_strnew(0)))
			return (0);
	}
	free(tmp);
	return (1);
}

static int					debut(char **str, const int fd)
{
	char					buf[BUFF_SIZE + 1];
	char					*tmp;
	int						ret;

	if (*str == NULL)
	{
		if (!(*str = ft_strnew(0)))
			return (0);
	}
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		tmp = *str;
		if (!(*str = ft_strjoin(*str, buf)))
			return (0);
		free(tmp);
		if ((ft_strchr(*str, '\n')) != NULL)
			return (1);
	}
	return (1);
}

int							get_next_line(const int fd, char **line)
{
	static char				*str = NULL;
	char					buftest[1];

	if (fd < 0 || BUFF_SIZE <= 0 || !line || (read(fd, buftest, 0) < 0))
		return (-1);
	*line = NULL;
	if (!(debut(&str, fd)))
		return (-1);
	if (str[0] == '\0')
		return (0);
	if (!(trsf(&str, line)))
		return (-1);
	return (1);
}
