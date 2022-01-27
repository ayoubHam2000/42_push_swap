/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 20:15:25 by aben-ham          #+#    #+#             */
/*   Updated: 2022/01/27 03:13:17 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	exe_command(t_stack *sa, t_stack *sb, int command)
{
	if (command == SA)
		ft_sa(sa);
	else if (command == SB)
		ft_sb(sb);
	else if (command == SS)
		ft_ss(sa, sb);
	else if (command == PA)
		ft_pa(sa, sb);
	else if (command == PB)
		ft_pb(sa, sb);
	else if (command == RA)
		ft_ra(sa);
	else if (command == RB)
		ft_rb(sb);
	else if (command == RR)
		ft_rr(sa, sb);
	else if (command == RRA)
		ft_rra(sa);
	else if (command == RRB)
		ft_rrb(sb);
	else if (command == RRR)
		ft_rrr(sa, sb);
}

static void	exe_seq(t_stack *sa, t_stack *sb, int commands)
{
	int	c;

	while (commands)
	{
		c = commands & 0b1111;
		commands = commands >> 4;
		if (sa->util->affect)
			exe_command(sa, sb, c);
		sa->util->moves++;
	}
}

void	ft_exec(t_stack *sa, t_stack *sb, int nb, int commands)
{
	while (--nb >= 0)
		exe_seq(sa, sb, commands);
}
