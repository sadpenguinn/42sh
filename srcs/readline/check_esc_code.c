/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_esc_code.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sitlcead <sitlcead@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 13:53:30 by sitlcead          #+#    #+#             */
/*   Updated: 2019/02/20 13:53:30 by sitlcead         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"
#include "time.h"

static int	check_buttons(t_matrix *matrix, t_uchar c)
{
	if (c == LEFT)
		return (move_cursor_left(matrix));
	if (c == RIGHT)
		return (move_cursor_right(matrix));
	if (c == DOWN)
		return (move_cursor_down(matrix));
	if (c == UP)
		return (move_cursor_up(matrix));
	if (c == HOME1 || c == HOME2)
		return (move_cursor_home(matrix));
	if (c == END1 || c == END2)
		return (move_cursor_end(matrix));
	return (0);
}

int			check_esc_code(t_matrix *matrix)
{
	int		i;
	time_t	start;
	time_t	end;
	t_uchar	c;
	t_uchar	tmp;

	i = 1;
	c = 27;
	while (i < 8)
	{
		start = time(&start);
		tmp = get_next_symbol(sizeof(char));
		end = time(&end);
		if (difftime(end, start) >= 0.2)
			return (1);
		c += (tmp << (i * 8));
		if (check_buttons(matrix, c))
		{
			print_default(matrix);
			return (1);
		}
		i++;
	}
	return (1);
}
