#include "expression.h"
#include "lexer.h"
#include "exprlexer.h"
#include "expr.h"

unsigned int		g_excurtok;
void				*g_extokens = NULL;
int					g_exprerr;

void				exprlexer_print(void *lexems);


char				*expression(char *arg)
{
	t_lexer		*lexer;
	t_astree	*root;
	intmax_t	res;

	lexer = exprlexer(arg, ft_strlen(arg));
	exprlexer_print(lexer->lexems);
	g_extokens = lexer->lexems;
	g_excurtok = 0;
	g_exprerr = 0;
	root = expr();
	if (g_exprerr)
		return ((char *)0);
	if (!root)
		return (ft_itoa(0));
	res = calc(root);
	if (g_exprerr)
	{
		exfreeastree(root);
		return ((char *)0);
	}
	lexer_free(lexer);
	exfreeastree(root);
	return (ft_itoa(res));
}
