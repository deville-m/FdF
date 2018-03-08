/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 13:33:55 by mdeville          #+#    #+#             */
/*   Updated: 2018/03/08 15:10:43 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <mlx.h>
#include "ft_graphics.h"
#include "fdf.h"
#include "mlx_keycode.h"
#include "ft_printf.h"

t_conf	*get_conf(void)
{
	static int		is_init = 0;
	static t_conf	conf;

	if (!is_init)
	{
		conf.angle.x = 35;
		conf.angle.y = 45;
		conf.pad.x = WIDTH / 2;
		conf.pad.y = HEIGHT / 2;
		conf.scale = 10;
		conf.alt = 1.;
		conf.color.color = 0xeb7141;
		is_init++;
	}
	return (&conf);
}

int		main(int argc, char **argv)
{
	t_mlx		mlx;
	t_conf		*conf;
	int			fd;

	if (!init(&mlx, WIDTH, HEIGHT, "FdF") || !init_hooks(&mlx))
		return (0);
	if (argc >= 3)
		exit_x(&mlx);
	conf = get_conf();
	if (argc == 1 && !(mlx.alloced = parse(0, conf)))
		exit_x(&mlx);
	else if (argc == 2)
	{
		if (!(fd = open(argv[1], O_RDONLY))
			|| !(mlx.alloced = parse(fd, conf)))
			exit_x(&mlx);
		close(fd);
	}
	print_x_map(&mlx, mlx.alloced, conf);
	mlx_loop(mlx.ptr);
	return (0);
}
