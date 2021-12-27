/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayoub <ayoub@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 23:59:41 by ayoub             #+#    #+#             */
/*   Updated: 2021/12/28 00:29:53 by ayoub            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;

	av++;
	init_stack(&a, ac - 1, av);
	init_stack(&b, ac - 1, NULL);
	print_stack(a);
	print_stack(b);
	return (0);
}
