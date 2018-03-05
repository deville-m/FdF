/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 21:08:15 by mdeville          #+#    #+#             */
/*   Updated: 2018/03/05 21:59:30 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fdf.h"
#include "ft_graphics.h"

int	exit_x(void *param)
{
	del_mlx((t_mlx *)param);
	if (((t_mlx *)param)->alloced)
		del_tab(((t_mlx *)param)->alloced);
	exit(0);
}
