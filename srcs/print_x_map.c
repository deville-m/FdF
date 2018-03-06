/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 14:02:08 by mdeville          #+#    #+#             */
/*   Updated: 2018/03/06 19:03:54 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <mlx.h>
#include "fdf.h"
#include "ft_graphics.h"

static t_2Dvector	project_point(int x, int y, int z, t_conf *conf)
{
	t_2Dvector	res;
	double		tmpx;
	double		tmpy;
	int			alpha;
	int			beta;

	alpha = conf->angle.x;
	beta = conf->angle.y;
	tmpx = x * cos(beta) - z * sin(beta);
	tmpy = y * cos(alpha) + z * cos(beta) * sin(alpha) + x * sin(alpha) * cos(beta);
	tmpx *= conf->scale.x;
	tmpy *= conf->scale.y;
	res.x = (int)tmpx + conf->pad.x;
	res.y = (int)tmpy + conf->pad.y;
	return (res);
}

void				print_x_map(
								t_mlx *mlx,
								int **map,
								t_conf *conf,
								t_pixel color)
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
			if (j != conf->dim.x - 1)
			{
				b = project_point(j + 1, i, map[i][j + 1], conf);
				put_line(mlx->img, a, b, color);
			}
			if (i != conf->dim.y - 1)
			{
				b = project_point(i + 1, j, map[i + 1][j], conf);
				put_line(mlx->img, a, b, color);
			}
			++j;
		}
		++i;
	}
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img->ptr, 0, 0);
}
