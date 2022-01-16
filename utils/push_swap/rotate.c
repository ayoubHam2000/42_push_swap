/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 23:35:19 by aben-ham          #+#    #+#             */
/*   Updated: 2022/01/16 20:05:04 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_shift_up(t_stack *s)
{
	int	tmp;
	int	i;

	tmp = s->s[s->size - 1];
	i = s->size - 1;
	while (i > 0)
	{
		s->s[i] = s->s[i - 1];
		i--;
	}
	s->s[0] = tmp;
}

int	ft_ra(t_stack *s, int affect)
{
	if (affect)
	{
		ft_shift_up(s);
		write(1, "ra\n", 3);
	}
	return (1);
}

int	ft_rb(t_stack *s, int affect)
{
	if (affect)
	{
		ft_shift_up(s);
		write(1, "rb\n", 3);
	}
	return (1);
}

int	ft_rr(t_stack *a, t_stack *b, int affect)
{
	if (affect)
	{
		ft_shift_up(a);
		ft_shift_up(b);
		write(1, "rr\n", 3);
	}
	return (1);
}

