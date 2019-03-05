#include "expression.h"

unsigned int		g_excurtok = 0;
void				*g_extokens = NULL;

long int	expression(char *arg)
{
	t_lexer		*lexer;
	t_astree	*ast;
  
	lexer = exprlexer(arg, ft_strlen(arg));
	g_extokens = lexer->lexems;
	ast = expr();
	return (exprexecute(ast));
}
