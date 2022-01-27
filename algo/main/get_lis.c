/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_lis.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 21:03:48 by aben-ham          #+#    #+#             */
/*   Updated: 2022/01/25 21:04:03 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algo.h"

static	int	con_not_best(t_node *node, void *p)
{
	if (node == p)
		return (0);
	return (1);
}

static int	have_the_begenning_item(t_list *lis, int b)
{
	t_node	*node;

	node = lis->head;
	while (node)
	{
		if (b == _int(node))
			return (1);
		node = node->next;
	}
	return (0);
}

t_list	*get_lis(t_list *lics, int b)
{
	t_node	*node;
	t_node	*best;
	t_list	*res;

	node = lics->head;
	best = node;
	while (node)
	{
		if (have_the_begenning_item(_list(node), b))
		{
			best = node;
			break ;
		}
		node = node->next;
	}
	l_del_cond(lics, best, con_not_best, del_list_nbr);
	free(lics);
	res = _list(best);
	free(best);
	return (res);
}
