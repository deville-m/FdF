/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 13:33:55 by mdeville          #+#    #+#             */
/*   Updated: 2018/03/07 19:21:03 by mdeville         ###   ########.fr       */
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
	static t_conf conf = {
						{0., 0.},
						{10, 10},
						{35., 45.},
						{WIDTH / 2, HEIGHT / 2},
						{.color = 0xeb7141}
						};

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
//	print_map(mlx.alloced, conf->dim.x);
	print_x_map(&mlx, mlx.alloced, conf);
	mlx_loop(mlx.ptr);
	return (0);
}
