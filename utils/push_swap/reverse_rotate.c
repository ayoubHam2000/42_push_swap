/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 23:35:09 by aben-ham          #+#    #+#             */
/*   Updated: 2022/01/12 00:42:43 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_shift_down(t_stack *s)
{
	int	tmp;
	int	i;

	tmp = s->s[0];
	i = 0;
	while (i < s->size - 1)
	{
		s->s[i] = s->s[i + 1];
		i++;
	}
	s->s[i] = tmp;
}

void	ft_rra(t_stack *s)
{
	ft_shift_down(s);
	write(1, "rra\n", 4);
}

void	ft_rrb(t_stack *s)
{
	ft_shift_down(s);
	write(1, "rrb\n", 4);
}

void	ft_rrr(t_stack *a, t_stack *b)
{
	ft_shift_down(a);
	ft_shift_down(b);
	write(1, "rrr\n", 4);
}

void	g_rev_rotate(t_stack *s)
{
	if (s->tag == SA)
		ft_rra(s);
	else if (s->tag == SB)
		ft_rrb(s);
}
