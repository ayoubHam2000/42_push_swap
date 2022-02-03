/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 23:35:09 by aben-ham          #+#    #+#             */
/*   Updated: 2022/02/03 14:50:47 by aben-ham         ###   ########.fr       */
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
	if (s->util->checker)
		return ;
	write(1, "rra\n", 4);
}

void	ft_rrb(t_stack *s)
{
	ft_shift_down(s);
	if (s->util->checker)
		return ;
	write(1, "rrb\n", 4);
}

void	ft_rrr(t_stack *a, t_stack *b)
{
	ft_shift_down(a);
	ft_shift_down(b);
	if (a->util->checker)
		return ;
	write(1, "rrr\n", 4);
}
