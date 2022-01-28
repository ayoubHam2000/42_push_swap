/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_del_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 23:30:23 by aben-ham          #+#    #+#             */
/*   Updated: 2022/01/28 19:06:27 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

//delete all nodes = result is an empty list
void	l_del_all(t_list *list, void (*del_ptr)(void *p))
{
	t_node	*node;
	t_node	*target;

	if (!list)
		return ;
	node = list->head;
	while (node)
	{
		target = node;
		node = node->next;
		l_del_node(target, del_ptr);
	}
	list->head = NULL;
	list->len = 0;
}
