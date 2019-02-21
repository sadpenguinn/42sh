/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compound_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 19:08:06 by bwerewol          #+#    #+#             */
/*   Updated: 2019/02/21 14:33:14 by bwerewol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_astree		*compound_list(void)
{
	unsigned int	curtmp;
	t_astree		*res;

	curtmp = g_curtok;
	newline_list();
	if (!(res = list1()))
		return (savecur(curtmp));
	return (res);
}
