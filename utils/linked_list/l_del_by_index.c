/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_del_by_index.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 23:31:10 by aben-ham          #+#    #+#             */
/*   Updated: 2022/01/28 21:26:24 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

static int	l_check(t_list *list, long *index)
{
	if (!list || !l_len(list))
		return (0);
	if (*index < 0)
		*index = l_len(list) + *index;
	if (*index < 0 || *index > l_len(list))
		return (0);
	return (1);
}

void	l_del_by_index(t_list *list, long index, void (*del_ptr)(void *p))
{
	t_node	*node;
	t_node	*previous;

	if (!l_check(list, &index))
		return ;
	if (index == 0)
	{
		node = list->head;
		if (node == list->last)
			list->last = NULL;
		list->head = node->next;
		l_del_node(node, del_ptr);
	}
	else
	{
		previous = l_get(list, index - 1);
		node = previous->next;
		if (node == list->last)
			list->last = previous;
		previous->next = node->next;
		l_del_node(node, del_ptr);
	}
	list->len--;
}
