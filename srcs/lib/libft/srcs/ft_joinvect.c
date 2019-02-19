/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrayjoin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 13:08:32 by bwerewol          #+#    #+#             */
/*   Updated: 2019/02/19 14:24:25 by bwerewol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	**ft_joinvect(void **arr1, void **arr2)
{
	int		i;
	int		j;
	int		newlen;
	void	**newarr;

	newlen = 0;
	i = 0;
	while (arr1[i++])
		newlen++;
	i = 0;
	while (arr2[i++])
		newlen++;
	newlen++;
	newarr = xmalloc(sizeof(void *) * newlen);
	j = 0;
	i = 0;
	while (arr1[i])
		newarr[j++] = arr1[i++];
	i = 0;
	while (arr2[i])
		newarr[j++] = arr2[i++];
	free(arr1);
	free(arr2);
	newarr[newlen] = 0;
	return (newarr);
}
