#include "expression.h"

unsigned int		g_excurtok = 0;
void				*g_extokens = NULL;

long int	expression(char *arg)
{
	t_lexer		*lexer;
	t_astree	*root;

	lexer = exprlexer(arg, ft_strlen(arg));
	g_extokens = lexer->lexems;
	g_excurtok = 0;
	root = expr();
	print_astree(root);
	/* return (exprexecute(ast)); */
	return (0);
}
