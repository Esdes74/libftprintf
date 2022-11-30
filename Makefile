# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eslamber <eslamber@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/21 10:00:43 by eslamber          #+#    #+#              #
#    Updated: 2022/11/30 19:23:34 by eslamber         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC := clang
# FLAGS := -Wall -Werror -Wextra -fsanitize=address -fno-omit-frame-pointer
FLAGS := -Wall -Werror -Wextra

NAME := libftprintf.a
HEADER := libftprintf.h

DIR_LIB := libft/
LIB := $(DIR_LIB)lib_fct.a
HEADER_LIB := $(DIR_LIB)lib_fct.h

SRC := ft_printf.c \
	   conv_ten_to_hex.c
OBJ := $(SRC:%.c=%.o)

#
### Compilation rules
#

all: $(LIB) $(NAME)

$(LIB): $(HEADER_LIB)
	@make -C ./libft

$(NAME): $(OBJ)
	cp libft/libft.a $(NAME)
	ar rcUs $@ $^
	ranlib $@

%.o: %.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

#
### Cleanup rules
#

clean:
	@rm -rfv $(OBJ)
	@make clean -C libft

fclean:
	@rm -rfv $(NAME) $(OBJ)
	@make fclean -C libft

re: fclean all

.PHONY: all clean fclean re
