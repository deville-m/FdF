/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_tab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 17:00:12 by mdeville          #+#    #+#             */
/*   Updated: 2018/03/05 18:21:22 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

void	del_tab(void **tab)
{
	void **tab2;

	tab2 = tab;
	if (!tab)
		return ;
	while (*tab)
		free(*tab++);
	free(tab2);
}
