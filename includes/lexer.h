/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorgil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/30 17:42:57 by dmorgil           #+#    #+#             */
/*   Updated: 2019/02/02 19:20:48 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include <stdlib.h>
# include <string.h>
# include "libft.h"
# include "vector.h"

# define TERM_WORD 0 /* word */
# define TERM_AND_IF 1 /* && */
# define TERM_OR_IF 2 /* || */
# define TERM_DLESSDASH 3 /* <<- */
# define TERM_DLESS 4 /* << */
# define TERM_DGREAT 5 /* >> */
# define TERM_LESSAND 6 /* <& */
# define TERM_GREATAND 7 /* &> */
# define TERM_LESSGREAT 8 /* <> */
# define TERM_CLOBBER 9 /* >| */
# define TERM_LESS 10 /* < */
# define TERM_GREAT 11 /* > */
# define TERM_LBRACE 12 /* { */
# define TERM_RBRACE 13 /* } */
# define TERM_DBL_LBRACKET 14 /* [[ */
# define TERM_DBL_RBRACKET 15 /* ]] */
# define TERM_DBL_LPARENTHESIS 16 /* (( */
# define TERM_DBL_RPARENTHESIS 17 /* )) */
# define TERM_LBRACKET 18 /* [ */
# define TERM_RBRACKET 19 /* ] */
# define TERM_LPARENTHESIS 20 /* ( */
# define TERM_RPARENTHESIS 21 /* ) */
# define TERM_SEMI 22 /* ; */
# define TERM_SINGLE_QUOTE 23 /* ' */
# define TERM_QUOTE 24 /* ' */
# define TERM_HASH 25 /* # */
# define TERM_IF 26 /* if */
# define TERM_THEN 27 /* then */
# define TERM_ELSE 28 /* else */
# define TERM_ELIF 29 /* elif */
# define TERM_FI 30 /* fi */
# define TERM_DO 31 /* do */
# define TERM_DONE 32 /* done */
# define TERM_CASE 33 /* case */
# define TERM_ESAC 34 /* esac */
# define TERM_WHILE 35 /* while */
# define TERM_UNTIL 36 /* until */
# define TERM_FOR 37 /* for */
# define TERM_FUNCTION 38 /* function */
# define TERM_IN 39 /* in */

extern char					*g_delims[];
extern int					g_delims_len[];
extern char					*g_terminals[];

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
int							push_token(void **lexems, char *lexem);
char						*push_symbol(char **symbol_table, char *str, size_t len);
int							is_delim(char c);
char						*strsstr(const char *s1, const char *s2);
int							get_type(char *lexems);
void						*lexer_die(void *a1, void *a2, void *a3);
char						*trim_quotes(char *str);

void						print_token(void *lexem);

#endif
