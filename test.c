/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 23:36:08 by aben-ham          #+#    #+#             */
/*   Updated: 2022/01/20 23:44:13 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <termios.h>
#include <stdio.h>
#include "utils/memory/mem.h"

int main()
{
    int i;

    i = 2;
    float f = 5 / (float)i;
    printf("%f\n", f);
}

/*
in B
rotate or swap

A : 12 -> 11 -> 9 -> 8 -> 7 -> 6 -> 5 -> 4 -> 2 -> 1
B : 20 -> 21 -> 15 -> 13 -> 14

== where is the most likley min

*/

// ./push_swap.out `seq 0 4 | sort -R | tr '\n' ' '` > out


/*
"args": [
                "-I",
                "${workspaceFolder}\\push_swap.h",
                "-fdiagnostics-color=always",
                "-g",
                "${workspaceFolder}\\main.c",
                "${workspaceFolder}\\utils\\*.c",
                "${workspaceFolder}\\algo\\*.c",
                "-o",
                "${workspaceFolder}\\push_swap.out"
            ],


"program": "${workspaceFolder}/push_swap.out",
			"args": ["1", "2", "3", "4", "5"],


*/



/*

void	exec_ma_1_part_2(t_stack *sa, t_stack *sb, t_m_info *info)
/*ft_exec(sa, sb, info->si[1] + info->si[2] - 2, RB);
	i = 2;
	while (++i < info->n)
	{
		ft_exec(sa, sb, 1, PA);
		exec_rr_or_ra(sa, sb, info->si[i]);
		ft_exec(sa, sb, info->si[i] - 1, RB);
	}
	ft_exec(sa, sb, 1, PA | RA << 4);*/

//1 4 5 3 2