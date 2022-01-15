/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayoub <ayoub@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 23:35:25 by aben-ham          #+#    #+#             */
/*   Updated: 2022/01/14 20:47:58 by ayoub            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*init_stack(t_stack *s, int max, char **values, char tag)
{
	int	i;

	s->s = ft_malloc(sizeof(int) * max);
	s->size = 0;
	s->tag = tag;
	i = 0;
	while (i < max && values)
	{
		if (int_check(values[i]))
			s->s[max - i - 1] = ft_atoi(values[i]);
		else
			return (ft_error());
		i++;
		s->size++;
	}
	if (!dup_check(s))
		return (ft_error());
	return (s);
}

void	*init_util()
{
	t_util	*util;

	util = ft_malloc(sizeof(t_util));
	util->ma = -1;
	util->mb = -1;
	util->sm_size = 0;
	return (util);
}

void	print_stack(t_stack s)
{
	int	i;

	i = s.size - 1;
	while (i >= 0)
	{
		printf("%d", s.s[s.size - i - 1]);
		if (i > 0)
			printf(" -> ");
		i--;
	}
	printf("\n");
}
