/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayoub <ayoub@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 22:18:25 by ayoub             #+#    #+#             */
/*   Updated: 2021/12/29 01:43:07 by ayoub            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>

# include <stdio.h>
# include <string.h>

typedef struct s_stack
{
	int	*s;
	int	size;
}	t_stack;

/* utils.c */
void	ft_error(void);
int		ft_atoi(const char *str);
int		int_check(char *str);
int		dup_check(t_stack *s);

/* stack.c */
void	init_stack(t_stack *s, int max, char **values);
void	print_stack(t_stack s);

/* swap.c */
void	ft_sa(t_stack *stack);
void	ft_sb(t_stack *stack);
void	ft_ss(t_stack *sa, t_stack *sb);

/* push.c */
void	ft_pa(t_stack *sa, t_stack *sb);
void	ft_pb(t_stack *sa, t_stack *sb);

/* rotate.c */
void	ft_ra(t_stack *s);
void	ft_rb(t_stack *s);
void	ft_rr(t_stack *a, t_stack *b);

/* reverse_rotate.c */
void	ft_rra(t_stack *s);
void	ft_rrb(t_stack *s);
void	ft_rrr(t_stack *a, t_stack *b);

#endif
