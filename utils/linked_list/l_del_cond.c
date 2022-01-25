/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_del_cond.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 16:58:16 by aben-ham          #+#    #+#             */
/*   Updated: 2022/01/25 16:58:16 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

void	l_del_cond(
		t_list *lists,
		void *p,
		int (*condition)(t_node *node, void *p),
		void (*del)(t_node *node))
{
	t_node	*node;
	t_node	*target;

	if (!lists || !condition)
		return ;
	node = lists->head;
	while (node)
	{
		if (condition(node, p))
		{
			target = node;
			node = node->next;
			l_delete_node(lists, target, del);
		}
		else
			node = node->next;
	}
}
