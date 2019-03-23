#include "shell.h"
#include "lexer.h"
#include "parser.h"
#include "execute.h"

static void		config_create_confile(char *path)
{
	int		fd;

	fd = open(path, O_CREAT, S_IRUSR | S_IRGRP | S_IROTH | S_IWUSR);
	close(fd);
}

static char		*config_get_path(void)
{
	return  (ft_strjoin(sgetenv("HOME", ENV_ALL), SHELL_DEFAULT_RC, 0));
}

void	parse_config(void)
{
	char		*config;
	t_lexer		*lex;
	t_astree	*ast;
	size_t		len;
	char		*path;
	int			fd;

	path = config_get_path();
	config_create_confile(path);
	len = get_file_size(path);
	config = (char *)xmalloc((sizeof(char) * (len + 1)));
	fd = open(path, 'r');
	read(fd, config, len + 1);
	close(fd);
	ft_strdel(&path);
	lex = lexer(config, len);
	ft_strdel(&config);
	g_tokens = lex->lexems;
	ast = inputunit();
	execute(ast);
	freeastree(ast);
	lexer_free(lex);
}
