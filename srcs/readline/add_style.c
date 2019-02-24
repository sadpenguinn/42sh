#include "array.h"
#include "readline.h"

void	add_lines_prompt_style(void)
{
	array_add(TEXT_BOLD, strlen(TEXT_BOLD));
}

void	add_cur_line_prompt_style(void)
{
	array_add(TEXT_BOLD TEXT_COLOR_RED, strlen(TEXT_BOLD) + strlen(TEXT_COLOR_RED));
}

void	add_prompt_style(void)
{
	array_add(TEXT_BOLD, strlen(TEXT_BOLD));
	array_add(TEXT_COLOR_BLUE, strlen(TEXT_COLOR_BLUE));
}
