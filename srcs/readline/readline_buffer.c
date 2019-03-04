#include "readline.h"
#include "shell.h"

char	*get_buffer_content(void)
{
	return (g_history->str->buf);
}

int		get_buffer_len(void)
{
	return (g_history->str->len);
}

void	buffer_free(void)
{
	free(g_history->str->buf);
	g_history->str->len = 0;
}

void	buffer_add(const char *str, int size)
{
	g_history->str->buf = (char *)xmalloc(sizeof(char) * size);
	g_history->str->len = size;
	ft_memcpy(g_history->str->buf, str, size);
}