/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayoub <ayoub@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 22:37:42 by ayoub             #+#    #+#             */
/*   Updated: 2021/12/29 02:17:13 by ayoub            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	stack_error(t_stack *s)
{
	if (s->s)
		free(s->s);
	ft_error();
	exit(0);
}

void	init_stack(t_stack *s, int max, char **values)
{
	int	i;

	s->s = malloc(sizeof(int) * max);
	if (!(s->s))
		stack_error(s);
	s->size = 0;
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
