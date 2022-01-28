/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_stack_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 21:02:24 by aben-ham          #+#    #+#             */
/*   Updated: 2022/01/28 21:27:39 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algo.h"
#define IN_LIS 1
#define NIN_LIS 2
#define NR_LIS 3
#define NL_LIS 4
#define TO_LEFT 1
#define TO_RIGHT 2

static int	state_n_nr_nl(t_node *node1, t_node *node2, t_stack *sa)
{
	if (sa->s[0] < sa->s[sa->size - 2] && _int(node2) < _int(node1))
	{
		if (sa->s[sa->size - 2] == _int(node1))
			return (NR_LIS);
		if (sa->s[0] == _int(node2))
			return (NL_LIS);
	}
	else if (_int(node2) > _int(node1))
	{
		if (sa->s[sa->size - 3] == _int(node2)
			&& sa->s[sa->size - 2] == _int(node1))
			return (NR_LIS);
		if (sa->s[0] == _int(node2) && sa->s[1] == _int(node1))
			return (NL_LIS);
	}
	return (NIN_LIS);
}

//lis will always have len >= 2
static int	state_n_in_lis(t_stack *sa, t_list *lis, int n)
{
	t_node	*node1;
	t_node	*node2;

	node1 = lis->head;
	node2 = lis->last;
	while (node1)
	{
		if (n == _int(node1) || n == _int(node2))
			return (IN_LIS);
		else if ((node1 == lis->head && _int(node1) < n && n > _int(node2))
			|| (node1 == lis->head && _int(node1) > n && n < _int(node2))
			|| (node1 != lis->head && _int(node1) < n && n < _int(node2)))
			break ;
		node2 = node1;
		node1 = node1->next;
	}
	if (node1 && node2)
		return (state_n_nr_nl(node1, node2, sa));
	return (NIN_LIS);
}

void	add_it_to_list(t_list *list, int n)
{
	t_node	*node1;
	t_node	*node2;
	t_node	*new;

	node1 = list->head;
	while (node1)
	{
		node2 = node1->next;
		if (node2 && _int(node1) > n && n > _int(node2))
		{
			new = l_create_node(p_int(n));
			node1->next = new;
			new->next = node2;
			list->len++;
			return ;
		}
		node1 = node1->next;
	}
	if (n > _int(list->head))
		l_append_front(list, p_int(n));
	else
		l_append_end(list, p_int(n));
}

void	to_stack_b(t_stack *sa, t_stack *sb, t_list *lis)
{
	int	n;
	int	n_state;

	while (sa->size != sa->util->sm_size)
	{
		n = sa->s[sa->size - 1];
		n_state = state_n_in_lis(sa, lis, n);
		if (n_state == IN_LIS)
			ft_exec(sa, sb, 1, RA);
		else if (n_state == NIN_LIS)
			ft_exec(sa, sb, 1, PB);
		else if (n_state == NR_LIS)
			ft_exec(sa, sb, 1, SA);
		else if (n_state == NL_LIS)
			ft_exec(sa, sb, 1, RRA | SA << 4);
		if (n_state == NL_LIS || n_state == NR_LIS)
		{
			sa->util->sm_size++;
			if (sa->size == sa->util->sm_size)
				break ;
			add_it_to_list(lis, n);
			ft_exec(sa, sb, 2, RA);
		}
	}
}
