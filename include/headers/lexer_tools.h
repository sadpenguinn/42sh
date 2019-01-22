/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_tools.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/02 15:56:44 by nkertzma          #+#    #+#             */
/*   Updated: 2019/01/18 14:40:18 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_TOOLS_H
# define LEXER_TOOLS_H

# include <string.h>
# include "libft.h"

extern char		*g_delims[];
extern int		g_delims_len[];
extern char		*g_terminals[];

int				push_token(void **lexems, char *lexem);
int				is_delim(char c);
char			*strsstr(const char *s1, const char *s2);
int				get_type(char *lexems);
void			*lexer_die(void *a1, void *a2, void *a3);
char			*trim_quotes(char *str);

#endif
