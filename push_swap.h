/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayoub <ayoub@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 23:36:04 by aben-ham          #+#    #+#             */
/*   Updated: 2022/01/14 20:43:51 by ayoub            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include "utils/memory/mem.h"

# include <stdio.h>
# include <string.h>

# define SA 'a'
# define SB 'b'

# define LEFT 0
# define RIGHT 1
# define _LEFT 2
# define _RIGHT 3

typedef struct s_util
{
	int	ma;
	int	mb;
	int	sm_size;
}	t_util;

typedef struct s_stack
{
	int		*s;
	int		size;
	char	tag;
	t_util	*util;
}	t_stack;

/* ./utils/push_swap/checker.c */
int int_check(char *str);
int dup_check(t_stack *s);
/* ./utils/push_swap/push.c */
void ft_pa(t_stack *sa, t_stack *sb);
void ft_pb(t_stack *sa, t_stack *sb);
void g_push(t_stack *sa, t_stack *sb);
/* ./utils/push_swap/reverse_rotate.c */
void ft_rra(t_stack *s);
void ft_rrb(t_stack *s);
void ft_rrr(t_stack *a, t_stack *b);
void g_rev_rotate(t_stack *s);
/* ./utils/push_swap/rotate.c */
void ft_ra(t_stack *s);
void ft_rb(t_stack *s);
void ft_rr(t_stack *a, t_stack *b);
void g_rotate(t_stack *s);
/* ./utils/push_swap/stack.c */
void *init_stack(t_stack *s, int max, char **values, char tag);
void *init_util(void);
void print_stack(t_stack s);
/* ./utils/push_swap/swap.c */
void ft_sa(t_stack *stack);
void ft_sb(t_stack *stack);
void ft_ss(t_stack *sa, t_stack *sb);
void g_swap(t_stack *s);
/* ./utils/ft_atoi.c */
int ft_atoi(const char *str);
/* ./utils/ft_error.c */
void *ft_error(void);

#endif
