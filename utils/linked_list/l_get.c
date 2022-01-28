/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_get.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 20:46:00 by aben-ham          #+#    #+#             */
/*   Updated: 2022/01/28 21:22:45 by aben-ham         ###   ########.fr       */
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

t_node	*l_get(t_list *list, long pos)
{
	t_node	*node;

	if (!l_check(list, &pos))
		return (NULL);
	if (pos == l_len(list) - 1)
		return (list->last);
	node = list->head;
	while (node && pos > 0)
	{
		node = node->next;
		pos--;
	}
	return (node);
}
