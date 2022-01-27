/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 23:35:53 by aben-ham          #+#    #+#             */
/*   Updated: 2022/01/27 03:30:29 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algo.h"

void	push_swap(t_stack *sa, t_stack *sb)
{
	t_list	*lic;

	//transform(sa);
	//print_stack(*sa);
	lic = LICS(sa->s, sa->size);
	//print_lists(lic);
	lic = get_lis(lic, sa->s[0]);
	//print_list_nbr(lic);
	sa->util->affect = 1;
	sa->util->sm_size = lic->len;
	to_stack_b(sa, sb, lic);
	to_stack_a(sa, sb);
	adjust(sa, sb);
	l_delete_all(lic, NULL);
	free(lic);
	printf("%d\n", check_sort(sa));
	//print_stack(*sa);
}	

void	push(int ac, char **av)
{
	t_stack	sa;
	t_stack	sb;

	init_push(&sa, &sb, ac, av);
	if (sa.size > 1)
		push_swap(&sa, &sb);
	free(sa.util);
}

int	main(int ac, char **av)
{
	push(ac, av);
	return (0);
}
