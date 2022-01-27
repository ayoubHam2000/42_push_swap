/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_delete_all.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 23:30:23 by aben-ham          #+#    #+#             */
/*   Updated: 2022/01/28 00:30:32 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

void	l_delete_all(t_list *list, void (*del)(t_node *node))
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
		l_del_node(target, del);
	}
	list->head = NULL;
}
