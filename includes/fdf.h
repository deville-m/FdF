/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 14:34:43 by mdeville          #+#    #+#             */
/*   Updated: 2018/03/05 18:28:34 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "ft_graphics.h"

# define WIDTH 1920
# define HEIGHT 1080

typedef struct	s_conf
{
	t_2Dvector	dim;
	t_2Dvector	scale;
	t_2Dvector	angle;
	t_2Dvector	pad;
}				t_conf;

void			print_map(int **map, int size_line);
void			del_tab(void **tab);
int				**parse(int fd, t_conf *conf);
int				mouse_press(int button, int x, int y, void *param);
int				mouse_release(int button, int x, int y, void *param);
int				mouse_hook(int x, int y, void *param);

#endif
