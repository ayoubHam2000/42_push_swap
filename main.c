/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 23:35:53 by aben-ham          #+#    #+#             */
/*   Updated: 2022/01/23 11:33:15 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algo.h"

#define IN_LIS 1
#define NIN_LIS 2
#define NR_LIS 3
#define NL_LIS 4
#define TO_LEFT 1
#define TO_RIGHT 2

//lis will always have len >= 2
int		state_n_in_lis(t_stack *sa, t_list *lis, int n)
{
	t_node	*node1;
	t_node	*node2;

	node1 = lis->head;
	node2 = l_get(lis, -1);
	while (node1)
	{
		if (n == _INT(node1))
			return (IN_LIS);
		else if ((node1 == lis->head && _INT(node1) < n && _INT(node2) < n)
				|| (node1 != lis->head && _INT(node1) > n && _INT(node2) < n))
			break ;
		node1 = node1->next;
		node2 = node1;
	}
	if (sa->s[sa->size - 2] == _INT(node2))
		return (NR_LIS);
	else if (sa->s[0] == _INT(node1))
		return (NL_LIS);
	return (NIN_LIS);
}

void	to_stack_b(t_stack *sa, t_stack *sb, t_list *lis)
{
	int	n;
	int	n_state;

	n = sa->s[sa->size - 1];
	n_state = state_n_in_lis(sa, lis, n);
	if (n_state == IN_LIS)
		ft_exec(sa, sb, 1, RA);
	else if (n_state == NIN_LIS)
		ft_exec(sa, sb, 1, PB);
	else if (n_state == NR_LIS)
	{
		ft_exec(sa, sb, 1, SA);
		ft_exec(sa, sb, 2, RA);
	}
	else if (n_state == NL_LIS)
	{
		ft_exec(sa, sb, 1, RRA);
		ft_exec(sa, sb, 1, SA);
		ft_exec(sa, sb, 2, RA);
	}
}

t_list	*get_lis(t_list *lics)
{
	return (_LIST(lics->head));
}

void	push_swap(t_stack *sa, t_stack *sb)
{
	t_list	*lic;

	transform(sa);
	print_stack(*sa);
	lic = get_lis(LICS(sa->s, sa->size));
	print_list_nbr(lic);
	sa->util->affect = 1;
	to_stack_b(sa, sb, lic);
}	

void	push(int ac, char **av)
{
	t_stack	sa;
	t_stack	sb;

	init_push(&sa, &sb, ac, av);
	if (sa.size > 1)
		push_swap(&sa, &sb);
	free(sa.util);
}

int	main(int ac, char **av)
{
	push(ac, av);
	return (0);
}
