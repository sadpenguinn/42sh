/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sitlcead <sitlcead@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 14:11:14 by sitlcead          #+#    #+#             */
/*   Updated: 2019/02/20 14:11:14 by sitlcead         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"
#include "shell.h"

t_line	*init_line(void)
{
	t_line	*line;

	line = (t_line *)xmalloc(sizeof(t_line));
	line->buf = (char *)xmalloc(sizeof(char) * BUF_DEFAULT_SIZE + 1);
	line->size = BUF_DEFAULT_SIZE;
	line->len = 0;
	line->symbols = 0;
	return (line);
}
