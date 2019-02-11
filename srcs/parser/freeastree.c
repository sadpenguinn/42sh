/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeastree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 21:58:50 by bwerewol          #+#    #+#             */
/*   Updated: 2019/02/11 12:12:17 by bwerewol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_astree	*freeastree(t_astree	*root)
{
	/* printf("%p\n", root); */
	if (!root)
		return (0);
	/* printf("l:%p\n", root->left); */
	/* printf("r:%p\n", root->right); */
	if (root->content)
		free(root->content);
	if (root->left)
		freeastree(root->left);
	if (root->right)
		freeastree(root->right);
	free(root);
	return (0);
}
