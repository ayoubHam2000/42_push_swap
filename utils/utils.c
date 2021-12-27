/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayoub <ayoub@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 22:41:14 by ayoub             #+#    #+#             */
/*   Updated: 2021/12/28 00:43:25 by ayoub            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_error(void)
{
	write(2, "Error\n", 6);
}

static int	is_blank(char c)
{
	if (c == ' ' || c == '\f'
		|| c == '\v' || c == '\t' || c == '\n' || c == '\r')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int					signe;
	unsigned long long	res;

	while (is_blank(*str))
		str++;
	signe = 1;
	if (*str == '-')
		signe = -1;
	if (*str == '+' || *str == '-')
		str++;
	res = 0;
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10;
		res = res + (*str - '0');
		str++;
	}
	return (res * signe);
}

int	int_check(char *str)
{
	int					signe;
	unsigned long long	res;

	while (is_blank(*str))
		str++;
	signe = 1;
	if (*str == '-')
		signe = -1;
	if (*str == '+' || *str == '-')
		str++;
	if (!(*str >= '0' && *str <= '9'))
		return (0);
	res = 0;
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10;
		res = res + (*str - '0');
		if ((res > 0x7fffffff && signe == 1)
			|| (res > 0x80000000 && signe == -1))
			return (0);
		str++;
	}
	return (*str == 0);
}

int	dup_check(t_stack *s)
{
	int	i;
	int	j;

	i = 0;
	while (i < s->size)
	{
		j = i + 1;
		while (j < s->size)
		{
			if (s->s[i] == s->s[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
