/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inpuntunit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 13:38:43 by bwerewol          #+#    #+#             */
/*   Updated: 2019/02/11 13:45:10 by bwerewol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_astree	*inputunit(void)
{
	t_astree	*res;

	if (g_curtok >= ((size_t *)g_tokens)[2])
		return (0);
	res = simple_list1();
	if (!(simple_list_terminator()))
		return (freeastree(res), parseerror());
	return (res);
}
