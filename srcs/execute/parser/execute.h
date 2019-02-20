/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 16:27:11 by bwerewol          #+#    #+#             */
/*   Updated: 2019/02/20 16:25:48 by bwerewol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "libft.h"
/* #include "parser.h" */
#include <stdio.h>
extern int	g_execerr;

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

/*
**	compound_list -> exexlist1
*/

int		execlist1(t_astree *root, int fd[2], int job);
int		execlist2(t_astree *root, int fd[2], int job);
int		execlist3(t_astree *root, int fd[2], int job);
int		execpipecmd(t_astree *root, int fd[2], int job);
int		execpipes(t_astree	*root, int fd[2], int job);
int		execcmd(t_astree *root, int fd[2], int job, int pipe);

int		execcase(t_astree *root, int fd[2], int job);
int		execif(t_astree *root, int fd[2], int job);

int		subshell(t_astree *root, int fd[2], int job);
int		function(t_astree *func, char **argv, int fd[2], int job);

# define EX_NOFG	0
# define EX_FG		1

t_redir	*get_redir(t_astree *root);

int pipeerror(void);
int fileerror(char *file);
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
# define WORD 0
# define FORBRACKET 5

# define SHIFT					100
# define OBRACKET		SHIFT + 1
# define CBRACKET		SHIFT + 2
# define OBRACE			SHIFT + 3
# define CBRACE			SHIFT + 4
# define OARRAY			SHIFT + 5
# define CARRAY			SHIFT + 6
# define AND			SHIFT + 7
# define SEMI			SHIFT + 8
# define AND_IF			SHIFT + 9
# define OR_IF			SHIFT + 10
# define DSEMI			SHIFT + 11
# define SEMI_AND		SHIFT + 12
# define DSEMI_AND		SHIFT + 13
# define LESS			SHIFT + 14
# define GREAT			SHIFT + 15
# define LESSAND		SHIFT + 16
# define GREATAND		SHIFT + 17
# define DLESS			SHIFT + 18
# define DGREAT			SHIFT + 19
# define LESSGREAT		SHIFT + 20
# define CLOBBER		SHIFT + 21
# define DLESSDASH		SHIFT + 22
# define TLESS			SHIFT + 23
# define ASSIGMENT_WORD	SHIFT + 24
# define NUMBER			SHIFT + 25
# define NEWLINE		SHIFT + 26
# define NOT			SHIFT + 27
# define PIPE			SHIFT + 28
# define PIPEAND		SHIFT + 29
# define IF				SHIFT + 30
# define THEN			SHIFT + 31
# define ELSE			SHIFT + 32
# define ELIF			SHIFT + 33
# define FI				SHIFT + 34
# define FOR			SHIFT + 35
# define WHILE			SHIFT + 36
# define UNTIL			SHIFT + 37
# define DO				SHIFT + 38
# define DONE			SHIFT + 39
# define CASE			SHIFT + 40
# define IN				SHIFT + 41
# define ESAC			SHIFT + 42
# define FUNCTION		SHIFT + 43
# define SELECT			SHIFT + 44
# define COMMAND 		SHIFT + 45
# define REDIRECTION	SHIFT + 46
# define TOKEOF			SHIFT + 47
# define ARITH			SHIFT + 48
# define COND			SHIFT + 49
# define REST			SHIFT + 50
# define LIST1			SHIFT + 51
# define LIST2			SHIFT + 52
# define LIST3			SHIFT + 53
# define CMDREDIR		SHIFT + 54
# define PIPECMD		SHIFT + 55
