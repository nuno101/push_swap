# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nlouro <nlouro@student.42heilbronn.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/22 14:47:05 by nlouro            #+#    #+#              #
#    Updated: 2022/03/12 17:52:34 by nlouro           ###   ########.fr        #
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

$(O_FILES): $(C_FILES)
	gcc -c $(C_FLAGS) $(C_FILES) -I$(LIBFT_DIR)

$(LIBFT_OBJ):
	make -C $(LIBFT_DIR)

clean:
	rm -f  $(O_FILES)

cleanl:
	rm -f  $(O_FILES)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(PUSH_SWAP)

fcleanl: clean
	rm -f $(PUSH_SWAP)
	make -C $(LIBFT_DIR) clean

re: fclean all

rel: fcleanl all
