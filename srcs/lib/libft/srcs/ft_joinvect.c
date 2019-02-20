/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_joinvect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 13:08:32 by bwerewol          #+#    #+#             */
/*   Updated: 2019/02/20 18:19:22 by bwerewol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	**ft_joinvect(void **arr1, void **arr2, int free2)
{
	int		i;
	int		j;
	int		len;

	len = 0;
	i = 0;
	while (arr1[i])
		i++;
	j = 0;
	while (arr2[j])
		j++;
	len = i + j + 1;
	arr1 = xrealloc((void *)arr1, sizeof(void *) * len, sizeof(void *) * len);
	j = 0;
	while (arr2[j])
		arr1[i++] = arr2[j++];
	if (free2)
		free(arr2);
	arr1[len - 1] = 0;
	return (arr1);
}
