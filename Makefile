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
DEBUG = -fdiagnostics-color=always -g
CFLAGS =  -I includes/
FILES = \
		utils/other/*.c \
		utils/push_swap/*.c \
		utils/LICS/*.c \
		utils/linked_list/*.c \
		algo/utils/*.c 

all:
	gcc $(CFLAGS) $(DEBUG) main.c $(FILES) -o push_swap.exe
dis:
	gcc $(CFLAGS) $(DEBUG) display.c $(FILES) -o dis_push_swap.exe
lics:
	gcc $(CFLAGS) $(DEBUG) 	main.c $(FILES) -o lics.exe
