/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis_cases.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 15:42:07 by aben-ham          #+#    #+#             */
/*   Updated: 2022/01/25 15:42:07 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LICS.h"

void	lis_case1(t_list *lists, int n)
{
	t_list	*new_list;

	new_list = l_init();
	l_append_front(new_list, create_nbr(n));
	l_append_end(lists, new_list);
}

void	lis_case2(t_list *lists, int n)
{
	t_list	*largest;
	t_list	*new;
	t_node	*node;

	largest = _list(lists->head);
	node = lists->head;
	while (node)
	{
		if (l_len(largest) < l_len(_list(node)))
			largest = _list(node);
		node = node->next;
	}
	new = l_clone(largest, clone_nbr);
	l_append_front(new, create_nbr(n));
	l_append_end(lists, new);
}

void	lis_case3(t_list *lists, int n)
{
	t_list	*largest;
	t_node	*node;
	t_list	*new;
	int		end;

	largest = NULL;
	node = lists->head;
	while (node)
	{
		end = _int(_list(node)->head);
		if (!largest && end < n)
			largest = _list(node);
		else if (end < n && end > _int(largest->head))
			largest = _list(node);
		node = node->next;
	}
	new = l_clone(largest, clone_nbr);
	l_append_front(new, create_nbr(n));
	l_append_end(lists, new);
	del_same_len(lists, new);
}
