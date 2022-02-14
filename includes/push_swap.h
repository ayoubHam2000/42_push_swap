/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 23:36:04 by aben-ham          #+#    #+#             */
/*   Updated: 2022/02/14 10:52:05 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include "ft_mem.h"

# define SA 1
# define SB 2
# define SS 3
# define PA 4
# define PB 5
# define RA 6
# define RB 7
# define RR 8
# define RRA 9
# define RRB 10
# define RRR 11

# define LEFT 0
# define RIGHT 1
# define _LEFT 2
# define _RIGHT 3

typedef struct s_stack	t_stack;

typedef struct s_util
{
	int		sm_size;
	int		moves;
	int		affect;
	id_t	checker;
}	t_util;

struct s_stack
{
	int		*s;
	int		size;
	char	tag;
	t_util	*util;
};

int		int_check(char *str);
int		dup_check(t_stack *s);

void	ft_pa(t_stack *sa, t_stack *sb);
void	ft_pb(t_stack *sa, t_stack *sb);
void	ft_rra(t_stack *s);
void	ft_rrb(t_stack *s);
void	ft_rrr(t_stack *a, t_stack *b);
void	ft_ra(t_stack *s);
void	ft_rb(t_stack *s);
void	ft_rr(t_stack *a, t_stack *b);
void	ft_sa(t_stack *stack);
void	ft_sb(t_stack *stack);
void	ft_ss(t_stack *sa, t_stack *sb);
void	ft_exec(t_stack *sa, t_stack *sb, int nb, int commands);

void	*init_stack(t_stack *s, int max, char **values, char tag);
void	*init_util(void);
void	init_push(t_stack *sa, t_stack *sb, int ac, char **av);

int		ft_atoi(const char *str);
int		ft_max(int a, int b);
int		ft_min(int a, int b);
void	ft_error(void);

#endif
