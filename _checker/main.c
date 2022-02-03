/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 13:10:45 by aben-ham          #+#    #+#             */
/*   Updated: 2022/02/03 14:58:24 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "linked_list.h"
#include "get_next_line.h"

int	get_instrinction(char *instrinction);

static int	check_sort(t_stack *sa)
{
	int	i;

	i = 0;
	while (i + 1 < sa->size)
	{
		if (sa->s[i] < sa->s[i + 1])
			return (0);
		i++;
	}
	return (1);
}

static void	checker(t_stack *sa, t_stack *sb)
{
	t_list	*list;
	t_node	*node;
	char	*instrinction;

	list = l_init();
	instrinction = get_next_line(0);
	while (instrinction)
	{
		l_append_end(list, instrinction);
		instrinction = get_next_line(0);
	}
	node = list->head;
	while (node)
	{
		instrinction = node->p;
		ft_exec(sa, sb, 1, get_instrinction(instrinction));
		node = node->next;
	}
	if (check_sort(sa))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	l_del_all(list, NULL);
	free(list);
}

static void	free_stack(t_stack *sa, t_stack *sb)
{
	free(sa->s);
	free(sb->s);
	free(sa->util);
}

int	main(int ac, char **av)
{
	t_stack	sa;
	t_stack	sb;

	init_push(&sa, &sb, ac, av);
	sa.util->affect = 1;
	sa.util->checker = 1;
	if (sa.size)
		checker(&sa, &sb);
	free_stack(&sa, &sb);
	return (0);
}
