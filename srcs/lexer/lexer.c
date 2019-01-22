/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorgil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/30 17:41:24 by dmorgil           #+#    #+#             */
/*   Updated: 2019/01/18 15:11:30 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/lexer.h"
#include "headers/lexer_tools.h"

char			*g_delims[] = {	"\\", " ", "\t", "\n", "&&", "||", ";;", "<<-",
								"<<", ">>", "<&", "&>", "<>", ">|", "<", ">",
								"{", "}", "[[", "]]", "((", "))", "[", "]",
								"(", ")", ";", "\'", "\"", "#", NULL		};

int				g_delims_len[] = {	1, 1, 1, 1, 2, 2, 2, 3,
									2, 2, 2, 2, 2, 2, 1, 1,
									1, 1, 2, 2, 2, 2, 1, 1,
									1, 1, 1, 1, 1, 1						};

char			*g_terminals[] = {	"&&", "||", ";;", "<<-", "<<", ">>", "<&",
									"&>", "<>", ">|", "<", ">", "{", "}", "[[",
									"]]", "((", "))", "[", "]", "(", ")", ";",
									"\'", "\"", "#", "if", "then", "else",
									"elif", "fi", "do", "done", "case", "esac",
									"while", "until", "for", "function", "in",
									NULL									};

static char		*push_symbol(char **lexstr, char **symbol_table, int len)
{
	char	*tmp;

	tmp = *symbol_table;
	if (!len)
	{
		while (**lexstr)
		{
			if (**lexstr != '\\')
			{
				**symbol_table = **lexstr;
				(*symbol_table)++;
			}
			(*lexstr)++;
		}
		**symbol_table = '\0';
		(*symbol_table) += 2;
		return (tmp);
	}
	while (**lexstr && len)
	{
		if (**lexstr != '\\')
		{
			**symbol_table = **lexstr;
			(*symbol_table)++;
		}
		(*lexstr)++;
		len--;
	}
	**symbol_table = '\0';
	(*symbol_table) += 2;
	return (tmp);
}

static int		find_first_delim(char *lexstr, int *delim)
{
	char	*entry;
	int		i;

	i = 0;
	while (lexstr[i])
	{
		(*delim) = 0;
		while (g_delims[*delim])
		{
			if ((entry = strsstr(&(lexstr[i]), g_delims[*delim])))
			{
				if (g_delims[*delim][0] == '\\')
				{
					i += 2;
					continue;
				}
				return (i);
			}
			(*delim)++;
		}
		i++;
	}
	return (-1);
}

static int		push_lexem_in_quotes(char **lexstr, void **lexems, char **symbol_table)
{
	int		last_quote;
	char	*lexem;
	char	*tmp;

	if ((*lexstr)[0] == (*lexstr)[1])
	{
		*lexstr += 2;
		return (1);
	}
	if (!(tmp = ft_strchr(&((*lexstr)[1]), (*lexstr)[0])))
		return (0);
	last_quote = tmp - *lexstr;
	*lexstr += 1;
	if (!(lexem = push_symbol(lexstr, symbol_table, last_quote - 1)))
		return (0);
	if (!(push_token(lexems, lexem)))
		return (0);
	*lexstr += 1;
	return (1);
}

static int		push_terminal(char **lexstr, void **lexems, int delim, char **symbol_table)
{
	if (delim == 1 || delim == 2 || delim == 3)
	{
		*lexstr += 1;
		return (1);
	}
	if (delim == 27 || delim == 28)
		return (push_lexem_in_quotes(lexstr, lexems, symbol_table));
	*lexstr += g_delims_len[delim];
	return (push_token(lexems, g_delims[delim]));
}

static int		build_lexems(char *lexstr, void **lexems, char *symbol_table)
{
	char	*lexem;
	int		index;
	int		delim;

	while (*lexstr)
	{
		if ((index = find_first_delim(lexstr, &delim)) != -1)
		{
			if (index > 0)
			{
				lexem = push_symbol(&lexstr, &symbol_table, index);
				if (!(push_token(lexems, lexem)))
					return (0);
			}
			if (!(push_terminal(&lexstr, lexems, delim, &symbol_table)))
				return (0);
		}
		else
		{
			lexem = push_symbol(&lexstr, &symbol_table, -1);
			if (!(push_token(lexems, lexem)))
				return (0);
			break ;
		}
	}
	return (1);
}

t_lexer				*lexer(char const *str)
{
	t_lexer		*lexer;
	void		*lexems;
	char		*symbol_table;
	char		*lexstr;

	if (!(lexstr = trim_quotes((char *)str)))
		return (NULL);
	if (!(lexems = vector_create(sizeof(t_lexem))))
		return (lexer_die(lexstr, NULL, NULL));
	if (!(symbol_table = (char *)malloc(ft_strlen(lexstr) * 2)))
		return (lexer_die(lexstr, lexems, NULL));
	if (!(build_lexems(lexstr, &lexems, symbol_table)))
		return (lexer_die(lexstr, lexems, symbol_table));
	if (!(lexer = (t_lexer *)malloc(sizeof(t_lexer))))
		return (lexer_die(lexstr, lexems, symbol_table));
	lexer->lexems = lexems;
	lexer->symbol_table = symbol_table;
	free(lexstr);
	return (lexer);
}
