/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_del_by_prev.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 23:45:42 by aben-ham          #+#    #+#             */
/*   Updated: 2022/01/28 03:17:50 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

void	l_del_by_prev(t_list *list, t_node *prev, void (*del_ptr)(void *p))
{
	t_node	*node;

	if (!list || !l_len(list))
		return ;
	if (!prev)
	{
		node = list->head;
		if (node == list->last)
			list->last = NULL;
		list->head = node->next;
		l_del_node(node, del_ptr);
	}
	else
	{
		node = prev->next;
		if (node == list->last)
			list->last = prev;
		prev->next = node->next;
		l_del_node(node, del_ptr);
	}
	list->len--;
}
