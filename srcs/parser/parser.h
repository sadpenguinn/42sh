/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 15:01:59 by bwerewol          #+#    #+#             */
/*   Updated: 2019/02/15 20:03:20 by bwerewol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "vector.h"
#include "shell.h"
#include <stdio.h>

void	*xmalloc(size_t bytes);

extern unsigned int		g_curtok;
extern void				*g_tokens;
extern int				g_parseerr;

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
# define LESS			SHIFT + 12
# define GREAT			SHIFT + 13
# define LESSAND		SHIFT + 14
# define GREATAND		SHIFT + 15
# define DLESS			SHIFT + 16
# define DGREAT			SHIFT + 17
# define LESSGREAT		SHIFT + 18
# define CLOBBER		SHIFT + 19
# define DLESSDASH		SHIFT + 20
# define TLESS			SHIFT + 21
# define ASSIGMENT_WORD	SHIFT + 22
# define NUMBER			SHIFT + 23
# define NEWLINE		SHIFT + 24
# define NOT			SHIFT + 25
# define PIPE			SHIFT + 26
# define PIPEAND		SHIFT + 27
# define IF				SHIFT + 28
# define THEN			SHIFT + 29
# define ELSE			SHIFT + 30
# define ELIF			SHIFT + 31
# define FI				SHIFT + 32
# define FOR			SHIFT + 33
# define WHILE			SHIFT + 34
# define UNTIL			SHIFT + 35
# define DO				SHIFT + 36
# define DONE			SHIFT + 37
# define CASE			SHIFT + 38
# define IN				SHIFT + 39
# define ESAC			SHIFT + 40
# define FUNCTION		SHIFT + 41
# define SELECT			SHIFT + 42
# define COMMAND 		SHIFT + 43
# define REDIRECTION	SHIFT + 44
# define TOKEOF			SHIFT + 45
# define ARITH			SHIFT + 46
# define COND			SHIFT + 47
# define REST			SHIFT + 48
# define LIST1			SHIFT + 49
# define LIST2			SHIFT + 50
# define LIST3			SHIFT + 51
# define CMDREDIR		SHIFT + 52
# define PIPECMD		SHIFT + 53


t_astree	*inputunit(void);
t_astree	*simple_list1(void);
t_astree	*simple_list2(void);
t_astree	*simple_list3(void);
t_astree	*pipeline_command(void);
t_astree	*pipeline(void);
t_astree	*command(void);
t_astree	*simple_command(void);
t_astree	*simple_command_element(void);
t_astree	*shell_command(void);
t_astree	*for_command(void);
t_astree	*case_command(void);
t_astree	*case_clause(void);
t_astree	*case_clause_sequence(void);
t_astree	*pattern_list(void);
t_astree	*pattern(void);
t_astree	*select_command(void);
t_astree	*if_command(void);
t_astree	*elif_clause(void);
t_astree	*group_command(void);
t_astree	*subshell(void);
t_astree	*arith_command(void);
t_astree	*cond_command(void);
t_astree	*arith_for_command(void);
t_astree	*function_def(void);
t_astree	*function_body(void);
t_astree	*compound_list(void);
t_astree	*list1(void);
t_astree	*list2(void);
t_astree	*list3(void);
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

int		check_select_word(char *str);
int		check_arith_for(char *str);
int		check_arith_word(char *str);
int		check_word_type(t_type type);
int		check_for_word(char *str);
int		check_func_name(char *str);
int		check_redir_num(char *str);
int		check_assigment_word(const char *str);
int		checktype(t_type type);
void		*savecur(unsigned int cur);
t_astree	*freeastree(t_astree	*root);
t_astree	*parseerror(void);
