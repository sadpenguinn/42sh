/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 10:22:36 by narchiba          #+#    #+#             */
/*   Updated: 2018/12/01 16:57:19 by narchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include "get_next_line.h"
#include "libft.h"
#include "vector.h"

static int	rb_tree_cmp(const void *data1, const void *data2)
{
	return (((t_gnl*)data1)->fd - ((t_gnl*)data2)->fd);
}

static int	get_rez(char **line, int check, t_rb_tree_node *node,
		t_rb_tree_node **root)
{
	char	c;

	if (check == -1 || check == 0)
	{
		vector_free((void **)line);
		vector_free((void **)&(((t_gnl *)(node->data))->str));
		ft_rb_tree_delete(node, root);
		return (check);
	}
	c = '\0';
	if (!(vector_push_back((void **)line, &c)))
	{
		vector_free((void **)line);
		vector_free((void **)&(((t_gnl *)(node->data))->str));
		ft_rb_tree_delete(node, root);
		return (-1);
	}
	if (!(vector_to_array((void **)line)))
	{
		vector_free((void **)line);
		vector_free((void **)&(((t_gnl *)(node->data))->str));
		ft_rb_tree_delete(node, root);
		return (-1);
	}
	return (check);
}

static int	move_rest_to_line(char **line, t_rb_tree_node *node)
{
	while (!(vector_is_empty(((t_gnl *)(node->data))->str)) &&
			*((char *)vector_back(((t_gnl *)(node->data))->str)) != '\n')
	{
		if (!(vector_push_back((void **)line,
						vector_back(((t_gnl *)(node->data))->str))))
			return (-1);
		if (!(vector_pop_back((void **)&(((t_gnl *)(node->data))->str))))
			return (-1);
	}
	if (!(vector_is_empty(((t_gnl *)(node->data))->str)))
	{
		if (!(vector_pop_back((void **)&(((t_gnl *)(node->data))->str))))
			return (-1);
		return (1);
	}
	return (2);
}

static int	get_line(const int fd, char **line, t_rb_tree_node *node)
{
	size_t		i;
	size_t		ret;
	char		buf[BUFF_SIZE];

	ret = read(fd, buf, BUFF_SIZE);
	if (ret == (size_t)(-1))
		return (-1);
	while (ret)
	{
		i = -1;
		while (++i < ret && buf[i] != '\n')
			if (!(vector_push_back((void **)line, buf + i)))
				return (-1);
		if (i < ret || ret < BUFF_SIZE)
		{
			while (--ret > i)
				if (!(vector_push_back((void **)&(((t_gnl *)
										(node->data))->str), buf + ret)))
					return (-1);
			return (1);
		}
		ret = read(fd, buf, BUFF_SIZE);
	}
	return (0);
}

int			get_next_line(const int fd, char **line)
{
	static t_rb_tree_node	*root = NULL;
	int						check;
	t_rb_tree_node			*node;
	t_gnl					tmp;

	if (fd < 0 || line == NULL)
		return (-1);
	tmp.fd = fd;
	if (!(node = ft_rb_tree_find(&tmp, root, &rb_tree_cmp)))
	{
		node = ft_rb_tree_insert(&tmp, sizeof(t_gnl), &root, &rb_tree_cmp);
		if (!(((t_gnl *)(node->data))->str = vector_create(sizeof(char))))
			return (get_rez(line, -1, node, &root));
	}
	if (!(*line = vector_create(sizeof(char))))
		return (get_rez(line, -1, node, &root));
	check = move_rest_to_line(line, node);
	if (check != 2)
		return (get_rez(line, check, node, &root));
	check = get_line(fd, line, node);
	if (check != 0)
		return (get_rez(line, check, node, &root));
	if (!(vector_is_empty(*line)))
		return (get_rez(line, 1, node, &root));
	return (get_rez(line, 0, node, &root));
}
