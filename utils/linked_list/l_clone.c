/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_clone.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 11:40:27 by aben-ham          #+#    #+#             */
/*   Updated: 2022/01/25 12:40:27 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

static t_node	*l_clone_node(t_node *node, t_node *(*clone)(t_node *node))
{
	t_node	*new_node;

	if (clone)
		return (clone(node));
	new_node = l_create_node(node->p);
	return (new_node);
}

t_list	*l_clone(t_list *list, t_node *(*clone)(t_node *node))
{
	t_list	*new_list;
	t_node	*tmp;
	t_node	*node;

	new_list = l_init();
	node = list->head;
	while (node)
	{
		if (!new_list->head)
		{
			new_list->head = l_clone_node(node, clone);
			tmp = new_list->head;
		}
		else
		{
			tmp->next = l_clone_node(node, clone);
			tmp = tmp->next;
		}
		node = node->next;
	}
	new_list->len = list->len;
	return (new_list);
}
