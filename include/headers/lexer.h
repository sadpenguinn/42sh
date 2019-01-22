/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorgil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/30 17:42:57 by dmorgil           #+#    #+#             */
/*   Updated: 2019/01/17 17:18:26 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include <stdlib.h>
# include <string.h>
# include "libft.h"
# include "vector.h"

enum				e_terminals
{
	WORD, /* word */
	AND_IF, /* && */
	OR_IF, /* || */
	DSEMI, /* ;; */
	DLESSDASH, /* <<- */
	DLESS, /* << */
	DGREAT, /* >> */
	LESSAND, /* <& */
	GREATAND, /* &> */
	LESSGREAT, /* <> */
	CLOBBER, /* >| */
	LESS, /* < */
	GREAT, /* > */
	LBRACE, /* { */
	RBRACE, /* } */
	DBL_LBRACKET, /* [[ */
	DBL_RBRACKET, /* ]] */
	DBL_LPARENTHESIS, /* (( */
	DBL_RPARENTHESIS, /* )) */
	LBRACKET, /* [ */
	RBRACKET, /* ] */
	LPARENTHESIS, /* ( */
	RPARENTHESIS, /* ) */
	SEMI, /* ; */
	SINGLE_QUOTE, /* ' */
	QUOTE, /* ' */
	HASH, /* # */
	IF, /* if */
	THEN, /* then */
	ELSE, /* else */
	ELIF, /* elif */
	FI, /* fi */
	DO, /* do */
	DONE, /* done */
	CASE, /* case */
	ESAC, /* esac */
	WHILE, /* while */
	UNTIL, /* until */
	FOR, /* for */
	FUNCTION, /* function */
	IN, /* in */
};

typedef unsigned long int	t_type;

typedef struct				s_lexem
{
	t_type					type;
	char					*word;
}							t_lexem;

typedef struct				s_lexer
{
	void		*lexems;
	char		*symbol_table;
	
}							t_lexer;

t_lexer						*lexer(char const *str);

#endif
