/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lics.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 20:29:57 by aben-ham          #+#    #+#             */
/*   Updated: 2022/02/13 16:33:33 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LICS.h"

t_list	*lics(int *arr, int size)
{
	t_list	*lists;
	int		*xx;
	int		i;
	int		j;

	xx = ft_malloc(sizeof(int) * (size * 2));
	i = -1;
	while (++i < size * 2)
		xx[i] = arr[i % size];
	lists = l_init();
	i = -1;
	j = size;
	while (++i < size)
	{
		l_append_front(lists, lis(xx + j, size));
		j--;
	}
	keep_longest(lists);
	free(xx);
	return (lists);
}
