/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 14:02:08 by mdeville          #+#    #+#             */
/*   Updated: 2018/03/08 15:31:03 by mdeville         ###   ########.fr       */
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

	x -= conf->cen.x;
	y -= conf->cen.y;
	z *= conf->alt;
	res.x = x * conf->cb - y * conf->sb;
	res.y = y * conf->ca * conf->cb - z * conf->sa + x * conf->ca * conf->sb;
	res.x *= conf->scale;
	res.y *= conf->scale;
	res.x += conf->pad.x;
	res.y += conf->pad.y;
	return (res);
}

static inline void	update_conf(t_conf *conf)
{
	conf->cen.x = conf->dim.x / 2;
	conf->cen.y = conf->dim.y / 2;
	conf->ca = cos(conf->angle.x);
	conf->cb = cos(conf->angle.y);
	conf->sa = sin(conf->angle.x);
	conf->sb = sin(conf->angle.y);
}

static inline void	put_string(t_mlx *mlx, t_conf *conf)
{
	mlx_string_put(
			mlx->ptr,
			mlx->win,
			50, 50,
			conf->color.color & 0x00FF0000, "R");
	mlx_string_put(
			mlx->ptr,
			mlx->win,
			65, 50,
			conf->color.color & 0x0000FF00, "G");
	mlx_string_put(
			mlx->ptr,
			mlx->win,
			80, 50,
			conf->color.color & 0x000000FF, "B");
}

static inline void	calc_image(t_image *img, double **map, t_conf *conf)
{
	int			i;
	int			j;
	t_2Dvector	a;

	i = 0;
	while (i < conf->dim.y)
	{
		j = 0;
		while (j < conf->dim.x)
		{
			a = project_point(j, i, map[i][j], conf);
			if (j < conf->dim.x - 1)
				put_line(img, a, project_point(j + 1, i, map[i][j + 1], conf),
						conf->color);
			if (i < conf->dim.y - 1)
				put_line(img, a, project_point(j, i + 1, map[i + 1][j], conf),
						conf->color);
			j += 1;
		}
		i += 1;
	}
}

void				print_x_map(
								t_mlx *mlx,
								double **map,
								t_conf *conf)
{
	update_conf(conf);
	calc_image(mlx->img, map, conf);
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img->ptr, 0, 0);
	put_string(mlx, conf);
}
