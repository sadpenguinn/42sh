/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modification_free.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 15:15:41 by narchiba          #+#    #+#             */
/*   Updated: 2019/03/20 15:15:42 by narchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"
#include "shell.h"

void	modification_free(t_modification *modif)
{
	if (modif == NULL)
		return ;
	while (modif->len)
	{
		action_free(modif->actions[modif->len - 1]);
		modif->len--;
	}
	free(modif->actions);
	free(modif);
}
