/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_get.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 20:46:00 by aben-ham          #+#    #+#             */
/*   Updated: 2022/01/24 20:46:00 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

t_node	*l_get(t_list *list, int pos)
{
	t_node	*node;

	if (pos < 0)
		pos = l_len(list) + pos;
	if (pos < 0)
		return (NULL);
	node = list->head;
	while (node && pos > 0)
	{
		node = node->next;
		pos--;
	}
	return (node);
}
