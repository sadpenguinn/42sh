/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 15:01:59 by bwerewol          #+#    #+#             */
/*   Updated: 2019/02/10 14:44:16 by bwerewol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include <stdio.h>

void	*xmalloc(size_t bytes);

typedef struct			s_astree
{
	int				type;
	char			*content;
	struct s_astree	*left;
	struct s_astree	*right;
}						t_astree;

extern unsigned int		g_curtok;
extern void				*g_tokens;

/*
**	<|Parser defines|>
**
** (	OBRACKET
** )	CBRACKET
** {	OBRACE
** }	CBRACE
** [	OARRAY
** ]	CARRAY
** !	BANG
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
** COND
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
# define BANG			SHIFT + 7
# define AND			SHIFT + 8
# define SEMI			SHIFT + 9
# define AND_IF			SHIFT + 10
# define OR_IF			SHIFT + 11
# define DSEMI			SHIFT + 12
# define SEMI_AND		SHIFT + 13
# define DSEMI_AND		SHIFT + 14
# define LESS			SHIFT + 15
# define GREAT			SHIFT + 16
# define LESSAND		SHIFT + 17
# define GREATAND		SHIFT + 18
# define DLESS			SHIFT + 19
# define DGREAT			SHIFT + 20
# define LESSGREAT		SHIFT + 21
# define CLOBBER		SHIFT + 22
# define DLESSDASH		SHIFT + 23
# define TLESS			SHIFT + 24
# define ASSIGMENT_WORD	SHIFT + 25
# define NUMBER			SHIFT + 26
# define NEWLINE		SHIFT + 27
# define NOT			SHIFT + 28
# define PIPE			SHIFT + 29
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

t_astree	*simple_list(void);

t_astree	*simple_command(void);
t_astree	*simple_command_element(void);

t_astree	*for_command(void);

t_astree	*case_command(void);
t_astree	*case_clause(void);
t_astree	*case_clause_sequence(void);
t_astree	*pattern_list(void);
t_astree	*pattern(void);

t_astree	*if_command(void);
t_astree	*elif_clause(void);
t_astree	*subshell(void);
t_astree	*arith_command(void);

t_astree	*function_def(void);
t_astree	*function_body(void);

int			simple_list_terminator();	//	Return terminator type if exist and skip it. If no term return 0
int			list_terminator();		//	Return terminator type if exist and skip it. If no term return 0
void		newline_list(void);		//	Skip all \n
t_astree	*word_list(void);

t_astree	*redirection_list(void);
t_astree	*redirection(void);
t_astree	*io_file(void);
t_astree	*filename(void);
t_astree	*io_here(void);
t_astree	*here_end(void);


t_astree	*compound_list(void);

int		check_arith_word(char *str);
int		check_word_type(int type);
int		check_for_word(char *str);
int		check_func_name(char *str);
int		check_redir_num(char *str);
int		check_assigment_word(char *str);
int		checktype(t_type type);
void		*savecur(unsigned int cur);
t_astree	*freeastree(t_astree	*root);
t_astree	*parseerror(void);
