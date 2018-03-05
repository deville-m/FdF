/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 20:52:22 by mdeville          #+#    #+#             */
/*   Updated: 2018/03/05 23:07:20 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "ft_graphics.h"
#include "mlx_keycode.h"
#include "ft_printf.h"

int		mouse_hook(int x, int y, void *param)
{
	t_mlx				*mlx;
	static t_pixel		blue = {.color = 0X000000FF};
	static t_2Dvector	last = {-1, -1};
	t_2Dvector			curr;

	if (!param)
		return (0);
	curr.x = x;
	curr.y = y;
	if (last.x == -1 && last.y == -1)
		last = curr;
	mlx = (t_mlx *)param;
	if (mlx->mouse[BUT1_KEY])
	{
		put_line(mlx->img, last, curr, blue);
		mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img->ptr, 0, 0);
	}
	last = curr;
	return (1);
}
