/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 23:35:48 by aben-ham          #+#    #+#             */
/*   Updated: 2022/01/08 23:37:07 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap_before(char *command, t_stack *a, t_stack *b)
{
	if (!strcmp(command, "sa"))
		ft_sa(a);
	else if (!strcmp(command, "sb"))
		ft_sb(b);
	else if (!strcmp(command, "ss"))
		ft_ss(a, b);
	else if (!strcmp(command, "pa"))
		ft_pb(a, b);
	else if (!strcmp(command, "pb"))
		ft_pa(a, b);
	else if (!strcmp(command, "ra"))
		ft_rra(a);
	else if (!strcmp(command, "rb"))
		ft_rrb(b);
	else if (!strcmp(command, "rr"))
		ft_rrr(a, b);
	else if (!strcmp(command, "rra"))
		ft_ra(a);
	else if (!strcmp(command, "rrb"))
		ft_rb(b);
	else if (!strcmp(command, "rrr"))
		ft_rr(a, b);	
}

void	push_swap_next(char *command, t_stack *a, t_stack *b)
{
	if (!strcmp(command, "sa"))
		ft_sa(a);
	else if (!strcmp(command, "sb"))
		ft_sb(b);
	else if (!strcmp(command, "ss"))
		ft_ss(a, b);
	else if (!strcmp(command, "pa"))
		ft_pa(a, b);
	else if (!strcmp(command, "pb"))
		ft_pb(a, b);
	else if (!strcmp(command, "ra"))
		ft_ra(a);
	else if (!strcmp(command, "rb"))
		ft_rb(b);
	else if (!strcmp(command, "rr"))
		ft_rr(a, b);
	else if (!strcmp(command, "rra"))
		ft_rra(a);
	else if (!strcmp(command, "rrb"))
		ft_rrb(b);
	else if (!strcmp(command, "rrr"))
		ft_rrr(a, b);
}

void	print_commands(char (*log)[4], int len)
{
	int	i;

	i = 0;
	printf("commands (%d) : ", len);
	while (i < len)
	{
		printf("%s", log[i]);
		if (i < len - 1)
			printf("->");
		i++;
	}
	printf("\n");
}

void	push_swap(t_stack *a, t_stack *b)
{
	char	command[3];
	char	log[1000][4];
	int		i;

	i = 0;
	while (1)
	{
		system("clear");
		print_commands(log, i);
		write (1, "A : ", 4);
		print_stack(*a);
		write (1, "B : ", 4);
		print_stack(*b);
		printf("command : ");
		scanf("%s", command);
		if (!strcmp(command, "ext"))
		{
			free(a->s);
			free(b->s);
			exit(0);
		}
		else if (!strcmp(command, "bef"))
		{
			if (i == 0)
				continue ;
			i--;
			push_swap_before(log[i], a, b);
		}
		else{
			strcpy(log[i], command);
			push_swap_next(log[i], a, b);
			i++;
		}
	}
}

int	main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;

	av++;
	init_stack(&a, ac - 1, av);
	init_stack(&b, ac - 1, NULL);
	push_swap(&a, &b);
	return (0);
}
