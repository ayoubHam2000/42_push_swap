/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 23:35:32 by aben-ham          #+#    #+#             */
/*   Updated: 2022/01/16 20:07:28 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_swap(t_stack *s)
{
	int	tmp;

	if (s->size < 2)
		return ;
	tmp = s->s[s->size - 1];
	s->s[s->size - 1] = s->s[s->size - 2];
	s->s[s->size - 2] = tmp;
}

int	ft_sa(t_stack *stack, int affect)
{
	if (affect)
	{
		ft_swap(stack);
		write(1, "sa\n", 3);
	}
	return (1);
}

int	ft_sb(t_stack *stack, int affect)
{
	if (affect)
	{
		ft_swap(stack);
		write(1, "sb\n", 3);
	}
	return (1);
}

int	ft_ss(t_stack *sa, t_stack *sb, int affect)
{
	if (affect)
	{
		ft_swap(sa);
		ft_swap(sb);
		write(1, "ss\n", 1);
	}
	return (1);
}

