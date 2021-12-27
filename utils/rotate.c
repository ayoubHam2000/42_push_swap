/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayoub <ayoub@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 23:02:49 by ayoub             #+#    #+#             */
/*   Updated: 2021/12/27 23:20:57 by ayoub            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

void	ft_ra(t_stack *s)
{
	ft_shift_up(s);
	write(1, "ra\n", 3);
}

void	ft_rb(t_stack *s)
{
	ft_shift_up(s);
	write(1, "rb\n", 3);
}

void	ft_rr(t_stack *a, t_stack *b)
{
	ft_shift_up(a);
	ft_shift_up(b);
	write(1, "rr\n", 3);
}
