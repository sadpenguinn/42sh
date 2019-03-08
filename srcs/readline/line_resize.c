/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_resize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sitlcead <sitlcead@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 14:11:28 by sitlcead          #+#    #+#             */
/*   Updated: 2019/03/08 13:12:11 by narchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"
#include "shell.h"

void	line_resize(t_line *line, int new_size, int old_size)
{
	line->buf = (char *)xrealloc(line->buf, new_size + 1, old_size);
	line->size = new_size;
}
