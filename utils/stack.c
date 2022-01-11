/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 23:35:25 by aben-ham          #+#    #+#             */
/*   Updated: 2022/01/09 00:06:01 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	stack_error(t_stack *s)
{
	if (s->s)
		free(s->s);
	ft_error();
	
	exit(0);
}

void	init_stack(t_stack *s, int max, char **values, char tag)
{
	int	i;

	s->s = malloc(sizeof(int) * max);
	if (!(s->s))
		stack_error(s);
	s->size = 0;
	s->tag = tag;
	s->minPos = -1;
	i = 0;
	while (i < max && values)
	{
		if (int_check(values[i]))
			s->s[max - i - 1] = ft_atoi(values[i]);
		else
			stack_error(s);
		i++;
		s->size++;
	}
	if (!dup_check(s))
		stack_error(s);
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
