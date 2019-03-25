/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_config.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 13:54:18 by nkertzma          #+#    #+#             */
/*   Updated: 2019/03/25 13:54:20 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	return (ft_strjoin(sgetenv("HOME", ENV_ALL), SHELL_DEFAULT_RC, 0));
}

static size_t	config_init(char **config)
{
	char		*path;
	size_t		len;
	int			fd;

	path = config_get_path();
	config_create_confile(path);
	len = get_file_size(path);
	*config = (char *)xmalloc((sizeof(char) * (len + 1)));
	fd = open(path, 'r');
	read(fd, *config, len + 1);
	close(fd);
	ft_strdel(&path);
	return (len);
}

void			parse_config(void)
{
	char		*config;
	t_lexer		*lex;
	t_astree	*ast;
	size_t		len;

	config = NULL;
	len = config_init(&config);
	lex = lexer(config, len);
	ft_strdel(&config);
	g_tokens = lex->lexems;
	ast = inputunit();
	execute(ast);
	freeastree(ast);
	lexer_free(lex);
}
