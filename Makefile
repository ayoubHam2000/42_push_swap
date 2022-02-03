# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/08 23:35:59 by aben-ham          #+#    #+#              #
#    Updated: 2022/02/03 14:17:29 by aben-ham         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#-Wall -Wextra -Werror
#DEBUG = -fdiagnostics-color=always -g
#ls -d algo/main/* algo/utils/* utils/push_swap/* 
#utils/other/* utils/linked_list/* utils/LICS/* 
#| grep "" | sed 's/$/ \\/'

FILES = \
		algo/main/adjust.c \
		algo/main/get_best_rule.c \
		algo/main/get_lis.c \
		algo/main/to_stack_a.c \
		algo/main/to_stack_b.c \
		algo/utils/find_s_min.c \
		utils/LICS/clone.c \
		utils/LICS/create.c \
		utils/LICS/delete.c \
		utils/LICS/lics.c \
		utils/LICS/lis.c \
		utils/LICS/type.c \
		utils/linked_list/l_append_end.c \
		utils/linked_list/l_append_front.c \
		utils/linked_list/l_clone.c \
		utils/linked_list/l_create_node.c \
		utils/linked_list/l_del_all.c \
		utils/linked_list/l_del_by_index.c \
		utils/linked_list/l_del_by_prev.c \
		utils/linked_list/l_del_cond.c \
		utils/linked_list/l_del_node.c \
		utils/linked_list/l_get.c \
		utils/linked_list/l_init.c \
		utils/linked_list/l_len.c \
		utils/other/ft_atoi.c \
		utils/other/ft_error.c \
		utils/other/ft_malloc.c \
		utils/other/ft_max.c \
		utils/other/ft_min.c \
		utils/push_swap/checker.c \
		utils/push_swap/ft_exec.c \
		utils/push_swap/push.c \
		utils/push_swap/reverse_rotate.c \
		utils/push_swap/rotate.c \
		utils/push_swap/stack.c \
		utils/push_swap/swap.c \
		main.c

FILES_BONUS = \
		utils/linked_list/l_append_end.c \
		utils/linked_list/l_append_front.c \
		utils/linked_list/l_clone.c \
		utils/linked_list/l_create_node.c \
		utils/linked_list/l_del_all.c \
		utils/linked_list/l_del_by_index.c \
		utils/linked_list/l_del_by_prev.c \
		utils/linked_list/l_del_cond.c \
		utils/linked_list/l_del_node.c \
		utils/linked_list/l_get.c \
		utils/linked_list/l_init.c \
		utils/linked_list/l_len.c \
		utils/other/ft_atoi.c \
		utils/other/ft_error.c \
		utils/other/ft_malloc.c \
		utils/other/ft_max.c \
		utils/other/ft_min.c \
		utils/push_swap/checker.c \
		utils/push_swap/ft_exec.c \
		utils/push_swap/push.c \
		utils/push_swap/reverse_rotate.c \
		utils/push_swap/rotate.c \
		utils/push_swap/stack.c \
		utils/push_swap/swap.c \
		_checker/get_next_line/get_next_line.c \
		_checker/get_next_line/utils.c \
		_checker/get_instrinction.c \
		_checker/main.c

CFLAGS =  -Wall -Wextra -Werror -I includes/
DEPFLAGS = -MMD -MF $(@:.o=.d)

NAME = push_swap
BONUS_NAME = checker

OBJ_DIR = obj/
OBJ_DIR_BONUS = obj/bonus/

OBJ = $(addprefix $(OBJ_DIR), $(FILES:.c=.o))
OBJ_BONUS = $(addprefix $(OBJ_DIR_BONUS), $(FILES_BONUS:.c=.o))

deps = $(OBJ:.o=.d)
deps_bonus = $(OBJ_BONUS:.o=.d)

all : $(NAME)

$(NAME) : $(OBJ)
	gcc $(OBJ) -o $(NAME)

$(OBJ) : $(OBJ_DIR)%.o : %.c
	mkdir -p $(dir $@)
	gcc $(CFLAGS) -c $(@:obj/%.o=%.c) $(DEPFLAGS) -o $@

-include $(deps)

##################

bonus : $(BONUS_NAME)

$(BONUS_NAME) : $(OBJ_BONUS)
	gcc $(OBJ_BONUS) -o $(BONUS_NAME)

$(OBJ_BONUS) : $(OBJ_DIR_BONUS)%.o : %.c
	mkdir -p $(dir $@)
	gcc $(CFLAGS) -c $(@:obj/bonus/%.o=%.c) $(DEPFLAGS) -o $@

-include $(deps_bonus)

###################

clean :
	rm -rf $(OBJ_DIR)

fclean : clean
	rm -f $(NAME)
	rm -f $(BONUS_NAME)

re : fclean all
