/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 21:27:27 by mdeville          #+#    #+#             */
/*   Updated: 2018/03/03 21:51:24 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_graphics.h"

int		put_pixel(t_image *img, t_point p, t_pixel color)
{
	if (!img || !img->data
		|| p.x >= img->width || p.y >= img->height
		|| p.x < 0 || p.y < 0)
		return (0);
	if (!img->endian)
	{
		img->data[p.y][p.x].b = color.a;
		img->data[p.y][p.x].g = color.r;
		img->data[p.y][p.x].r = color.g;
		img->data[p.y][p.x].a = color.b;
	}
	else
		img->data[p.y][p.x] = color;
	return (1);
}
