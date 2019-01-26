#include "parser.h"

t_astree        *cmd_suffix_1(void)
{
	t_astree        *root;

	if (!(root = ft_memalloc(sizeof(t_astree))))
		return (0);
	root->type = WORD;
	root->content = ft_strdup(((t_lexem *)vector_get_elem(g_tokens, g_curtok++))->word);
	return (root);
}

t_astree        *cmd_suffix(void)
{
	t_astree        *root;
	t_astree        *res;

	if (g_curtok >= ((size_t *)g_tokens)[2])
		return (0);
	if (((t_lexem *)vector_get_elem(g_tokens, g_curtok))->type ==
			WORD)
		res = cmd_suffix_1();
	else
		res = io_redirect();
	if (!res)
		return (0);
	if (!(root = ft_memalloc(sizeof(t_astree))))
		return (0);
	root->left = res;
	root->right = cmd_suffix();
	return (root);
}
