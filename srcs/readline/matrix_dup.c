#include "readline.h"
#include "libshell.h"

t_matrix	*matrix_dup(t_matrix *src)
{
	int			i;
	t_matrix	*dest;

	if (src == NULL)
		return (NULL);
	dest = (t_matrix *)xmalloc(sizeof(t_matrix));
	dest->size = src->size;
	dest->lines = (t_line **)xmalloc(sizeof(t_line *) * dest->size);
	dest->cursor = cursor_dup(src->cursor);
	dest->str_history = string_dup(src->str_history);
	dest->len = src->len;
	dest->left_limit = src->left_limit;
	dest->right_limit = src->right_limit;
	dest->single_quotes = src->single_quotes;
	dest->double_quotes = src->double_quotes;
	i = 0;
	while (i < src->len)
	{
		dest->lines[i] = line_dup(src->lines[i]);
		i++;
	}
	return (dest);
}
