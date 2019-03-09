/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_cursor_offset.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 16:33:32 by narchiba          #+#    #+#             */
/*   Updated: 2019/02/26 16:33:43 by narchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"
#include "libft.h"

void	add_cursor_offset(void)
{
	char	str[20];

	if (g_history->last_offset)
	{
		ft_memset(str, 0, 20);
		array_add(CSI, ft_strlen(CSI));
		ft_strnum(str, g_history->last_offset);
		array_add(str, ft_strlen(str));
		array_add("A", 1);
	}
	array_add(CURSOR_MOVE_LINE_START, ft_strlen(CURSOR_MOVE_LINE_START));
	reset_last_offset();
}
