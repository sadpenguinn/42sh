#include "expression.h"

unsigned int		g_excurtok;
void				*g_extokens = NULL;
int					g_exprerr;

void			exprlexer_print(void *lexems);

long int	expression(char *arg)
{
	t_lexer		*lexer;
	t_astree	*root;

	lexer = exprlexer(arg, ft_strlen(arg));
	exprlexer_print(lexer->lexems);
	g_extokens = lexer->lexems;
	g_excurtok = 0;
	g_exprerr = 0;
	root = expr();
	print_astree(root);
	/* return (exprexecute(ast)); */
	return (0);
}

int main(int ac, char **av)
{
	expression(av[ac-1]);
}
