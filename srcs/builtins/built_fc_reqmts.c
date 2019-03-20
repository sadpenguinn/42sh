/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_fc_reqmts.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 15:29:56 by narchiba          #+#    #+#             */
/*   Updated: 2019/03/20 15:31:08 by narchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "readline.h"
#include "vector.h"
#include "libft.h"
#include "lexer.h"
#include "parser.h"
#include "execute.h"
#include <pwd.h>

int		built_fc_open_tmp_file(char **file_name)
{
	int				fd;
	struct passwd	*pw;

	pw = getpwuid(getuid());
	*file_name = ft_strjoin(pw->pw_dir, "/", 0);
	*file_name = ft_strjoin(*file_name, BUILTT_FC_TMP_FILE, 1);
	fd = open(*file_name, O_CREAT | O_TRUNC | O_WRONLY, 0777);
	return (fd);
}

int		built_fc_parse_string(char *script, int print)
{
	t_lexer		*lex;
	t_astree	*ast;
	int			last;
	char		*tmp;

	if (print)
		ft_putstr(script);
	lex = lexer(script, ft_strlen(script));
	g_tokens = lex->lexems;
	ast = inputunit();
	last = execute(ast);
	tmp = ft_itoa(last);
	ssetenv("?", tmp, ENV_RO);
	ft_strdel(&tmp);
	freeastree(ast);
	lexer_free(lex);
	return (1);
}

void	built_fc_swap_limits(size_t *left_limit, size_t *right_limit)
{
	size_t	tmp;

	tmp = *right_limit;
	*right_limit = *left_limit;
	*left_limit = tmp;
}

void	built_fc_set_limits_default(size_t *left_limit, size_t *right_limit,
		void *fc_history, int *flags)
{
	*right_limit = vector_get_len(fc_history);
	if (*right_limit - 1)
		(*right_limit) -= 2;
	if (flags[3])
	{
		if (*right_limit < 15)
			*left_limit = 0;
		else
			*left_limit = *right_limit - 14;
	}
	else
	{
		*left_limit = *right_limit;
	}
}

int		built_fc_usage(int error)
{
	if (error == FC_ERROR_FLAGS)
	{
		array_add("fc usage: \n", ft_strlen("fc usage: \n"));
		array_add("  fc [-r] [-e editor] [first [last]]\n",
				ft_strlen("  fc [-r] [-e editor] [first [last]]\n"));
		array_add("  fc -l [-nr] [first [last]]\n",
				ft_strlen("  fc -l [-nr] [first [last]]\n"));
		array_add("  fc -s [old=new] [first]\n",
				ft_strlen("  fc -s [old=new] [first]\n"));
	}
	if (error == FC_ERROR_ARGS)
		array_add("fc: too many arguments\n",
				ft_strlen("fc: too many arguments\n"));
	if (error == FC_ERROR_EVENT)
		array_add("fc: no such event\n", ft_strlen("fc: no such event\n"));
	array_flush();
	return (0);
}
