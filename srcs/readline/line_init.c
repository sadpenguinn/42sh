/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 13:11:36 by narchiba          #+#    #+#             */
/*   Updated: 2019/03/08 13:11:40 by narchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"
#include "shell.h"

t_line		*line_init(void)
{
	t_line	*line;

	line = (t_line *)xmalloc(sizeof(t_line));
	line->buf = (char *)xmalloc(sizeof(char) * BUF_DEFAULT_SIZE + 1);
	line->size = BUF_DEFAULT_SIZE;
	line->len = 0;
	line->symbols = 0;
	return (line);
}
