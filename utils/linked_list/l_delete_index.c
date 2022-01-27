/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_delete_index.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 23:31:10 by aben-ham          #+#    #+#             */
/*   Updated: 2022/01/28 00:30:37 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

void	l_delete_index(t_list *list, size_t index, void (*del)(t_node *node))
{
	t_node	*node;
	t_node	*before;
	t_node	*tmp;

	if (l_len(list) + index < 0 || !list)
		return ;
	if (index < 0)
		index = l_len(list) + index;
	node = l_get(list, index);
	if (!node)
		return ;
	if (index == 0)
	{
		tmp = node->next;
		l_del_node(node, del);
		list->head = tmp;
	}
	else
	{
		before = l_get(list, index - 1);
		before->next = node->next;
		l_del_node(node, del);
	}
	list->len--;
}
