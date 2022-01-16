/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 23:35:09 by aben-ham          #+#    #+#             */
/*   Updated: 2022/01/16 02:22:09 by aben-ham         ###   ########.fr       */
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

int	ft_rra(t_stack *s, int affect)
{
	if (affect)
	{
		ft_shift_down(s);
		write(1, "rra\n", 4);
	}
	return (1);
}

int	ft_rrb(t_stack *s, int affect)
{
	if (affect)
	{
		ft_shift_down(s);
		write(1, "rrb\n", 4);
	}
	return (1);
}

int	ft_rrr(t_stack *a, t_stack *b, int affect)
{
	if (affect)
	{
		ft_shift_down(a);
		ft_shift_down(b);
		write(1, "rrr\n", 4);
	}
	return (1);
}

