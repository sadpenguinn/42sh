/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modification_resize.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 15:16:20 by narchiba          #+#    #+#             */
/*   Updated: 2019/03/20 15:16:21 by narchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"
#include "shell.h"

void	modification_resize(t_modification *modif,
		size_t new_size, size_t old_size)
{
	modif->actions = (t_action **)xrealloc(modif->actions,
			sizeof(t_action *) * new_size, sizeof(t_action *) * old_size);
	modif->size = new_size;
}
