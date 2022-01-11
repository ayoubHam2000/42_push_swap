/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 07:11:00 by aben-ham          #+#    #+#             */
/*   Updated: 2022/01/10 20:31:22 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	change_left_b(t_stack *sa, t_stack *sb)
{
	int	i;

	i = sb->minPos + 1;
	//printf("Left B\n");
	while (i > 0)
	{
		ft_rrb(sb);
		i--;
	}
	sb->minPos = -1;
	ft_pa(sa, sb);
	ft_ra(sa);
}

void	change_right_b(t_stack *sa, t_stack *sb)
{
	int	i;

	//printf("Right B\n");
	i = sb->size - sb->minPos - 1;
	while (i > 0)
	{
		ft_rb(sb);
		i--;
	}
	sb->minPos = -1;
	ft_pa(sa, sb);
	ft_ra(sa);
}
