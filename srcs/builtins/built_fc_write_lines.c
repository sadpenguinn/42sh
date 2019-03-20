/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_fc_write_lines.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 15:29:48 by narchiba          #+#    #+#             */
/*   Updated: 2019/03/20 15:31:29 by narchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "readline.h"
#include "vector.h"
#include "libft.h"

static int	built_fc_set_limit_word_case(size_t *limit,
		const char *str, void *fc_history)
{
	size_t	i;
	size_t	len;
	int		flag;

	len = ft_strlen(str);
	i = vector_get_len(fc_history);
	flag = 0;
	while (i--)
	{
		if (ft_strncmp(str, *((char **)vector_get_elem(fc_history, i)),
					len) == 0)
		{
			flag = 1;
			break ;
		}
	}
	if (flag)
	{
		*limit = i;
		return (1);
	}
	return (built_fc_usage(FC_ERROR_EVENT));
}

static int	built_fc_set_limit_nbr_case(size_t *limit,
		const char *str, void *fc_history)
{
	*limit = (size_t)ft_atoi(str);
	if (*limit)
		(*limit)--;
	if (*limit >= vector_get_len(fc_history))
		*limit = vector_get_len(fc_history) - 1;
	return (1);
}

static int	built_fc_set_limit(size_t *limit,
		const char *str, void *fc_history)
{
	if (str == NULL || str[0] == '\0')
		return (1);
	if (str[0] >= '0' && str[0] <= '9')
		return (built_fc_set_limit_nbr_case(limit, str, fc_history));
	if (str[1] && str[0] == '+' && str[1] >= '0' && str[1] <= '9')
		return (built_fc_set_limit_nbr_case(limit, str, fc_history));
	if (str[1] && str[0] == '-' && str[1] >= '0' && str[1] <= '9')
	{
		built_fc_set_limit_nbr_case(limit, str + 1, fc_history);
		*limit = vector_get_len(fc_history) - *limit - 1;
		return (1);
	}
	return (built_fc_set_limit_word_case(limit, str, fc_history));
}

static void	built_fc_add_string(void *fc_history,
		const int *flags, size_t pos)
{
	char	*str;

	if (flags[2] == 0 && flags[3])
	{
		array_add("  ", 2);
		str = ft_itoa((int)(pos + 1));
		array_add(str, ft_strlen(str));
		free(str);
		array_add("  ", 2);
	}
	str = *((char **)vector_get_elem(fc_history, pos));
	array_add(str, ft_strlen(str));
	array_add("\n", 1);
}

int			built_fc_write_lines(void *fc_history,
		int fd, int *flags, char **av)
{
	size_t	left_limit;
	size_t	right_limit;

	built_fc_set_limits_default(&left_limit, &right_limit, fc_history, flags);
	if (av[0])
		if (!built_fc_set_limit(&left_limit, av[0], fc_history))
			return (1);
	if (av[0] && av[1])
		if (!built_fc_set_limit(&right_limit, av[1], fc_history))
			return (1);
	if (flags[1])
		built_fc_swap_limits(&left_limit, &right_limit);
	if (flags[4] == 0)
		while (left_limit != right_limit)
		{
			built_fc_add_string(fc_history, flags, left_limit);
			if (left_limit < right_limit)
				left_limit++;
			else
				left_limit--;
		}
	built_fc_add_string(fc_history, flags, left_limit);
	array_flush_fd(fd);
	return (1);
}
