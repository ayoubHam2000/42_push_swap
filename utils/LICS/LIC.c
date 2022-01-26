/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LICS.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 15:43:03 by aben-ham          #+#    #+#             */
/*   Updated: 2022/01/25 15:43:03 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LICS.h"

static int	is_the_smallest(t_list *lists, int n)
{
	t_node	*list;
	t_node	*end;

	list = lists->head;
	while (list)
	{
		end = l_get(_LIST(list), 0);
		if (n > _INT(end))
			return (0);
		list = list->next;
	}
	return (1);
}

static int	is_the_largest(t_list *lists, int n)
{
	t_node	*list;
	t_node	*end;

	list = lists->head;
	while (list)
	{
		end = l_get(_LIST(list), 0);
		if (n < _INT(end))
			return (0);
		list = list->next;
	}
	return (1);
}

static int	con_less_than(t_node *node, void *p)
{
	size_t	max_len;

	max_len = *(size_t *)p;
	if (l_len(_LIST(node)) < max_len)
		return (1);
	return (0);
}

void	keep_longest(t_list *lists)
{
	size_t	max_len;
	t_node	*node;

	node = lists->head;
	if (!node)
		return ;
	max_len = l_len(_LIST(node));
	node = node->next;
	while (node)
	{
		if (max_len < l_len(_LIST(node)))
			max_len = l_len(_LIST(node));
		node = node->next;
	}
	l_del_cond(lists, &max_len, con_less_than, del_list_nbr);
}

//backward (--i >= 0)
t_list	*LIS(int *arr, int size)
{
	t_list	*lists;
	int		i;

	i = size;
	lists = l_init();
	while (--i >= 0)
	{
		if (is_the_smallest(lists, arr[i]))
			lis_case1(lists, arr[i]);
		else if (is_the_largest(lists, arr[i]))
			lis_case2(lists, arr[i]);
		else
			lis_case3(lists, arr[i]);
	}
	keep_longest(lists);
	return (lists);
}
