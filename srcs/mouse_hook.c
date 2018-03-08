/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 20:52:22 by mdeville          #+#    #+#             */
/*   Updated: 2018/03/08 15:48:53 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fdf.h"
#include "ft_graphics.h"
#include "mlx_keycode.h"
#include "ft_printf.h"

int		mouse_hook(int x, int y, void *param)
{
	t_mlx				*mlx;
	static t_2dvector	last = {-1, -1};
	t_2dvector			curr;
	t_conf				*conf;

	if (!param)
		return (0);
	curr.x = x;
	curr.y = y;
	if (last.x == -1 && last.y == -1)
		last = curr;
	mlx = (t_mlx *)param;
	if (mlx->mouse[1])
	{
		conf = get_conf();
		conf->angle.x += (last.y - curr.y) / 100;
		conf->angle.y += (last.x - curr.x) / 100;
		clear_image(mlx->img);
		print_x_map(mlx, mlx->alloced, conf);
	}
	last = curr;
	return (1);
}
