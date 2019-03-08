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

int			history_save_elem(t_string *str)
{
	int ret;

	matrix_to_string(g_history->matrix[g_history->cur],
					 g_history->matrix[g_history->cur]->str_history);
	if (g_history->matrix[g_history->cur]->str_history->buf[0] == '\0')
		ret = 1;
	else
	{
		if (!(g_history->len - 1 &&
			matrix_cmp(g_history->matrix[g_history->cur],
					   g_history->last_hst_matrix) == 0))
			write_history_on_disk(g_history->matrix[g_history->cur]->str_history);
		matrix_to_string(g_history->matrix[g_history->cur], str);
		ret = 0;
	}
	history_del(&g_history);
	return (ret);
}
