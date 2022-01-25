/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_delete_node.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 23:45:42 by aben-ham          #+#    #+#             */
/*   Updated: 2022/01/24 23:45:42 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

void	l_delete_node(t_list *list, t_node *node, void (*del)(t_node *node))
{
	t_node	*before;
	t_node	*tmp;

	if (!node || !list)
		return ;
	if (list->head == node)
	{
		tmp = node->next;
		l_del_node(node, del);
		list->head = tmp;
	}
	else
	{
		before = list->head;
		while (before->next != node)
			before = before->next;
		before->next = node->next;
		l_del_node(node, del);
	}
	list->len--;
}
