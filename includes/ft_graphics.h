/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graphics.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 20:52:55 by mdeville          #+#    #+#             */
/*   Updated: 2018/03/05 22:41:52 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GRAPHICS_H
# define FT_GRAPHICS_H

typedef struct			s_2Dvector
{
	int					x;
	int					y;
}						t_2Dvector;

typedef union			u_pixel
{
	int					color;
	struct {
		unsigned char	b;
		unsigned char	g;
		unsigned char	r;
		unsigned char	a;
	};
}						t_pixel;

typedef struct			s_image
{
	void				*ptr;
	t_pixel				**data;
	int					width;
	int					height;
	int					bit_per_pixel;
	int					size_line;
	int					endian;
}						t_image;

typedef struct			s_mlx
{
	void				*alloced;
	void				*ptr;
	void				*win;
	t_image				*img;
	int					keyboard[280];
	int					mouse[8];
}						t_mlx;

int						init(t_mlx *mlx, int width, int height, char *name);
int						init_hooks(t_mlx *mlx);
int						put_pixel(
								t_image *img,
								t_2Dvector p,
								t_pixel color);
void					put_line(
								t_image *img,
								t_2Dvector a,
								t_2Dvector b,
								t_pixel color);
t_image					*new_image(void *mlx_ptr, int height, int width);
void					del_image(void *mlx_ptr, t_image **img);
void					del_mlx(t_mlx *mlx);
int						exit_x(void *param);

#endif
