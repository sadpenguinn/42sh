#include "builtins.h"
#include "lexer.h"
#include "parser.h"
#include "execute.h"

static int		parse_string(char *script)
{
	t_lexer		*lex;
	t_astree	*ast;
	int 		last;
	char 		*tmp;

	ft_putendl(script);
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

int				built_fc_case_s(char **av, int i, int *flags, void **fc_history)
{
	char	**str;

	str = (char **)vector_front(*fc_history);
	parse_string(*str);
	(void)av;
	(void)i;
	(void)flags;
	(void)fc_history;
}
