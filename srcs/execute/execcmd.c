/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 16:27:11 by bwerewol          #+#    #+#             */
/*   Updated: 2019/02/27 22:45:42 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**     CMD
**
**     CMDREDIR
**    /        \
** CMD          REDIR
*/

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

#include "execute.h"

static void		applycmdredir(t_astree *root)
{
	t_redir		*redir;
	t_astree	*redthree;

	redthree = root->right;
	while (redthree)
	{
		redir = get_redir(redthree->left);
		if (redir->type == REDIRECT)
			dup2(redir->fd[1], redir->fd[0]);
		if (redir->type == CLOSEFD)
			close(redir->fd[0]);
		redthree = redthree->right;
	}
}

int				execcmd(t_astree *root, int fd[2], int isfork)
{
	pid_t		pid;

	if (root->type != CMDREDIR)
		return (execshellcmd(root, fd, isfork));
	if (!(pid = xfork()))
	{
		applycmdredir(root);
		exit(execshellcmd(root->left, fd, isfork));
	}
	if (pid == -1)
		return (-1);
	return (xwaitpid(pid, 0));
}
