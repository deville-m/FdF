/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 13:39:11 by mdeville          #+#    #+#             */
/*   Updated: 2018/03/05 20:04:07 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "ft_printf.h"
#include "conversion.h"
#include "ft_string.h"
#include "fdf.h"
#include "dlst.h"
#include "get_next_line.h"

static void		free_line(void *data, size_t content_size)
{
	(void)content_size;
	free(data);
}

static int		*parse_split(char **split, int size, int max)
{
	int		i;
	int		*res;

	if (!(res = (int *)malloc(sizeof(int) * size)))
	{
		del_tab((void **)split);
		return (NULL);
	}
	i = 0;
	while (i < size && split[i])
	{
		res[i] = ft_atoi(split[i]);
		++i;
	}
	del_tab((void **)split);
	if (i != max)
	{
		free(res);
		return (NULL);
	}
	return (res);
}

static int		*parse_line(char *line, t_conf *conf)
{
	char	**split;
	int		*res;
	int		i;

	if (!(split = ft_strsplit(line, ' ')))
		return (NULL);
	if (!split[0])
	{
		del_tab((void **)split);
		return (NULL);
	}
	i = 0;
	while (split[i])
		++i;
	if (!conf->dim.x)
		conf->dim.x = i;
	res = parse_split(split, i, conf->dim.x);
	return (res);
}

static t_dlist	*parse_lines(int fd, t_conf *conf)
{
	char	*line;
	int		*tmp;
	t_dlist *res;
	t_dlist	*last;

	res = NULL;
	last = NULL;
	line = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		if (!(tmp = parse_line(line, conf)))
		{
			ft_dlstdel(&res, free_line);
			free(line);
			return (NULL);
		}
		free(line);
		ft_dlstappend(&last, ft_dlstlink(tmp, 0));
		if (!res)
			res = last;
	}
	free(line);
	return (res);
}

int				**parse(int fd, t_conf *conf)
{
	int		**res;
	t_dlist	*tmp;

	if (!conf || read(fd, 0, 0) == -1)
		return (NULL);
	tmp = NULL;
	res = NULL;
	if (!(tmp = parse_lines(fd, conf)))
		return (NULL);
	conf->dim.y = ft_dlstlen(tmp);
	if (!(res = (int **)ft_dlst_to_tab(tmp)))
	{
		ft_dlstdel(&tmp, free_line);
		return (NULL);
	}
	ft_dlstdel(&tmp, NULL);
	return (res);
}
