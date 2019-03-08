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

#ifndef EXECUTE_H
# define EXECUTE_H

# include "shell.h"
# include "libft.h"
# include <stdio.h>
# include "exprlexer.h"

# define EXECUTE_RELEASE

extern int				g_execerr;
extern void				*g_pids;

/*
**	Flags for g_redirf
*/

# define REDIR_NO		0
# define REDIR_IN		0b1
# define REDIR_OUT		0b01
# define REDIR_IO		0b11

/*
**	Flags for t_redir->type
*/

# define REDIRECT		1
# define CLOSEFD		2

/*
**	Flags for job
*/

# define EX_NOFG		0
# define EX_FG			1

typedef struct			s_redir
{
	int		type;
	int		fd[2];
}						t_redir;

typedef struct			s_cmd
{
	t_astree	*root;
	void		*ppid;
	int			fd[2];
	int			job;
}						t_cmd;

typedef struct			s_func
{
	char		*name;
	t_astree	*func;
}						t_func;

int						execute(t_astree *root);
int						execlist1(t_astree *root,
									int fd[2], int job, int isfork);
int						execlist2(t_astree *root,
									int fd[2], int job, int isfork);
int						execlist3(t_astree *root,
									int fd[2], int job, int isfork);
int						execpipecmd(t_astree *root,
									int fd[2], int job, int isfork);
int						execpipes(t_astree	*root,
									int fd[2], int job, int isfork);
int						execcmd(t_astree *root,
									int fd[2], int job, int isfork);
int						execshellcmd(t_astree *root,
									int fd[2], int job, int isfork);
int						execscmd(t_astree *root,
									int fd[2], int job, int isfork);

int						execfor(t_astree *root,
									int fd[2], int job, int isfork);
int						execcase(t_astree *root,
									int fd[2], int job, int isfork);
int						execif(t_astree *root,
									int fd[2], int job, int isfork);
int						execsubshell(t_astree *root,
									int fd[2], int job, int isfork);
int						execfunction(t_astree *root);
int						execwhile(t_astree *root,
									int fd[2], int job, int isfork);
int						execuntil(t_astree *root,
									int fd[2], int job, int isfork);

int						function(t_astree *func, char **argv, char **envp);

t_redir					*get_redir(t_astree *root);
int						applyredir(t_list *redirs);

pid_t					xfork(void);
int						xwaitpid(pid_t pid, int options);

int						pipeerror(void);
int						fileerror(char *file);
int						forkerror(char *cmd);
int						threaderror(void);
int						cmdexitsig(pid_t pid, int sig);
t_redir					*redirfileerror(char *file, t_redir *redir);

/*
**	initcmd.c
**	Init command args
*/

int						initcmd(t_astree *root, int fd[2], t_list *cmd[3], char **aven[2]);
int						add_pipe_redir(t_list **redlst, int fd[2]);

#endif
