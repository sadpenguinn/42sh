/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_resize.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 13:07:45 by narchiba          #+#    #+#             */
/*   Updated: 2019/03/08 13:07:56 by narchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"
#include "shell.h"

void	history_resize(t_history *history)
{
	history->matrix =
			(t_matrix **)xrealloc(history->matrix,
					history->size * RATIO * sizeof(t_matrix *),
					history->size * sizeof(t_matrix *));
	history->size *= RATIO;
}
