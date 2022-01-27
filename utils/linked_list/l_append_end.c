/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_append_end.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 21:27:26 by aben-ham          #+#    #+#             */
/*   Updated: 2022/01/28 00:30:12 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

void	l_append_end(t_list *list, void *p)
{
	t_node	*new;
	t_node	*last;

	new = l_create_node(p);
	if (list->head)
	{
		last = l_get(list, -1);
		last->next = new;
	}
	else
		list->head = new;
	list->len++;
}
