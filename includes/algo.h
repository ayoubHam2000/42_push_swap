/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 20:37:22 by ayoub             #+#    #+#             */
/*   Updated: 2022/01/25 22:08:31 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGO_H
# define ALGO_H

# include "LICS.h"
# include "push_swap.h"

# define R1 1
# define R2 2
# define R3 3
# define R4 4

typedef struct	s_info
{
	int	a;
	int	b;
	int	old_moves;
	void	(*f)(t_stack *sa, t_stack *sb, int a, int b);
}	t_info;

void	*transform(t_stack *sa);
int		min_pos(t_stack *s);

void	to_stack_b(t_stack *sa, t_stack *sb, t_list *lis);
t_list	*get_lis(t_list *lics, int b);
void	*get_best_rule(t_stack *sa, t_stack *sb, int a, int b);
void	adjust(t_stack *sa, t_stack *sb);
void	to_stack_a(t_stack *sa, t_stack *sb);

#endif
