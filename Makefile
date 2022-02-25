# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nlouro <nlouro@student.42heilbronn.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/22 14:47:05 by nlouro            #+#    #+#              #
#    Updated: 2022/02/25 18:57:12 by nlouro           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PUSH_SWAP = push_swap
CHECKER = checker

C_FLAGS = -Wall -Wextra -Werror
LIBFT_DIR = libft
LIBFT_OBJ = libft.a

C_FILES = push_swap.c stack_operators.c sort.c utils.c
CC_FILES = checker.c stack_operators.c sort.c utils.c

O_FILES = $(C_FILES:%.c=%.o)
OC_FILES = $(CC_FILES:%.c=%.o)

all: $(PUSH_SWAP)

$(CHECKER): $(OC_FILES) $(LIBFT_OBJ)
	gcc $(C_FLAGS) $(OC_FILES) $(LIBFT_DIR)/$(LIBFT_OBJ) -o $(CHECKER)

$(PUSH_SWAP): $(O_FILES) $(LIBFT_OBJ)
	gcc $(C_FLAGS) $(O_FILES) $(LIBFT_DIR)/$(LIBFT_OBJ) -o $(PUSH_SWAP)

$(O_FILES): $(C_FILES) $(LIBFT_OBJ)
	gcc -c $(C_FLAGS) $(C_FILES) -I$(LIBFT_DIR)

$(OC_FILES): $(CC_FILES) $(LIBFT_OBJ)
	gcc -c $(C_FLAGS) $(CC_FILES) -I$(LIBFT_DIR)

$(LIBFT_OBJ):
	make -C $(LIBFT_DIR)

clean:
	rm -f  $(O_FILES) $(OC_FILES)

fclean: clean
	rm -f $(PUSH_SWAP) $(CHECKER)

re: fclean all
