/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_line_prefix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 16:35:30 by narchiba          #+#    #+#             */
/*   Updated: 2019/02/26 16:36:29 by narchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"
#include "array.h"

static void	num_to_str(int max, char *str, int nbr)
{
	int	i;

	i = get_lines_offset(max);
	memset(str, 0, i + 1);
	while (nbr && i)
	{
		str[i - 1] = '0' + nbr % 10;
		i--;
		nbr /= 10;
	}
	while (i)
	{
		str[i - 1] = '0';
		i--;
	}
}

void		add_line_prefix(t_matrix *matrix, int cur_row)
{
	char	str[20];

	memset(str, 0, 20);
	if (cur_row == matrix->cursor->row)
		add_cur_line_prompt_style();
	else
		add_lines_prompt_style();
	num_to_str(matrix->len, str, cur_row + 1);
	array_add(str, strlen(str));
	array_add("> ", 2);
	array_add(COLOR_DEFAULT, strlen(COLOR_DEFAULT));
}
