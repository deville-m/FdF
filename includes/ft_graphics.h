/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graphics.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 20:52:55 by mdeville          #+#    #+#             */
/*   Updated: 2018/03/03 22:53:45 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GRAPHICS_H
# define FT_GRAPHICS_H

typedef struct		s_point
{
	int				x;
	int				y;
}					t_point;

typedef struct		s_pixel
{
	unsigned char	a;
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}					t_pixel;

typedef struct		s_image
{
	void			*ptr;
	t_pixel			**data;
	int				width;
	int				height;
	int				bit_per_pixel;
	int				size_line;
	int				endian;
}					t_image;

typedef struct		s_mlx
{
	void			*alloced;
	void			*ptr;
	void			*win;
	t_image			*img;
	int				keyboard[279];
	int				mouse[7];
}					t_mlx;

int					init(t_mlx *mlx, int width, int height, char *name);
int					init_hooks(t_mlx *mlx);
int					put_pixel(t_image *img, t_point p, t_pixel color);
void				put_line(t_image *img, t_point a, t_point b, t_pixel color);
t_image				*new_image(void *mlx_ptr, int height, int width);
void				del_image(void *mlx_ptr, t_image **img);
void				del_mlx(t_mlx *mlx);
int					exit_x(void *param);

#endif
