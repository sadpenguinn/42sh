/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_del.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 12:59:44 by narchiba          #+#    #+#             */
/*   Updated: 2019/03/08 12:59:59 by narchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"
#include <stdlib.h>

void	history_del(t_history **history)
{
	if (history == NULL)
		return ;
	history_free(*history);
	*history = NULL;
}
