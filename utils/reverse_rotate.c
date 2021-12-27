/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayoub <ayoub@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 23:02:49 by ayoub             #+#    #+#             */
/*   Updated: 2021/12/27 23:22:24 by ayoub            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	ft_shift_down(t_stack *s)
{
	int	tmp;
	int	i;

	tmp = s->s[0];
	i = 0;
	while (i < s->size - 1)
	{
		s->s[i + 1] = s->s[i];
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
