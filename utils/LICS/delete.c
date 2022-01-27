/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 23:33:23 by aben-ham          #+#    #+#             */
/*   Updated: 2022/01/28 00:29:55 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LICS.h"

void	del_list_nbr(t_node *node)
{
	l_delete_all(_list(node), NULL);
	free(node->p);
	free(node);
}

void	del_same_len(t_list *lists, t_list *new)
{
	t_node	*node;
	t_node	*target;

	node = lists->head;
	while (node)
	{
		if (_list(node) != new && l_len(_list(node)) == l_len(new))
		{
			target = node;
			node = node->next;
			l_delete_node(lists, target, del_list_nbr);
		}
		else
			node = node->next;
	}
}
