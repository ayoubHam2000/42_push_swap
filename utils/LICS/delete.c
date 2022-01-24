/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 23:33:23 by aben-ham          #+#    #+#             */
/*   Updated: 2022/01/24 23:33:23 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LICS.h"

static void	del_list_nbr(t_node *node)
{
	l_delete_all(_LIST(node), NULL);
	ft_free(node);
}

void	del_less_than_n(t_list *lists, int n)
{
	t_node	*node;
	t_node	*target;

	node = lists->head;
	while (node)
	{
		if (l_len(_LIST(node)) == n)
		{
			node = node->next;
			target = node;
			l_delete_node(lists, target, del_list_nbr);
		}
		else
			node = node->next;
	}
}
