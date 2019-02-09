/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 14:21:31 by bwerewol          #+#    #+#             */
/*   Updated: 2019/02/08 17:39:41 by bwerewol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	RDLST - ReDirection LiST	(res)
**	RD - ReDirection			(root)(type: REDIRECTION)
**
**    RDLST
**   /     \
** RD       RDLST
**         /     \
**       RD       ...
*/

#include "parser.h"

t_astree	*redirection_list(void)
{
	t_astree	*res;
	t_astree	*root;

	if (!(res = redirection()))
		return (0);
	root = xmalloc(sizeof(t_astree));
	root->type = REDIRECTION;
	root->left = res;
	root->right = redirection_list();
	return (root);
}
