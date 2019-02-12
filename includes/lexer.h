/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorgil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/30 17:42:57 by dmorgil           #+#    #+#             */
/*   Updated: 2019/02/10 19:54:06 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include <stdlib.h>
# include <string.h>
# include "libft.h"
# include "vector.h"

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

t_lexer						*lexer(char const *str, size_t len);
int							push_token(void **lexems, char *lexem, int state);
char						*push_symbol(char **symbol_table,
														char *str, size_t len);
void						*lexer_die(void *a1, void *a2);

#endif
