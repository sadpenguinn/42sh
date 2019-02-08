/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 14:21:31 by bwerewol          #+#    #+#             */
/*   Updated: 2019/02/08 14:26:10 by bwerewol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	RDLST - ReDirection LiST
**	RD - ReDirection
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
	t_astree	*root;

	if (!(root = redirection()))
		return (0);
	root->right = redirection_list();
	return (root);
}
