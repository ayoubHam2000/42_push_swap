# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/08 23:35:59 by aben-ham          #+#    #+#              #
#    Updated: 2022/01/21 00:49:01 by aben-ham         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#-Wall -Wextra -Werror
CFLAGS =  -I.
FILES = \
		algo/calc/*.c \
		algo/exec/a/*.c \
		algo/exec/b/*.c \
		algo/exec/u/*.c \
		algo/utils/*.c \
		algo/main/*.c \
		utils/other/*.c \
		utils/memory/*.c \
		utils/push_swap/*.c
all:
	gcc $(CFLAGS) main.c $(FILES) -o push_swap.out
dis:
	gcc $(CFLAGS) display.c $(FILES) -o dis_push_swap.out

