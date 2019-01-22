/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_handling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sitlcead <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 23:36:40 by sitlcead          #+#    #+#             */
/*   Updated: 2019/01/17 11:17:23 by narchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_editing.h"

void	clear_all_line(void)
{
	write(1, "\e[2K", 4);
	write(1, "\e[1K", 4);
	write(1, "\e[0K", 4);
}

void	clear_line(char *buf, int *len, int *pos)
{
	/* char	*tmp; */
	/* int		i; */

	/* tmp = malloc(sizeof(char) * (*len)); */
	/* memset(tmp, 0, sizeof(char) * (*len)); */
	/* i = *pos; */
	/* move_cursor_left(move_pos_begin(buf, len, &i)); */
	/* i = 0; */
	/* while (i < *len) */
	/* 	tmp[i++] = ' '; */
	/* write(1, tmp, *len); */
	/* printf("i = %d\n\n", i); */
	/* printf("len = %d", *len); */
	/* fflush(stdout); */
	/* move_cursor_left(move_pos_begin(tmp, len, &i)); */
	/* free(tmp); */
	clear_all_line();
	print_prompt();
}

int		output_line(char *buf, int *len, int *pos)
{
	write(1, buf, *len);
	move_cursor_to_pos(buf, *pos, *len);
	return (1);
}
