/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayoub <ayoub@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 22:35:17 by ayoub             #+#    #+#             */
/*   Updated: 2021/12/29 01:43:17 by ayoub            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	ft_push(t_stack *sa, t_stack *sb)
{
	if (sb->size == 0)
		return ;
	sa->s[sa->size] = sb->s[sb->size - 1];
	sa->size++;
	sb->size--;
}

void	ft_pa(t_stack *sa, t_stack *sb)
{
	ft_push(sa, sb);
	write(1, "pa\n", 3);
}

void	ft_pb(t_stack *sa, t_stack *sb)
{
	ft_push(sb, sa);
	write(1, "pb\n", 3);
}
