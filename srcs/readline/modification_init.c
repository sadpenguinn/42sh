/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modification_init.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 15:15:54 by narchiba          #+#    #+#             */
/*   Updated: 2019/03/20 15:16:08 by narchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"
#include "shell.h"

t_modification	*modification_init(void)
{
	t_modification	*modif;

	modif = (t_modification *)xmalloc(sizeof(t_modification));
	modif->actions = (t_action **)xmalloc(sizeof(t_action *) *
			MODIF_ARRAY_DEFAULT_SIZE);
	modif->size = MODIF_ARRAY_DEFAULT_SIZE;
	modif->len = 0;
	modif->cur = 0;
	return (modif);
}
