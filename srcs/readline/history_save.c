#include "readline.h"
#include <pwd.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "libft.h"

static void	write_history_on_disk(t_string *str)
{
	int				fd;
	char			*file_name;
	struct passwd	*pw;

	pw = getpwuid(getuid());
	file_name = ft_strjoin(pw->pw_dir, "/", 0);
	file_name = ft_strjoin(file_name, HISTORY_FILE, 1);
	fd = open(file_name, O_CREAT | O_WRONLY | O_APPEND, 0777);
	write(fd, str->buf, str->len);
	write(fd, "\n", 1);
	close(fd);
	free(file_name);
}

int			history_save_elem(void)
{
	if (g_history->cur_matrix->str_history->buf[0] == '\0')
	{
		matrix_del(&g_history->matrix[g_history->len - 1]);
		matrix_del(&g_history->cur_matrix);
		g_history->len--;
		return (1);
	}
	if (g_history->len - 1 &&
		matrix_cmp(g_history->cur_matrix,
				   g_history->matrix[g_history->len - 2]) == 0)
	{
		matrix_del(&g_history->matrix[g_history->len - 1]);
		matrix_del(&g_history->cur_matrix);
		g_history->len--;
		return (0);
	}
	matrix_del(&g_history->matrix[g_history->len - 1]);
	g_history->matrix[g_history->len - 1] = matrix_dup(g_history->cur_matrix);
	matrix_del(&g_history->cur_matrix);
	write_history_on_disk(g_history->matrix[g_history->len - 1]->str_history);
	return (0);
}
