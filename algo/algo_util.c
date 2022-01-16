/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 23:40:46 by aben-ham          #+#    #+#             */
/*   Updated: 2022/01/15 23:11:46 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algo.h"

void	*transform(t_stack *sa)
{
	int	i;
	int	j;
	int	*tmp;

	tmp = ft_malloc(sizeof(int) * sa->size);
	i = 0;
	while (i < sa->size)
	{
		j = 0;
		tmp[i] = 0;
		while (j < sa->size)
		{
			if (j != i && sa->s[j] < sa->s[i])
				tmp[i]++;
			j++;
		}
		i++;
	}
	ft_free(sa->s);
	sa->s = tmp;
	return (sa);
}

static int	find_min_form(t_stack *s, int start)
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

void	init_smin_size(t_stack *sa)
{
	int	i;

	i = 0;
	while (i < sa->size - 1)
	{
		if (sa->s[i] != sa->s[i + 1] + 1)
			break ;
		i++;
	}
	if (sa->s[i] == 0)
		sa->util->sm_size = i + 1;
}
