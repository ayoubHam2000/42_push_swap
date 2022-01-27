/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LICS.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 11:36:03 by aben-ham          #+#    #+#             */
/*   Updated: 2022/01/26 11:36:03 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LICS.h"

static void	append_lists(t_list *lists, t_list *src)
{
	t_node	*node;

	node = src->head;
	while (node)
	{
		l_append_end(lists, node->p);
		node = node->next;
	}
}

static void	del_lic_nodes(t_node *node)
{
	free(node);
}

//they have already the same length
static int	con_dup(t_node *node, void *p)
{
	t_list	*list1;
	t_list	*list2;
	t_node	*n1;
	t_node	*n2;

	list1 = _list(node);
	list2 = _list((t_node *)p);
	if (list1 == list2)
		return (0);
	n1 = list1->head;
	n2 = list2->head;
	while (n1)
	{
		if (_int(n1) != _int(n2))
			return (0);
		n1 = n1->next;
		n2 = n2->next;
	}
	return (1);
}

static void	del_dup(t_list *lists)
{
	t_node	*node;

	node = lists->head;
	while (node)
	{
		l_del_cond(lists, node, con_dup, del_list_nbr);
		node = node->next;
	}
}

t_list	*lics(int *arr, int size)
{
	t_list	*lists;
	t_list	*lic_lists;
	int		*xx;
	int		i;

	xx = ft_malloc(sizeof(int) * (size * 2));
	i = -1;
	while (++i < size * 2)
		xx[i] = arr[i % size];
	lists = l_init();
	i = -1;
	xx += size;
	while (++i < size)
	{
		lic_lists = lis(xx, size);
		append_lists(lists, lic_lists);
		l_delete_all(lic_lists, del_lic_nodes);
		free(lic_lists);
		xx--;
	}
	keep_longest(lists);
	del_dup(lists);
	return (lists);
}
