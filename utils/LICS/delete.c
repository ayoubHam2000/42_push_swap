/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 23:33:23 by aben-ham          #+#    #+#             */
/*   Updated: 2022/01/24 23:33:23 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LICS.h"

static void	del_list_nbr(t_node *node)
{
	l_delete_all(_LIST(node), NULL);
	ft_free(node->p);
	ft_free(node);
}

void	del_same_len(t_list *lists, t_list *new)
{
	t_node	*node;
	t_node	*target;

	node = lists->head;
	while (node)
	{
		if (_LIST(node) != new && l_len(_LIST(node)) == l_len(new))
		{
			target = node;
			node = node->next;
			l_delete_node(lists, target, del_list_nbr);
		}
		else
			node = node->next;
	}
}
