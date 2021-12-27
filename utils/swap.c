/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayoub <ayoub@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 22:17:02 by ayoub             #+#    #+#             */
/*   Updated: 2021/12/27 23:01:45 by ayoub            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	ft_swap(t_stack *s)
{
	int	tmp;

	if (s->size < 2)
		return ;
	tmp = s->s[s->size - 1];
	s->s[s->size - 1] = s->s[s->size - 2];
	s->s[s->size - 2] = tmp;
}

void	ft_sa(t_stack *stack)
{
	ft_swap(stack);
	write(1, "sa\n", 3);
}

void	ft_sb(t_stack *stack)
{
	ft_swap(stack);
	write(1, "sb\n", 3);
}

void	ft_ss(t_stack *sa, t_stack *sb)
{
	ft_swap(sa);
	ft_swap(sb);
	write(1, "ss\n", 1);
}
