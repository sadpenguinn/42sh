/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 15:11:34 by narchiba          #+#    #+#             */
/*   Updated: 2019/03/20 15:11:35 by narchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"
#include "shell.h"

void	action_free(t_action *action)
{
	if (action == NULL)
		return ;
	free(action->buf);
	free(action);
}
