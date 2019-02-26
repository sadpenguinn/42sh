/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 16:27:11 by bwerewol          #+#    #+#             */
/*   Updated: 2019/02/26 17:32:22 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "libft.h"
/* #include "parser.h" */
#include <stdio.h>
#include "pthread.h"
extern int	g_execerr;

/* #define EXECUTE_DEBUG */
/*
** redir types and struct
*/

# define REDIRECT		1
# define CLOSEFD		2

typedef struct	s_redir
{
	int		type;
	int		fd[2];
}				t_redir;

typedef struct	s_cmd
{
	t_astree	*root;
	void 		*ppid;
	int			fd[2];
	int			job;
}				t_cmd;

int		execute(t_astree *root);
int		execlist1(t_astree *root, int fd[2], int job, int isfork);
int		execlist2(t_astree *root, int fd[2], int job, int isfork);
int		execlist3(t_astree *root, int fd[2], int job, int isfork);
int		execpipecmd(t_astree *root, int fd[2], int job, int isfork);
int		execpipes(t_astree	*root, int fd[2], int job, int isfork);
int		execcmd(t_astree *root, int fd[2], int job, int isfork);
int		execscmd(t_astree *root, int fd[2], int job, int isfork);

int		execcase(t_astree *root, int fd[2], int job, int isfork);
int		execif(t_astree *root, int fd[2], int job, int isfork);
int		execsubshell(t_astree *root, int fd[2], int job, int isfork);
int		function(t_astree *func, char **argv, int fd[2], int job, int isfork);

# define EX_NOFG	0
# define EX_FG		1

t_redir	*get_redir(t_astree *root);

int pipeerror(void);
int fileerror(char *file);
int forkerror(char *cmd);
int threaderror(void);
/*
**	<|Parser defines|>
**
** (	OBRACKET
** )	CBRACKET
** {	OBRACE
** }	CBRACE
** [	OARRAY
** ]	CARRAY
** &	AND
** ;	SEMI
** &&	AND_IF
** ||	OR_IF
** ;;	DSEMI
** ;&	SEMI_AND
** ;;&	DSEMI_AND
** <	LESS
** >	GREAT
** <&	LESSAND
** >&	GREATAND
** <<	DLESS
** >>	DGREAT
** <>	LESSGREAT
** >|	CLOBBER
** <<-	DLESSDASH
** <<<	TLESS
** V=W	ASSIGMENT_WORD
** 123	NUMBER
** \n	NEWLINE
** !	NOT
** |	PIPE
** |&	PIPEAND
** IF
** THEN
** ELSE
** ELIF
** FI
** FOR
** WHILE
** UNTIL
** DO
** DONE
** CASE
** IN
** ESAC
** FUNCTION
** SELECT
** COPROC
**
** COMMAND
** REDIRECTION
** TOKEOF
** ARITH
** COND			[[ ... ]]
** REST
** CMDREDIR
** PIPECMD
**
*/

