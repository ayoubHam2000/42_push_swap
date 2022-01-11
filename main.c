/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 23:35:53 by aben-ham          #+#    #+#             */
/*   Updated: 2022/01/10 23:24:20 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	push_swap(t_stack *sa, t_stack *sb)
{
	int	i;

	i = 2;
	while (i != -1)
	{
		//print_stack(*sa);
		//print_stack(*sb);
		i = step(sa, sb);
		//print_stack(*sa);
		//print_stack(*sb);
		//printf("---------------\n");
		//getchar();	
	}
}

void	change_a_right(t_stack *sa, t_stack *sb)
{
	//make;./push_swap.out 7 5 6 10 9 4 1 2 3
	int i = 4;
	while (--i > 0)
		ft_pb(sa, sb);
	print_stack(*sa);
	print_stack(*sb);
	find_next_min(sa, sb);
	printf("%d\n", sa->minPos);
	printf("%d\n", sb->minPos);
	change__right_a(sa, sb);
	print_stack(*sa);
	print_stack(*sb);
}

void	change_a_left(t_stack *sa, t_stack *sb)
{
	//make;./push_swap.out 7 6 5 15 13 14 11 12 2 9 10 8 1
	int i = 7;
	while (--i > 0)
		ft_pb(sa, sb);
	print_stack(*sa);
	print_stack(*sb);
	find_next_min(sa, sb);
	printf("%d\n", sa->minPos);
	printf("%d\n", sb->minPos);
	printf("%d\n", direction(sa));
	change__left_a(sa, sb);
	print_stack(*sa);
	print_stack(*sb);
}

int	main(int ac, char **av)
{
	t_stack	sa;
	t_stack	sb;

	av++;
	init_stack(&sa, ac - 1, av, SA);
	init_stack(&sb, ac - 1, NULL, SB);
	print_stack(sa);
	//change_a_left(&sa, &sb);
	push_swap(&sa, &sb);
	print_stack(sa);
	return (0);
}
