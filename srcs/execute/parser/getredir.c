/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getredir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 16:02:43 by bwerewol          #+#    #+#             */
/*   Updated: 2019/02/19 17:46:34 by bwerewol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"
#include <fcntl.h>
#include <unistd.h>

/*
**              <(type)
**             /  \
**  (content)2?    filename(content)
*/

t_redir	*fileerr(char *file, t_redir *redir)
{
	g_execerr = 1;
	free(redir);
	fileerror(file);
	return ((t_redir *)0);
}

t_redir	*get_redir(t_astree *root)
{
	t_redir		*redir;
	int			type;

	type = root->type;
	redir = malloc(sizeof(t_redir));
	redir->type = REDIRECT;
	redir->fd[0] = (type == LESS || type == DLESS || type == LESSAND) ? 0 : 1;
	if (root->left)
		redir->fd[0] = ft_atoi(root->left->content);
	if (type != LESSAND && type != GREATAND)
	{
		if (-1 == (redir->fd[1] = open(root->right->content,
				O_WRONLY | O_CREAT | O_TRUNC | O_CLOEXEC, 0644)))
			return (fileerr(root->right->content, redir));
	}
	else
	{
		if (ft_strequ(root->right->content, "-"))
			redir->type = CLOSEFD;
		else
			redir->fd[1] = ft_atoi(root->right->content);
	}
	return (redir);
}
