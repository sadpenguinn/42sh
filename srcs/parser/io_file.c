#include "parser.h"

t_astree        *io_file(void)
{
	int				type;
	t_astree        *root;
	t_astree        *res;

	if (g_curtok >= ((size_t *)g_tokens)[2])
		return (0);
	type = ((t_lexem *)vector_get_elem(g_tokens, g_curtok))->type;
	if (type != LESS && type != LESSAND &&
		type != GREAT && type != GREATAND &&
		type != DGREAT && type != LESSGREAT && type != CLOBBER)
		return (0);
	g_curtok++;
	if (!(root = ft_memalloc(sizeof(t_astree))))
		return (0);
	root->type = type;
	if ((root->right = filename()))
		return (root);
	free(root);
	return (0);
}

