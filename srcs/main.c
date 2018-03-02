/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 13:33:55 by mdeville          #+#    #+#             */
/*   Updated: 2018/03/02 22:26:51 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <mlx.h>
#include "ft_graphics.h"
#include "fdf.h"
#include "mlx_keycode.h"
#include "ft_printf.h"

int		main()
{
	t_mlx	mlx;

	if (!init(&mlx, WIDTH, HEIGHT, "FdF"))
		return (0);
	mlx_loop(mlx.ptr);
	return (0);
}