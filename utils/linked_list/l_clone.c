/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_clone.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 21:24:02 by aben-ham          #+#    #+#             */
/*   Updated: 2022/01/24 21:24:02 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

t_list	*l_clone(t_list *list)
{
	t_list	*new_list;
	t_node	*node;
	void	*p;

	new_list = l_init(list->data_size);
	node = list->head;
	while (node)
	{
		p = ft_malloc(list->data_size);
		ft_memcpy(p, node->p, list->data_size);
		l_append_end(new_list, p);
		node = node->next;
	}
	return (new_list);
}
