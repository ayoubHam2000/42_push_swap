/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 17:55:49 by aben-ham          #+#    #+#             */
/*   Updated: 2022/01/24 17:55:49 by aben-ham         ###   ########.fr       */
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

	largest = _LIST(lists->head);
	node = lists->head;
	while (node)
	{
		if (l_len(largest) < l_len(_LIST(node)))
			largest = _LIST(node);
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
		end = _INT(_LIST(node)->head);
		if (!largest && end < n)
			largest = _LIST(node);
		else if (end < n && end > _INT(largest->head))
			largest = _LIST(node);
		node = node->next;
	}
	new = l_clone(largest, clone_nbr);
	l_append_front(new , create_nbr(n));
	l_append_end(lists, new);
	del_same_len(lists, new);
}

int	is_the_smallest(t_list *lists, int n)
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

int	is_the_largest(t_list *lists, int n)
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

t_list	*LIS(int arr[], int size)
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
		print_lists(lists);
		printf("++++++++++++++++++\n");
	}
	return (lists);
}

int	main(int ac, char **av)
{
	t_list	*lists;
	int		*arr;
	int		i;

	arr = ft_malloc((ac - 1) * sizeof(int));
	i = 0;
	while (++i < ac)
		arr[i - 1] = atoi(av[i]);
	lists = LIS(arr, ac - 1);
	print_lists(lists);
	mem_clean();
	return (0);
}
