/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subshell.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 13:00:53 by bwerewol          #+#    #+#             */
/*   Updated: 2019/02/10 16:44:18 by bwerewol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_astree	*subshell(void)
{
	t_astree        *root;

	if (!checktype(OBRACKET))
		return (0);
	if (!(root = compound_list()))
		return (parseerror());
	if (!checktype(CBRACKET))
		return (freeastree(root), parseerror());
	return (root);
}
