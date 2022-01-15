/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   done.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayoub <ayoub@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 23:02:03 by aben-ham          #+#    #+#             */
/*   Updated: 2022/01/14 23:16:22 by ayoub            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*transform(t_stack *sa)
{
	int	i;
	int	j;
	int	*tmp;

	tmp = ft_malloc(sizeof(int) * sa->size);
	i = 0;
	while (i < sa->size)
	{
		j = 0;
		tmp[i] = 0;
		while (j < sa->size)
		{
			if (j != i && sa->s[j] < sa->s[i])
				tmp[i]++;
			j++;
		}
		i++;
	}
	ft_free(sa->s);
	sa->s = tmp;
	return (sa);
}
