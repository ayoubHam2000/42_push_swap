/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_stack_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 21:02:24 by aben-ham          #+#    #+#             */
/*   Updated: 2022/01/25 21:03:14 by aben-ham         ###   ########.fr       */
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
	if (sa->s[0] < sa->s[sa->size - 2] && _INT(node2) < _INT(node1))
	{
		if (sa->s[0] == _INT(node2))
			return (NL_LIS);
		if (sa->s[sa->size - 2] == _INT(node1))
			return (NR_LIS);
	}
	else if (_INT(node2) > _INT(node1))
	{
		if (sa->s[0] == _INT(node2) && sa->s[1] == _INT(node1))
			return (NL_LIS);
		if (sa->s[sa->size - 3] == _INT(node2)
			&& sa->s[sa->size - 2] == _INT(node1))
			return (NR_LIS);
	}
	return (NIN_LIS);
}

//lis will always have len >= 2
static int	state_n_in_lis(t_stack *sa, t_list *lis, int n)
{
	t_node	*node1;
	t_node	*node2;
	int		i;
	
	node1 = lis->head;
	node2 = l_get(lis, -1);
	while (node1)
	{
		i = _INT(node1);
		i = _INT(node2);
		if (n == _INT(node1) || n == _INT(node2))
			return (IN_LIS);
		else if ((node1 == lis->head && _INT(node1) < n && n > _INT(node2))
				|| (node1 == lis->head && _INT(node1) > n && n < _INT(node2))
				|| (node1 != lis->head && _INT(node1) < n && n < _INT(node2))
				)
			break ;
		node2 = node1;
		node1 = node1->next;
	}
	if (node1 && node2)
		return (state_n_nr_nl(node1, node2, sa));
	return (NIN_LIS);
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
			ft_exec(sa, sb, 2, RA);
		}
	}
}
