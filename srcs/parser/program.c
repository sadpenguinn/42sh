/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 20:50:47 by bwerewol          #+#    #+#             */
/*   Updated: 2019/01/30 15:45:02 by bwerewol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**     COMPLETE_COMMANDS
**    /                 \
** ...                   ...
*/

#include "parser.h"

t_astree	*program(void)
{
	t_astree	*res;

	linebreak();
	res = complete_commands();
	linebreak();
	/*  XXX */
	/* if (g_curtok < ((size_t *)g_tokens)[2]) */
	/* 	return (0); */
	return (res);
}
