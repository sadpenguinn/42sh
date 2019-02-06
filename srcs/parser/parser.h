/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 15:01:59 by bwerewol          #+#    #+#             */
/*   Updated: 2019/02/05 20:55:55 by bwerewol         ###   ########.fr       */
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
** <	LESS
** >	GREAT
** <&	LESSAND
** >&	GREATAND
** <<	DLESS
** >>	DGREAT
** <>	LESSGREAT
** >|	CLOBBER
** <<-	DLESSDASH
** V=W	ASSIGMENT_WORD
** 123	NUMBER
** W	COMMAND
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
# define LESS			SHIFT + 13
# define GREAT			SHIFT + 14
# define LESSAND		SHIFT + 15
# define GREATAND		SHIFT + 16
# define DLESS			SHIFT + 17
# define DGREAT			SHIFT + 18
# define LESSGREAT		SHIFT + 19
# define CLOBBER		SHIFT + 20
# define DLESSDASH		SHIFT + 21
# define ASSIGMENT_WORD	SHIFT + 21
# define NUMBER			SHIFT + 22
# define COMMAND		SHIFT + 23
# define NEWLINE		SHIFT + 24
# define NOT			SHIFT + 25
# define PIPE			SHIFT + 26
# define IF				SHIFT + 27
# define THEN			SHIFT + 28
# define ELSE			SHIFT + 29
# define ELIF			SHIFT + 30
# define FI				SHIFT + 31
# define FOR			SHIFT + 32
# define WHILE			SHIFT + 33
# define UNTIL			SHIFT + 34
# define DO				SHIFT + 35
# define DONE			SHIFT + 36
# define CASE			SHIFT + 37
# define IN				SHIFT + 38
# define ESAC			SHIFT + 39
# define FUNCTION		SHIFT + 40

t_astree	*program(void);
t_astree	*complete_commands(void);
t_astree	*complete_commands_rest(void);
t_astree	*complete_command(void);
t_astree	*list(void);
t_astree	*list_rest(void);
t_astree	*and_or(void);
t_astree	*and_or_rest(void);
t_astree	*and_or2(void);
t_astree	*and_or2_rest(void);
t_astree	*pipeline(void);
t_astree	*pipeline_sequence(void);
t_astree	*pipeline_sequence_rest(void);
t_astree	*command(void);
t_astree	*compound_command(void);
t_astree	*subshell(void);
t_astree	*compound_list(void);
t_astree	*compound_list_rest(void);
t_astree	*separator(void);
t_astree	*separator_op(void);
t_astree	*for_clause(void);
t_astree	*sequential_sep(void);
t_astree	*name(void);
t_astree	*in(void);
t_astree	*wordlist(void);

t_astree	*linebreak(void);
t_astree	*newline_list(void);
t_astree	*simple_command(void);
t_astree	*cmd_name(void);
t_astree	*cmd_word(void);
t_astree	*cmd_prefix(void);
t_astree	*cmd_suffix(void);
t_astree	*io_redirect(void);
t_astree	*io_file(void);
t_astree	*filename(void);
t_astree	*io_here(void);
t_astree	*here_end(void);

void	*savecur(unsigned int cur);
