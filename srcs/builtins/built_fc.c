#include "shell.h"
#include "builtins.h"
#include "get_next_line.h"
#include "readline.h"
#include <pwd.h>
#include "lexer.h"
#include "parser.h"
#include "execute.h"

static void	read_history_from_disk(void **vector)
{
	int				fd;
	char			*file_name;
	struct passwd	*pw;
	int				ret;
	char			*str;

	pw = getpwuid(getuid());
	file_name = ft_strjoin(pw->pw_dir, "/", 0);
	file_name = ft_strjoin(file_name, HISTORY_FILE, 1);
	fd = open(file_name, O_CREAT | O_RDONLY | O_APPEND, 0777);
	while ((ret = get_next_line(fd, &str)))
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

static int		parse_string(char *script)
{
	t_lexer		*lex;
	t_astree	*ast;
	int 		last;
	char 		*tmp;

	ft_putendl(script);
	lex = lexer(script, ft_strlen(script));
	g_tokens = lex->lexems;
	ast = inputunit();
	last = execute(ast);
	tmp = ft_itoa(last);
	ssetenv("?", tmp, ENV_RO);
	ft_strdel(&tmp);
	freeastree(ast);
	lexer_free(lex);
	return (1);
}

int			built_fc(char **av, char **env)
{
	int		flags[4];
	void	*fc_history;
	char	**str;

	env = NULL;
	fc_history = vector_create(sizeof(void *));
	read_history_from_disk(&fc_history);
	str = (char **)vector_front(fc_history);
	parse_string(*str);
	fc_history_free(fc_history);
	vector_free(&fc_history);
	(void)flags;
	(void)av;
	return (SHERR_OK);
}
