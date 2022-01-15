/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayoub <ayoub@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 23:36:08 by aben-ham          #+#    #+#             */
/*   Updated: 2022/01/15 17:25:54 by ayoub            ###   ########.fr       */
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