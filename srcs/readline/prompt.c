#include "array.h"
#include "readline.h"
#include <limits.h>
#include <pwd.h>
#include <sys/types.h>
#include <unistd.h>

#ifndef PATH_MAX
# define PATH_MAX 4096
#endif

static int  get_pos(const char *s1, const char *s2)
{
	int     i;

	i = 0;
	while (s1[i] == s2[i] && s1[i])
		i++;
	if (s1[i] == '\0' && s2[i] != '\0')
		return (0);
	return (i);
}

static int  get_prompt(char *cwd)
{
	struct passwd   *pw;

	pw = getpwuid(getuid());
	if (getcwd(cwd, PATH_MAX) != NULL)
		return (get_pos(cwd, pw->pw_dir));
	return (-1);
}

void        print_prompt(void)
{
	char    cwd[PATH_MAX];
	int     pos;

	array_add(CURSOR_MOVE_LINE_START, 0);
	array_add(CURSOR_CLEAR_TO_END_SCREEN, 0);
	array_add("[42] ", 0);
	array_add(COLOR_PROMPT, 0);
	pos = get_prompt(cwd);
	if (pos >= 0)
	{
		if (pos != 0)
			array_add("~", 0);
		array_add(cwd + pos, 0);
		array_add("/", 0);
	}
	array_add(COLOR_DEFAULT, 0);
	array_add("$\n", 0);
//	array_add("> ", 0);
	array_flush();
}
