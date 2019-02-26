/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getredir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 16:02:43 by bwerewol          #+#    #+#             */
/*   Updated: 2019/02/19 21:23:48 by bwerewol         ###   ########.fr       */
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

t_list				*g_redirs;
unsigned int		g_redirf;

t_redir	*fileerr(char *file, t_redir *redir)
{
	g_execerr = 1;
	free(redir);
	fileerror(file);
	return ((t_redir *)0);
}

void	closefds(t_list	*redirs)
{
	while (redirs)
	{
		if (((t_redir *)redirs->data)->fd[1] > 2)
			close(((t_redir *)redirs->data)->fd[1]);
		redirs = redirs->next;
	}
}

void	apply_g_redir(void)
{
	t_redir	*redir;
	t_list	*redirs;
	t_list	*redirslist;

	printf("<><>\n");
	redirs = g_redirs;
	printf("%p\n", g_redirs);
	while (redirs)
	{
		printf("><><\n");
		redirslist = (t_list *)redirs->data;
		printf("%p\n", redirslist);
		printf("%p\n", redirslist->data);
		printf("apply:%d|%d\n", redir->fd[1], redir->fd[0]);
		/* while (redirslist) */
		/* { */
			printf("apply:%d|%d\n", redir->fd[1], redir->fd[0]);
			redir = (t_redir *)redirs->data;
			/* if (redir->type == REDIRECT) */
			/* 	dup2(redir->fd[1], redir->fd[0]); */
			/* if (redir->type == CLOSEFD) */
			/* 	close(redir->fd[0]); */
		/* 	redirslist = redirslist->next; */
		/* } */
		printf("=><=\n");
		redirs = redirslist->next;
	}
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
printf(">>%s|%d|%d\n", root->right->content, redir->fd[0], redir->fd[1]);
printf("%p\n", redir);
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
