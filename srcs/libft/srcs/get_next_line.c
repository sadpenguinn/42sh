/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 20:15:14 by bwerewol          #+#    #+#             */
/*   Updated: 2018/12/09 18:44:24 by bwerewol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <unistd.h>

static t_line		*ft_linefd(t_line **begin, int fd, int rm)
{
	t_line *elem;
	t_line *del;

	if (!(elem = *begin))
		return ((t_line *)0);
	if (elem->fd == fd)
	{
		if (!rm)
			return (elem);
		*begin = elem->next;
		free(elem->data);
		free(elem);
		return ((t_line *)0);
	}
	while (elem->next && elem->next->fd != fd)
		elem = elem->next;
	if ((del = elem->next) && elem->next->fd == fd)
	{
		if (!rm)
			return (elem->next);
		elem->next = elem->next->next;
		free(del->data);
		free(del);
	}
	return ((t_line *)0);
}

static t_line		*ft_pushline(t_line **begin, int fd, long *res)
{
	t_line *new;

	if (!begin || !(new = malloc(sizeof(t_line))))
		return ((t_line *)0);
	if (!(new->data = ft_strnew(BUFF_SIZE)))
	{
		free(new);
		return ((t_line *)0);
	}
	*res = read(fd, new->data, BUFF_SIZE);
	new->end = *res;
	new->fd = fd;
	new->pos = 0;
	if (*res < 1)
		return (ft_linefd(&new, fd, 1));
	new->next = *begin;
	return (*begin = new);
}

static int			ft_summ(t_line *s, size_t len)
{
	char	*buff;
	long	count;

	if (!(buff = ft_strnew(s->end - s->pos + BUFF_SIZE)))
		return (-1);
	ft_memcpy(buff, s->data + s->pos, s->end - s->pos);
	free(s->data);
	s->data = buff;
	if ((count = read(s->fd, s->data + s->end - s->pos, BUFF_SIZE)) == -1)
		return (-1);
	s->end = s->end - s->pos + count;
	if (count < BUFF_SIZE && len)
	{
		s->data[s->end] = '\n';
		s->end += s->data[s->end - 1] == '\n' ? 0 : 1;
	}
	s->pos = 0;
	return (count + (len ? 1 : 0));
}

static int			ft_copy(char **line, t_line *s)
{
	size_t	len;
	long	count;

	while (1)
	{
		len = 0;
		while ((s->pos + len) < (size_t)s->end && s->data[s->pos + len] != '\n')
			len++;
		if (len + s->pos < (size_t)s->end)
			break ;
		if ((count = ft_summ(s, len)) < 1)
			return (count);
	}
	if (!(*line = ft_strnew(len)))
		return (-1);
	ft_memcpy(*line, s->data + s->pos, len);
	s->pos += len + 1;
	return (1);
}

int					get_next_line(const int fd, char **line)
{
	static t_line	*begin = 0;
	t_line			*curr;
	long			res;

	if (!line || BUFF_SIZE < 1)
		return (-1);
	res = 0;
	if (!(curr = ft_linefd(&begin, fd, 0)))
		if (!(curr = ft_pushline(&begin, fd, &res)))
			return (res);
	if ((res = ft_copy(line, curr)) == 1)
		return (1);
	ft_linefd(&begin, fd, 1);
	*line = (char *)0;
	return (res);
}
