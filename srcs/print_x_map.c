/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 14:02:08 by mdeville          #+#    #+#             */
/*   Updated: 2018/03/07 20:50:57 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <mlx.h>
#include "fdf.h"
#include "ft_graphics.h"
#include "ft_printf.h"

static t_2Dvector	project_point(double x, double y, double z, t_conf *conf)
{
	t_2Dvector	res;

	res.x = cos(conf->angle.y) * x + sin(conf->angle.y) * z;
	z = -sin(conf->angle.y) * x + cos(conf->angle.y) * z;
	res.y = cos(conf->angle.x) * y + cos(conf->angle.x) * z;
	res.x *= conf->scale.x;
	res.y *= conf->scale.y;
	res.x += conf->pad.x;
	res.y += conf->pad.y;
	return (res);
}

void				print_x_map(
								t_mlx *mlx,
								double **map,
								t_conf *conf)
{
	int i;
	int j;
	t_2Dvector a;
	t_2Dvector b;

	i = 0;
	while (i < conf->dim.y)
	{
		j = 0;
		while (j < conf->dim.x)
		{
			a = project_point(j, i, map[i][j], conf);
			if (j < conf->dim.x - 1)
			{
				b = project_point(j + 1, i, map[i][j + 1], conf);
				put_line(mlx->img, a, b, conf->color);
			}
			if (i < conf->dim.y - 1)
			{
				b = project_point(j, i + 1, map[i + 1][j], conf);
				put_line(mlx->img, a, b, conf->color);
			}
			++j;
		}
		++i;
	}
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img->ptr, 0, 0);
	mlx_string_put(mlx->ptr, mlx->win, 50, 50, conf->color.color & 0x00FF0000, "R");
	mlx_string_put(mlx->ptr, mlx->win, 65, 50, conf->color.color & 0x0000FF00, "G");
	mlx_string_put(mlx->ptr, mlx->win, 80, 50, conf->color.color & 0x000000FF, "B");
}
