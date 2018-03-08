/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 21:27:27 by mdeville          #+#    #+#             */
/*   Updated: 2018/03/08 15:47:38 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_graphics.h"

int		put_pixel(t_image *img, t_2dvector p, t_pixel color)
{
	int		x;
	int		y;

	x = (int)p.x;
	y = (int)p.y;
	if (!img || !img->data
		|| x >= img->width || y >= img->height
		|| x < 0 || y < 0)
		return (0);
	if (img->endian)
	{
		img->data[y][x].col.b = color.col.a;
		img->data[y][x].col.g = color.col.r;
		img->data[y][x].col.r = color.col.g;
		img->data[y][x].col.a = color.col.b;
	}
	else
		img->data[y][x] = color;
	return (1);
}
