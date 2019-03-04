int	repeat_command(t_matrix *matrix, int *(command)(t_matrix *matrix))
{
	int	i;
	int	rez;

	i = SHORTCUT_ARRAY_SIZE - 1;
	while (!(g_shortcuts[i] >= '0' && g_shortcuts [i] <= '9') & i)
		i--;
	while (g_shortcuts[i] >= '0' && g_shortcuts [i] <= '9' & i)
		i--;
}