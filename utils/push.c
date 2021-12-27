/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayoub <ayoub@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 22:35:17 by ayoub             #+#    #+#             */
/*   Updated: 2021/12/28 00:41:06 by ayoub            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//take the first element at the top of b and put it at the top of a. Do
//nothing if b is empty.

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

void	ft_pb(t_stack *sb, t_stack *sa)
{
	ft_push(sb, sa);
	write(1, "pb\n", 3);
}
