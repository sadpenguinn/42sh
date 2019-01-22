/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_cursor_functions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sitlcead <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 09:01:39 by sitlcead          #+#    #+#             */
/*   Updated: 2019/01/14 19:33:21 by narchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_editing.h"

static int	move_cursor_right_case(char *buf, int dest, int src)
{
	int		*arr;
	char	*tmp;
	int		cnt;
	int		offset;
	int		i;

	offset = dest - src + 1;
	tmp = malloc(sizeof(int) * offset);
	memset(tmp, 0, sizeof(int) * offset);
	cnt = 0;
	i = src;
	while (i < dest)
	{
		if ((buf[i++] >> 7) & 1)
			while (i < dest && ((buf[i] >> 7) & 1) && (((buf[i] >> 6) & 1) == 0))
				i++;
		arr = (int *)(tmp + cnt * 3);
		*arr = RIGHT;
		cnt++;
	}
	write(1, tmp, 3 * cnt);
	free(tmp);
	return (1);
}

static int	move_cursor_left_case(char *buf, int dest, int src)
{
	int		*arr;
	char	*tmp;
	int		cnt;
	int		offset;
	int		i;

	offset = src - dest + 1;
	tmp = malloc(sizeof(int) * offset);
	memset(tmp, 0, sizeof(int) * offset);
	cnt = 0;
	i = src;
	while (i > dest)
	{
		if ((buf[i - 1] >> 7) & 1)
			while (i > dest - 1 && ((buf[i - 1] >> 6) & 1) == 0)
				i--;
		i--;
		arr = (int *)(tmp + cnt * 3);
		*arr = LEFT;
		cnt++;
	}
	write(1, tmp, 3 * cnt);
	free(tmp);
	return (1);
}

int		move_cursor_to_pos(char *buf, int dest, int src)
{
	if (src > dest)
		return (move_cursor_left_case(buf, dest, src));
	return (move_cursor_right_case(buf, dest, src));
}

static int	ft_strnum_base(char *str, long int num, int base)
{
	long long	ln;
	int			len;
	int			ret;
	int			sign;
	char		*barr;

	if (base < 2 || base > 16)
		return (0);
	barr = "0123456789ABCDEF";
	sign = (num < 0) ? 1 : 0;
	ln = sign ? -num : num;
	len = (sign && base == 10) ? 1 : 0;
	while (num /= base)
		len++;
	ret = len;
	while (len >= 0)
	{
		str[len--] = barr[ln % base];
		ln /= base;
	}
	if (sign && base == 10)
		*str = '-';
	return (++ret);
}

static int	ft_strnum(char *str, long int num)
{
	return (ft_strnum_base(str, num, 10));
}

static int	move_cursor(int n, char c)
{
	char	tmp[24];
	int		len;

	if (n == 0)
		return (1);
	memset(tmp, 0, 24);
	memcpy(tmp, "\033[", 2);
	len = ft_strnum(tmp + 2, n);
	tmp[len + 2] = c;
	write(1, tmp, len + 3);
	return (1);
}

int		move_cursor_right(int n)
{
	return (move_cursor(n, 'C'));
}

int		move_cursor_left(int n)
{
	return (move_cursor(n, 'D'));
}
