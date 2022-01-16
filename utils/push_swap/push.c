/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 22:35:17 by aben-ham          #+#    #+#             */
/*   Updated: 2022/01/16 02:19:47 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_push(t_stack *sa, t_stack *sb)
{
	if (sb->size == 0)
		return ;
	sa->s[sa->size] = sb->s[sb->size - 1];
	sa->size++;
	sb->size--;
}

int	ft_pa(t_stack *sa, t_stack *sb, int	affect)
{
	if (affect)
	{
		ft_push(sa, sb);
		write(1, "pa\n", 3);
	}
	return (1);
}

int	ft_pb(t_stack *sa, t_stack *sb, int affect)
{
	if (affect)
	{
		ft_push(sb, sa);
		write(1, "pb\n", 3);
	}
	return (1);
}
