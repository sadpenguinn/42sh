/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getredir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 16:02:43 by bwerewol          #+#    #+#             */
/*   Updated: 2019/02/27 22:45:42 by nkertzma         ###   ########.fr       */
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

int			applyredir(t_list *redirs)
{
	t_redir	*redir;

	while (redirs)
	{
		redir = (t_redir *)redirs->data;
		if (redir->type == REDIRECT)
			dup2(redir->fd[1], redir->fd[0]);
		if (redir->type == CLOSEFD)
			close(redir->fd[0]);
		redirs = redirs->next;
	}
	return (0);
}

static int	get_herein_doc(char *end)
{
	int			fd[2];
	t_string	*line;

	pipe(fd);
	while ((line = heredoc()))
	{
		if (g_execerr || ft_strequ(line->buf, end))
			break ;
		ft_putstr_fd(line->buf, fd[1]);
		ft_putstr_fd("\n", fd[1]);
		string_free(line);
	}
	if (g_execerr)
		close(fd[0]);
	string_free(line);
	close(fd[1]);
	return (g_execerr ? -1 : fd[0]);
}

static int	get_redir_file(t_astree *root, int type)
{
	if (type == GREAT)
		return (open(root->right->content,
					O_WRONLY | O_CREAT | O_TRUNC | O_CLOEXEC, 0644));
		if (type == DGREAT)
		return (open(root->right->content,
					O_WRONLY | O_CREAT | O_APPEND | O_CLOEXEC, 0644));
		if (type == LESS)
		return (open(root->right->content,
					O_RDONLY | O_CLOEXEC));
		if (type == DLESS)
		return (get_herein_doc(root->right->content));
	return (-1);
}

t_redir		*get_redir(t_astree *root)
{
	t_redir		*redir;
	int			type;

	type = root->type;
	redir = malloc(sizeof(t_redir));
	redir->type = REDIRECT;
	redir->fd[0] = (type == LESS || type == DLESS || type == LESSAND) ? 0 : 1;
	if (root->left)
		redir->fd[0] = ft_atoi(root->left->content);
	if (type == LESSAND || type == GREATAND)
	{
		if (root->right->content[0] == '-')
			redir->type = CLOSEFD;
		else
			redir->fd[1] = ft_atoi(root->right->content);
	}
	else
	{
		if (-1 == (redir->fd[1] = get_redir_file(root, type)))
			return (redirfileerror(root->right->content, redir));
	}
	return (redir);
}
