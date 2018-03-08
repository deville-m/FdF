/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 19:17:00 by mdeville          #+#    #+#             */
/*   Updated: 2018/03/08 15:44:49 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "ft_graphics.h"
#include "mlx_keycode.h"

static int	color_key(int keycode, t_conf *conf)
{
	if (keycode == Q_KEY)
		conf->color.col.r += 5;
	else if (keycode == W_KEY)
		conf->color.col.g += 5;
	else if (keycode == E_KEY)
		conf->color.col.b += 5;
	else if (keycode == A_KEY)
		conf->color.col.r -= 5;
	else if (keycode == S_KEY)
		conf->color.col.g -= 5;
	else if (keycode == D_KEY)
		conf->color.col.b -= 5;
	else
		return (0);
	return (1);
}

static int	move_key(int keycode, t_conf *conf)
{
	if (keycode == UP_KEY)
		conf->pad.y -= 10;
	else if (keycode == DOWN_KEY)
		conf->pad.y += 10;
	else if (keycode == RIGHT_KEY)
		conf->pad.x += 10;
	else if (keycode == LEFT_KEY)
		conf->pad.x -= 10;
	else
		return (0);
	return (1);
}

static int	zoom_key(int keycode, t_conf *conf)
{
	if (keycode == NKPL_KEY)
		conf->scale += 0.1;
	else if (keycode == NKMN_KEY)
		conf->scale -= 0.1;
	else if (keycode == NK6_KEY)
		conf->alt += 0.1;
	else if (keycode == NK9_KEY)
		conf->alt -= 0.1;
	else
		return (0);
	return (1);
}

int			key_hook(int keycode, void *param)
{
	t_conf	*conf;

	conf = get_conf();
	if (keycode == ESC_KEY)
		exit_x(param);
	else if (move_key(keycode, conf)
			|| color_key(keycode, conf)
			|| zoom_key(keycode, conf))
	{
		clear_image(((t_mlx *)param)->img);
		print_x_map(param, ((t_mlx *)param)->alloced, conf);
	}
	return (1);
}
