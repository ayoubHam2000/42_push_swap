/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_del_cond.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 16:58:16 by aben-ham          #+#    #+#             */
/*   Updated: 2022/01/28 19:23:38 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

static void	del_head(t_list *list, void (*del_ptr)(void *p))
{
	t_node	*tmp;

	if (list->head == list->last)
		list->last = NULL;
	tmp = list->head->next;
	l_del_node(list->head, del_ptr);
	list->head = tmp;
}

static void	del_target(
				t_list *list, t_node *target,
				t_node *prev, void (*del_ptr)(void *p)
				)
{
	if (target == list->head)
		del_head(list, del_ptr);
	else
	{
		if (target == list->last)
			list->last = prev;
		l_del_node(target, del_ptr);
	}
	list->len--;
}

void	l_del_cond(
		t_list *list,
		void *p,
		int (*condition)(t_node *node, void *p),
		void (*del_ptr)(void *p))
{
	t_node	*prev;
	t_node	*node;
	t_node	*target;

	if (!list || !condition)
		return ;
	node = list->head;
	prev = NULL;
	while (node)
	{
		if (condition(node, p))
		{
			target = node;
			node = target->next;
			del_target(list, target, prev, del_ptr);
			if (prev)
				prev->next = node;
		}
		else
		{
			prev = node;
			node = node->next;
		}
	}
}
