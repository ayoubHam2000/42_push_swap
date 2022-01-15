# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ayoub <ayoub@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/08 23:35:59 by aben-ham          #+#    #+#              #
#    Updated: 2022/01/14 23:15:18 by ayoub            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#-Wall -Wextra -Werror
CFLAGS =  -I.
FILES = utils/*.c \
		utils/memory/*.c \
		utils/push_swap/*.c \
		algo/*.c
all:
	gcc $(CFLAGS) main.c $(FILES) -o push_swap.out
dis:
	gcc $(CFLAGS) display.c $(FILES) -o dis_push_swap.out

