/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 23:36:04 by aben-ham          #+#    #+#             */
/*   Updated: 2022/01/09 10:05:55 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>

# include <stdio.h>
# include <string.h>

# define SA 'a'
# define SB 'b'

# define LEFT 0
# define RIGHT 1
# define _LEFT 2
# define _RIGHT 3

typedef struct s_stack
{
	int		*s;
	int		size;
	char	tag;
	int		minPos;
}	t_stack;

/* utils/push.c */
void	ft_pa(t_stack *sa, t_stack *sb);
void	ft_pb(t_stack *sa, t_stack *sb);
void	g_push(t_stack *sa, t_stack *sb);
/* utils/reverse_rotate.c */
void	ft_rra(t_stack *s);
void	ft_rrb(t_stack *s);
void	ft_rrr(t_stack *a, t_stack *b);
void	g_rev_rotate(t_stack *s);
/* utils/rotate.c */
void	ft_ra(t_stack *s);
void	ft_rb(t_stack *s);
void	ft_rr(t_stack *a, t_stack *b);
void	g_rotate(t_stack *s);
/* utils/stack.c */
void	init_stack(t_stack *s, int max, char **values, char tag);
void	print_stack(t_stack s);
/* utils/swap.c */
void	ft_sa(t_stack *stack);
void	ft_sb(t_stack *stack);
void	ft_ss(t_stack *sa, t_stack *sb);
void	g_swap(t_stack *s);
/* utils/utils.c */
void	ft_error(void);
int		ft_atoi(const char *str);
int		int_check(char *str);
int		dup_check(t_stack *s);

/* algo/min.c */
int		find_min_index(t_stack *s, int start);
int		find_sm_size(t_stack *s);
int		find_s_min(t_stack *s);
void	find_next_min(t_stack *sa, t_stack *sb);
/* algo/direction */
int		direction(t_stack *s);
/* algo/change_a.c */
void change_left_a(t_stack *sa);
void change_right_a(t_stack *sa);
void change__left_a(t_stack *sa, t_stack *sb);
void change__right_a(t_stack *sa, t_stack *sb);
/* algo/change_b.c */
void change_left_b(t_stack *sa, t_stack *sb);
void change_right_b(t_stack *sa, t_stack *sb);
/* algo/steps.c */
int step(t_stack *sa, t_stack *sb);

#endif
