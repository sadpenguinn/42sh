#include "shell.h"
#include "builtins.h"
#include "get_next_line.h"
#include "readline.h"
#include <pwd.h>

static void	fc_read_history_from_disk(void **vector)
{
	int				fd;
	char			*file_name;
	struct passwd	*pw;
	char			*str;

	pw = getpwuid(getuid());
	file_name = ft_strjoin(pw->pw_dir, "/", 0);
	file_name = ft_strjoin(file_name, HISTORY_FILE, 1);
	fd = open(file_name, O_CREAT | O_RDONLY | O_APPEND, 0777);
	while ((get_next_line(fd, &str)))
		vector_push_back(vector, &str);
	close(fd);
	free(file_name);
}

static void	fc_history_free(void *fc_history)
{
	char	**str;
	size_t	len;
	size_t	i;

	i = 0;
	len = vector_get_len(fc_history);
	while (i < len)
	{
		str = (char **)vector_get_elem(fc_history, i);
		free(*str);
		i++;
	}
}

static int	parse_flags(char **av, int *flags, int i, int k)
{
	while (av[i] && av[i][0] == '-')
	{
		k = 0;
		while (av[i][++k])
		{
			if (av[i][k] != 'e' && av[i][k] != 'r' && av[i][k] != 'l'
			&& av[i][k] != 'n' && av[i][k] != 's')
				return (i);
			if (flags[0] || flags[4] || (av[i][k] == 's' && i > 1)
			|| (av[i][k] == 'e' && (flags[2] || flags[3] || flags[4])))
				return (built_fc_usage(FC_ERROR_FLAGS));
			if (av[i][k] == 'e')
				flags[0] = 1;
			else if (av[i][k] == 'r')
				flags[1] = 1;
			else if (av[i][k] == 'n')
				flags[2] = 1;
			else if (av[i][k] == 'l')
				flags[3] = 1;
			else if (av[i][k] == 's')
				flags[4] = 1;
		}
		i++;
	}
	return (i);
}

static int	run_fc(char **av, int i, int *flags, void *fc_history)
{
	int	cnt;

	cnt = i;
	while (av[cnt])
		cnt++;
	if (flags[0])
	{
		if (cnt - i > 3)
			return (built_fc_usage(FC_ERROR_ARGS));
		if (cnt == i)
			return (built_fc_usage(FC_ERROR_FLAGS));
		return (built_fc_case_e(av, i, flags, fc_history));
	}
	if (cnt - i > 2)
		return (built_fc_usage(FC_ERROR_ARGS));
	if (flags[3])
		return (built_fc_case_l(av, i, flags, fc_history));
	if (flags[4])
		return (built_fc_case_s(av, i, flags, fc_history));
	return (built_fc_case_default(av, i, flags, fc_history));
}

int			built_fc(char **av, char **env)
{
	int		flags[5];
	void	*fc_history;
	int		ret;

	env = NULL;
	ft_memset(flags, 0, sizeof(int) * 5);
	fc_history = vector_create(sizeof(void *));
	fc_read_history_from_disk(&fc_history);
	ret = parse_flags(av, flags, 1, 0);
	if (ret == 0)
	{
		fc_history_free(fc_history);
		vector_free(&fc_history);
		return (SHERR_OK);
	}
	run_fc(av, ret, flags, fc_history);
	fc_history_free(fc_history);
	vector_free(&fc_history);
	return (SHERR_OK);
}
