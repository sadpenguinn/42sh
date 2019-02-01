/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_handling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sitlcead <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 23:36:40 by sitlcead          #+#    #+#             */
/*   Updated: 2019/01/30 16:56:11 by narchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_editing.h"

void	clear_line(char *buf, int *len, int *pos)
{
	write(1, "\e[2K", 4);
	write(1, "\e8", 2);
	write(1, "\e7", 2);
	print_prompt();
}

int		output_line(char *buf, int *len, int *pos)
{
	write(1, buf, *len);
	move_cursor_to_pos(buf, *pos, *len);
	return (1);
}
