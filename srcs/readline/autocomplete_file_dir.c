#include "readline.h"
#include "array.h"
#include "libshell.h"

static char	*get_pattern(char *buf, int pos)
{
	char 	*pattern;
	int 	left_pos;

	left_pos = pos;
	while (left_pos && buf[left_pos - 1] != ' ' && buf[left_pos - 1] != '/')
		left_pos--;
	pattern = ft_strndup(buf + left_pos, pos - left_pos);
	pattern = ft_strjoin(pattern, "*", 1);
	return (pattern);
}

static char	*get_rel_dir(char *buf, int pos)
{
	int	left_pos;

	if (pos)
		pos--;
	while (pos && buf[pos] != '/' && buf[pos - 1] != ' ')
		pos--;
	left_pos = pos;
	while (left_pos && buf[left_pos - 1] != ' ')
		left_pos--;
	if (left_pos == pos)
		return (ft_strdup("."));
	return (ft_strndup(buf + left_pos, pos - left_pos + 1));
}

static void	print_possibilities(t_matrix *matrix, char **matches, size_t cnt)
{
	size_t	i;

	set_matrix_limits(matrix);
	add_cursor_offset(matrix->last_offset);
	add_lines_text(matrix);
	i = 0;
	array_add("\n", 1);
	while (i < cnt)
	{
		array_add(matches[i], strlen(matches[i]));
		free(matches[i]);
		array_add("\n", 1);
		i++;
	}
	print_prompt();
	matrix->last_offset = 0;
}

static void	add_completion(t_matrix *matrix, char *match, char *pattern)
{
	size_t	left_pos;
	size_t	right_pos;
	char	*tmp;
	DIR		*dir;

	left_pos = 0;
	while (pattern[left_pos] == match[left_pos] && match[left_pos])
		left_pos++;
	right_pos = left_pos;
	while (match[right_pos])
		right_pos++;
	if ((dir = opendir(match)))
		tmp = ft_strjoin(match + left_pos, "/", 0);
	else
		tmp = ft_strjoin(match + left_pos, " ", 0);
	closedir(dir);
	free(match);
	matrix_string_insert(matrix, matrix->cursor, tmp, strlen(tmp));
	free(tmp);
}

int			autocomplete_file_dir(t_matrix *matrix)
{
	char	**matches;
	size_t	cnt;
	char 	*pattern;
	char 	*dir;

	matches = NULL;
	dir = get_rel_dir(matrix->lines[matrix->cursor->row]->buf, matrix->cursor->col);
	pattern = get_pattern(matrix->lines[matrix->cursor->row]->buf, matrix->cursor->col);
	xglob(pattern, dir, &matches, &cnt);
	if (cnt > 1)
		print_possibilities(matrix, matches, cnt);
	if (cnt == 1)
		add_completion(matrix, matches[0], pattern);
	free(pattern);
	free(dir);
	free(matches);
	return (1);
}

