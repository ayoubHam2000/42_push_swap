/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayoub <ayoub@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 23:35:53 by aben-ham          #+#    #+#             */
/*   Updated: 2022/01/15 01:55:08 by ayoub            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algo.h"

#pragma region done

int	find_min_form(t_stack *s, int start)
{
	int	i;
	int	res;

	if (start >= s->size)
		return (-1);
	i = start + 1;
	res = start;
	while (i < s->size)
	{
		if (s->s[res] > s->s[i])
			res = i;
		i++;
	}
	return (res);
}

int	find_s_min(t_stack *s)
{
	if (s->tag == SA)
		return (find_min_form(s, s->util->sm_size));
	return (find_min_form(s, 0));
}

int	min_nbr(t_stack *s, int me)
{
	return (s->s[me] - s->util->sm_size + 1);
}

int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	ft_max(int a, int b)
{
	if (a < b)
		return (b);
	return (a);
}

#pragma endregion

int	find_mi(t_stack *s, int i)
{
	int	c;
	int	mi;
	
	mi = find_s_min(s);
	if (s->s[mi] != s->util->sm_size)
		return (-1);
	c = mi + 1;
	while (c < s->size && (i > 0 || i <= -1))
	{
		if (s->s[mi] + 1 == s->s[c])
		{
			mi = c;
			i--;
		}
		c++;
	}
	if (i == 0 || i <= -1)
		return (mi);
	else
		return (-1);
}

//from [0 to min_nbr[
int	size_of_si(t_stack *s, int i)
{
	int	m1;
	int	m2;

	m1 = find_mi(s, i);
	m2 = find_mi(s, i + 1);
	if (m2 == -1)
		return (-1);
	return (m2 - m1 - 1);
}

int	ms_left(t_stack *s, int ms)
{
	return (ms - s->util->sm_size);
}

int	ms_right(t_stack *s, int me)
{
	return (s->size - me - 1);
}

//sr + 3*(n-1) + 2s_1 + sum(s_i, 2, n)
//min(0, s_2 - 2) + sum(min(0, s_i - 1), 3, n)
//3 -> 4 -> 0 -> 5 -> 1 -> 8 -> 2 -> 7 -> 6
//s1 = 1; s2 = 1
//2+6+2+1	
int	cal_ma_1(t_stack *sa)
{
	int	res;
	int	ms;
	int	me;
	int	i;

	res = 0;
	ms = find_mi(sa, 0);
	if (ms == -1)
		return (-1);
	me = find_mi(sa, -1);
	res = ms_right(sa, ms); //2
	res += 3 * (min_nbr(sa, me) - 1); //6
	res += 2 * size_of_si(sa, 0); //2
	i = 0;
	while (++i < min_nbr(sa, me) - 1)
		res += size_of_si(sa, i);
	res += ft_max(0, size_of_si(sa, 1) - 2); //1+0
	i = 1;
	while (++i < min_nbr(sa, me) - 1)
		res += ft_max(0, size_of_si(sa, i) - 1);
	return (res);
}

//=============================

void	push_swap(t_stack *sa, t_stack *sb)
{
	transform(sa);
	print_stack(*sa);
	
	int ms = find_mi(sa, 0);
	int me = find_mi(sa, -1);
	printf("ms = %d,me = %d, min_nbr = %d\n",ms, me, min_nbr(sa, me));
	int	s1 = size_of_si(sa, 0);
	int	s2 = size_of_si(sa, 1);
	int	s3 = size_of_si(sa, 2);
	printf("s1 = %d\n", s1);
	printf("s2 = %d\n", s2);
	printf("s3 = %d\n", s3);
	printf("ma_1 = %d\n", cal_ma_1(sa));
}

int	main(int ac, char **av)
{
	t_stack	sa;
	t_stack	sb;
	t_util	*util;

	av++;
	init_stack(&sa, ac - 1, av, SA);
	init_stack(&sb, ac - 1, NULL, SB);
	util = init_util();
	sa.util = util;
	sb.util = util;
	push_swap(&sa, &sb);
	mem_clean();
	return (0);
}
