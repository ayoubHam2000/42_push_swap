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

static int	gaps_size(t_list *list)
{
	t_node	*node;
	int		res;

	node = list->head;
	if (!node)
		return (0);
	res = 0;
	while (node->next)
	{
		res += _INT(node) - _INT(node->next);
		node = node->next;
	}
	return (res);
}

static int	have_the_begenning_item(t_list *lis, int b)
{
	t_node	*node;

	node = lis->head;
	while (node)
	{
		if (b == _INT(node))
			return (1);
		node = node->next;
	}
	return (0);
}

t_list	*get_lis(t_list *lics, int b)
{
	t_node	*node;
	t_list	*best;
	int		old;
	int		gap_size;

	old = 0;
	node = lics->head;
	best = _LIST(node);
	while (node)
	{
		if (have_the_begenning_item(_LIST(node), b))
		{
			best = _LIST(node);
			break;
		}
		/*gap_size = gaps_size(_LIST(node));
		if (!old || old > gap_size)
		{
			best = _LIST(node);
			old = gap_size;
		}*/
		node = node->next;
	}
	return (best);
}
