#include "parser.h"

t_astree	*simple_command(void)
{
	t_astree	*root;
	t_astree	*res;

	if ((res = cmd_prefix()))
	{
		if (!(root = cmd_word()))
			return (res);
		root->left = res;
		root->right = cmd_suffix();
		return (root);
	}
	else
	{
		if (!(root = cmd_name()))
			return (0);
		root->right = cmd_suffix();
		return (root);
	}
}
