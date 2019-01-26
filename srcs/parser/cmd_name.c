#include "parser.h"

t_astree	*cmd_name(void)
{
	t_lexem		*token;
	t_astree	*root;

	if (g_curtok >= ((size_t *)g_tokens)[2])
		return (0);
	token = ((t_lexem *)vector_get_elem(g_tokens, g_curtok));
	if (token->type != WORD)
		return (0);
	if (!(root = ft_memalloc(sizeof(t_astree))))
		return (0);
	root->type = WORD;
	root->content = ft_strdup(token->word);
	return (root);
}
