/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 16:27:11 by bwerewol          #+#    #+#             */
/*   Updated: 2019/02/20 17:51:06 by bwerewol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**     CMDREDIR
**    /        \
** CMD          REDIR
**
**     CMD
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

int		execcmd(t_astree *root, int fd[2], int job, int isfork)
{
	int			res;
	int			tmp;
	t_list		*cmdredir;
	t_astree	*redthree;

	if (root->type != CMDREDIR)
		return (execshellcmd(root, fd, job, isfork));
	tmp = g_redirf;
	g_redirf = REDIR_IO;
	redthree = root->right;
	cmdredir = (t_list *)0;
	while (redthree)
	{
		ft_push_back(&cmdredir, get_redir(redthree->left));
		redthree = redthree->right;
	}
	ft_push_back(&g_redirs, cmdredir);
	res = execshellcmd(root->left, fd, job, isfork);
	g_redirf = tmp;
	cmdredir = (t_list *)ft_pop(&g_redirs);
	closefds(cmdredir);
	ft_listdel(&cmdredir, &ft_free);
	return (res);
}
