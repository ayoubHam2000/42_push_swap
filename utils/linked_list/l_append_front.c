/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_append_front.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 19:08:58 by aben-ham          #+#    #+#             */
/*   Updated: 2022/01/28 00:30:14 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

void	l_append_front(t_list *list, void *p)
{
	t_node	*new;

	new = l_create_node(p);
	new->next = list->head;
	list->head = new;
	list->len++;
}
