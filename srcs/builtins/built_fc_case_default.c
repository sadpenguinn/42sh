/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_fc_case_default.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 15:29:22 by narchiba          #+#    #+#             */
/*   Updated: 2019/03/20 15:29:23 by narchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "readline.h"
#include "libft.h"
#include <pwd.h>
#include "get_next_line.h"

static void	built_fc_write_history_on_disk(int fd_r)
{
	int				fd_w;
	char			*file_name;
	struct passwd	*pw;
	char			*str;

	pw = getpwuid(getuid());
	file_name = ft_strjoin(pw->pw_dir, "/", 0);
	file_name = ft_strjoin(file_name, HISTORY_FILE, 1);
	fd_w = open(file_name, O_CREAT | O_WRONLY | O_APPEND, 0777);
	while ((get_next_line(fd_r, &str)))
	{
		ft_putendl_fd(str, fd_w);
		free(str);
	}
	close(fd_w);
	free(file_name);
}

void		built_fc_write_history_changes(void)
{
	int				fd;
	char			*file_name;
	struct passwd	*pw;

	pw = getpwuid(getuid());
	file_name = ft_strjoin(pw->pw_dir, "/", 0);
	file_name = ft_strjoin(file_name, BUILTT_FC_TMP_FILE, 1);
	fd = open(file_name, O_CREAT | O_RDONLY, 0777);
	built_fc_write_history_on_disk(fd);
	close(fd);
	free(file_name);
}

int			built_fc_case_default(char **av, int i, int *flags,
		void *fc_history)
{
	int		fd;
	char	*file_name;
	size_t	len;
	char	*script;

	fd = built_fc_open_tmp_file(&file_name);
	built_fc_write_lines(fc_history, fd, flags, av + i);
	close(fd);
	array_add("nano", ft_strlen("nano"));
	array_add(" ", 1);
	array_add(file_name, ft_strlen(file_name));
	script = array_to_string();
	if ((built_fc_parse_string(script, 0)) == 0)
	{
		len = get_file_size(file_name);
		script = (char *)xmalloc((sizeof(char) * (len + 1)));
		fd = open(file_name, O_CREAT | O_RDONLY, 0777);
		read(fd, script, len + 1);
		close(fd);
		built_fc_parse_string(script, 1);
		built_fc_write_history_changes();
	}
	free(file_name);
	return (1);
}
