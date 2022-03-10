# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nlouro <nlouro@student.42heilbronn.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/22 14:47:05 by nlouro            #+#    #+#              #
#    Updated: 2022/03/10 17:40:18 by nlouro           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PUSH_SWAP = push_swap

C_FLAGS = -Wall -Wextra -Werror
LIBFT_DIR = libft
LIBFT_OBJ = libft.a

C_FILES = push_swap.c stack_operators.c sort.c radix.c utils.c init.c
O_FILES = $(C_FILES:%.c=%.o)

all: $(PUSH_SWAP)

$(PUSH_SWAP): $(O_FILES) $(LIBFT_OBJ)
	gcc $(C_FLAGS) $(O_FILES) $(LIBFT_DIR)/$(LIBFT_OBJ) -o $(PUSH_SWAP)

$(O_FILES): $(C_FILES) $(LIBFT_OBJ)
	gcc -c $(C_FLAGS) $(C_FILES) -I$(LIBFT_DIR)

$(LIBFT_OBJ):
	make -C $(LIBFT_DIR)

clean:
	rm -f  $(O_FILES)

fclean: clean
	rm -f $(PUSH_SWAP)

re: fclean all
