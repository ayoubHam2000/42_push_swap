/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayoub <ayoub@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 23:36:08 by aben-ham          #+#    #+#             */
/*   Updated: 2022/01/14 20:22:25 by ayoub            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <termios.h>
#include <stdio.h>
#include "utils/memory/mem.h"

int main()
{
    int *i;

    i = ft_malloc(4);
    *i = 88;
    printf("%d\n", *i);
    ft_free(i);
    mem_clean();
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