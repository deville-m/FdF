/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 20:52:22 by mdeville          #+#    #+#             */
/*   Updated: 2018/03/03 20:53:44 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "ft_graphics.h"
#include "mlx_keycode.h"

int		mouse_hook(int x, int y, void *param)
{
	t_mlx			*mlx;
	static t_pixel	blue = {0, 255, 0, 255};

	if (!param)
		return (0);
	mlx = (t_mlx *)param;
	if (mlx->mouse[BUT1_KEY] && put_pixel(mlx->img, x, y, blue))
		mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img->ptr, 0, 0);
	return (1);
}
