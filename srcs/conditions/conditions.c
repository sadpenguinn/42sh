/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conditions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaelor- <bbaelor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 17:55:05 by bbaelor-          #+#    #+#             */
/*   Updated: 2019/03/26 02:20:58 by bbaelor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conditions.h"

void		conditions_processing(char **argv, int *res, int *i)
{
	int t_i;

	t_i = *i;
	if (argv[t_i][0] == '-')
	{
		*res = cond_switcher_for_one(argv[t_i], argv[t_i + 1]);
		*i += 2;
	}
	else
	{
		*res = cond_switcher_for_two(argv[t_i + 1], argv[t_i], argv[t_i + 2]);
		*i += 3;
	}
}

static int	destr(char **str, int to_return)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (to_return);
}

int			conditions(char **argv)
{
	int	i;
	int res;
	int n;

	if (!(n = ft_tab_len(argv)))
		return (destr(argv, 0));
	if (n == 1)
		return (destr(argv, 1));
	res = 0;
	i = 0;
	while (argv[i])
	{
		if (!(ft_strcmp(argv[i], "-a")))
			return (destr(argv, (res * (conditions(&argv[i + 1]))) ? 1 : 0));
		else if (!(ft_strcmp(argv[i], "-o")))
			return (destr(argv, (conditions(&argv[i + 1])) ? 1 : res));
		else if ((argv[i][0] == '-' && n - i < 2)
						|| (!(argv[i][0] == '-') && n - i < 3))
			return (destr(argv, conditions_print_error_syntax()));
		else
			conditions_processing(argv, &res, &i);
	}
	return (destr(argv, res));
}
