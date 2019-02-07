/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 15:01:59 by bwerewol          #+#    #+#             */
/*   Updated: 2019/02/07 22:03:16 by bwerewol         ###   ########.fr       */
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
** COMMAND_ELEM
**
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
# define LESS			SHIFT + 13
# define GREAT			SHIFT + 14
# define LESSAND		SHIFT + 15
# define GREATAND		SHIFT + 16
# define DLESS			SHIFT + 17
# define DGREAT			SHIFT + 18
# define LESSGREAT		SHIFT + 19
# define CLOBBER		SHIFT + 20
# define DLESSDASH		SHIFT + 21
# define TLESS			SHIFT + 22
# define ASSIGMENT_WORD	SHIFT + 23
# define NUMBER			SHIFT + 24
# define NEWLINE		SHIFT + 25
# define NOT			SHIFT + 26
# define PIPE			SHIFT + 27
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
# define COPROC			SHIFT + 43
# define COMMAND_ELEM	SHIFT + 44


void	*savecur(unsigned int cur);
t_astree	*freeastree(t_astree	*root);
