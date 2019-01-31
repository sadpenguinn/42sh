/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 15:01:59 by bwerewol          #+#    #+#             */
/*   Updated: 2019/01/31 18:51:38 by bwerewol         ###   ########.fr       */
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
** !	BANG
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
**
*/

# define SHIFT					100
# define BANG			SHIFT + 1
# define AND_IF			SHIFT + 2
# define OR_IF			SHIFT + 3
# define DSEMI			SHIFT + 4
# define LESS			SHIFT + 5
# define GREAT			SHIFT + 6
# define LESSAND		SHIFT + 7
# define GREATAND		SHIFT + 8
# define DLESS			SHIFT + 9
# define DGREAT			SHIFT + 10
# define LESSGREAT		SHIFT + 11
# define CLOBBER		SHIFT + 12
# define DLESSDASH		SHIFT + 13
# define ASSIGMENT_WORD	SHIFT + 13
# define NUMBER			SHIFT + 14
# define COMMAND		SHIFT + 15
# define NEWLINE		SHIFT + 16
# define NOT			SHIFT + 17
# define PIPE			SHIFT + 18

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
