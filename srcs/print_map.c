/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 18:21:53 by mdeville          #+#    #+#             */
/*   Updated: 2018/03/05 18:27:21 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

void	print_map(int **map, int line_size)
{
	int i;

	if (!map)
	{
		ft_printf("MAP EMPTY\n");
		return ;
	}
	while (*map)
	{
		i = 0;
		while (i < line_size)
		{
			ft_printf("%d ", (*map)[i]);
			++i;
		}
		write(1, "\n", 1);
		++map;
	}
}
