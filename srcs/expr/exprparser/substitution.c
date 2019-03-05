/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   substitution.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 17:43:57 by bwerewol          #+#    #+#             */
/*   Updated: 2019/01/21 17:52:46 by bwerewol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expr.h"

t_astree	*substitution()
{
	t_astree	*leaf;

	if (((t_lexem *)vector_get_elem(g_extokens, g_excurtok))->type != HASH)
		return (0);
	if (!(leaf = ft_memalloc(sizeof(t_astree))))
		return (0);
	leaf->type = HASH;
	return (leaf);
}
