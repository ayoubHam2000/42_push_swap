/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 20:38:37 by aben-ham          #+#    #+#             */
/*   Updated: 2022/01/28 20:53:54 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LICS.h"

static void	smallest(t_list *lists, int n)
{
	t_list	*new_list;

	new_list = l_init();
	l_append_front(new_list, p_int(n));
	l_append_front(lists, new_list);
}

static void	largest(t_list *lists, int n)
{
	t_list	*largest;
	t_list	*new_list;
	t_node	*node;

	largest = _list(lists->head);
	node = lists->head;
	while (node)
	{
		if (l_len(largest) < l_len(_list(node)))
			largest = _list(node);
		node = node->next;
	}
	new_list = l_clone(largest, clone_int);
	l_append_front(new_list, p_int(n));
	l_append_end(lists, new_list);
}

static void	between(t_list *lists, int n)
{
	t_node	*node;
	t_node	*largest;
	t_node	*new_node;
	int		end;

	largest = NULL;
	node = lists->head;
	while (node)
	{
		end = _int(_list(node)->head);
		if (!largest && end < n)
			largest = node;
		else if (end < n && end > _int(_list(largest)->head))
			largest = node;
		node = node->next;
	}
	new_node = l_create_node(l_clone(_list(largest), clone_int));
	new_node->next = largest->next;
	largest->next = new_node;
	l_del_cond(lists, &(_list(new_node)->len), con_del_same_len, del_list_int);
	l_append_front(_list(new_node), p_int(n));
}

void	keep_longest(t_list *lists)
{
	t_node	*node;
	t_node	*largest;

	largest = lists->head;
	node = lists->head->next;
	while (node)
	{
		if (l_len(_list(largest)) < l_len(_list(node)))
			largest = node;
		node = node->next;
	}
	l_del_cond(lists, largest, con_del_less_than_len, del_list_int);
}

t_list	*lis(int *arr, int size)
{
	t_list	*lists;
	t_list	*res;
	int		i;

	lists = l_init();
	i = size;
	while (--i >= 0)
	{
		if (!lists->head || arr[i] < _int(_list(lists->head)->head))
			smallest(lists, arr[i]);
		else if (arr[i] > _int(_list(lists->last)->head))
			largest(lists, arr[i]);
		else
			between(lists, arr[i]);
	}
	keep_longest(lists);
	res = _list(lists->head);
	free(lists->head);
	free(lists);
	return (res);
}
