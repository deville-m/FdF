/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_release.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 20:26:08 by mdeville          #+#    #+#             */
/*   Updated: 2018/03/03 20:33:01 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_graphics.h"

int	mouse_release(int button, int x, int y, void *param)
{
	(void)x;
	(void)y;
	if (!param)
		return (0);
	((t_mlx *)param)->mouse[button] = 0;
	return (1);
}
