#include "builtins.h"
#include "readline.h"
#include "libft.h"

int	built_fc_case_e(char **av, int i, int *flags, void *fc_history)
{
	int		fd;
	char	*file_name;
	size_t	len;
	char	*script;

	fd = built_fc_open_tmp_file(&file_name);
	built_fc_write_lines(fc_history, fd, flags, av + i + 1);
	close(fd);
	array_add(av[i], ft_strlen(av[i]));
	array_add(" ", 1);
	array_add(file_name, ft_strlen(file_name));
	script = array_to_string();
	built_fc_parse_string(script, 0);
	free(script);
	len = get_file_size(file_name);
	script = (char *)xmalloc((sizeof(char) * (len + 1)));
	fd = open(file_name, O_CREAT | O_RDONLY, 0777);
	read(fd, script, len + 1);
	close(fd);
	built_fc_parse_string(script, 1);
	free(script);
	free(file_name);
	built_fc_write_history_changes();
	return (1);
}
