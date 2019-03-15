/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inpuntunit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 13:38:43 by bwerewol          #+#    #+#             */
/*   Updated: 2019/03/01 21:27:58 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_astree	*inputunit(void)
{
	t_astree	*res;

	g_curtok = 0;
	g_parseerr = 0;
	if (g_curtok >= ((size_t *)g_tokens)[2])
		return (0);
	res = list1();
	if (!(simple_list_terminator()))
		return (parseerror(res));
	return (res);
}
