/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 23:36:04 by aben-ham          #+#    #+#             */
/*   Updated: 2022/01/16 20:07:55 by aben-ham         ###   ########.fr       */
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
	int	nbr_ele;
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
int	ft_pa(t_stack *sa, t_stack *sb, int	affect);
int	ft_pb(t_stack *sa, t_stack *sb, int affect);
/* ./utils/push_swap/reverse_rotate.c */
int	ft_rra(t_stack *s, int affect);
int	ft_rrb(t_stack *s, int affect);
int	ft_rrr(t_stack *a, t_stack *b, int affect);
/* ./utils/push_swap/rotate.c */
int	ft_ra(t_stack *s, int affect);
int	ft_rb(t_stack *s, int affect);
int	ft_rr(t_stack *a, t_stack *b, int affect);
/* ./utils/push_swap/stack.c */
void *init_stack(t_stack *s, int max, char **values, char tag);
void *init_util(void);
void print_stack(t_stack s);
/* ./utils/push_swap/swap.c */
int	ft_sa(t_stack *stack, int affect);
int	ft_sb(t_stack *stack, int affect);
int	ft_ss(t_stack *sa, t_stack *sb, int affect);
/* ./utils/ft_atoi.c */
int ft_atoi(const char *str);
/* ./utils/ft_error.c */
void *ft_error(void);

#endif
