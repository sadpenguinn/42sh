/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_astree.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 17:25:13 by nkertzma          #+#    #+#             */
/*   Updated: 2019/01/22 11:36:43 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <math.h>
#include "libft.h"
#include "expr.h"

static size_t	find_tree_height(t_astree *root)
{
	size_t	left;
	size_t	right;

	if (!root)
		return (0);
	left = find_tree_height(root->left);
	right = find_tree_height(root->right);
	return ((left > right ? left : right) + 1);
}

static void		print_space(int space)
{
	while (space--)
	{
		printf(" ");
	}
}

static int		get_space(int max_len, int level)
{
	int	elem_count;
	int	space;

	elem_count = pow(2, level);
	space = (max_len - (elem_count * 4)) / (elem_count + 1);
	return (space);
}

static t_list	*print_level(t_list **queue, size_t level, int max_len, size_t height)
{
	t_list	*tmp;
	t_list	*elem;
	t_astree *tree;
	int		space;

	tmp = NULL;
	space = get_space(max_len, level);
	print_space(space);
	while ((elem = ft_pop(queue)))
	{
		tree = (t_astree *)(elem->data);
		if (!tree)
			printf("    ");
		else
			printf("%4d", tree->type);
		if (level < height - 1)
		{
			ft_push_back(&tmp, tree ? tree->left : 0);
			ft_push_back(&tmp, tree ? tree->right : 0);
		}
		print_space(space);
	}
	printf("\n");
	return (tmp);
}

void			print_astree(t_astree *root)
{
	t_list	*queue;
	size_t	height;
	int		max_len;
	int		level;

	if (!root)
		return ;
	queue = NULL;
	level = 0;
	height = find_tree_height(root);
	max_len = pow(2, height) * 5 + 1;
	ft_push_back(&queue, root);
	while ((queue = print_level(&queue, level, max_len, height)))
		level++;
}
