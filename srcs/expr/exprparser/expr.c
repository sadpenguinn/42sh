/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expr.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 18:39:53 by bwerewol          #+#    #+#             */
/*   Updated: 2019/01/20 15:19:50 by bwerewol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expr.h"

unsigned int		g_excurtok;
void				*g_extokens;
int					g_exprerr;

t_astree		*expr(void)
{
	t_astree	*root;

	root = expr1();
	if (!exchecktype(TOKEOF))
		return (exparseerror(root));
	return (root);
}
