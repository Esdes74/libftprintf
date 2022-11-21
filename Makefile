# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eslamber <eslamber@student.42.ft>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/21 10:00:43 by eslamber          #+#    #+#              #
#    Updated: 2022/11/21 11:06:36 by eslamber         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC := gcc
FLAGS := -Wall -Werror -Wextra

NAME := libftprintf.a
HEADER := libftprintf.h

DIR_LIB := libft/
LIB := $(DIR_LIB)lib_str.a
HEADER_LIB := $(DIR_LIB)lib_str.h

SRC := ft_printf.c
OBJ := $(SRC:%.c=%.o)

SRC_B := $(SRC) \
		 o_minus.c
OBJ_B := $(SRC_B:%.c=%.o)

#
### Compilation rules
#

all: $(LIB) $(NAME)

bonus: $(LIB) comp_bonus

comp_bonus: $(OBJ_B)
	ar rc $(NAME) $^

$(LIB): $(HEADER_LIB)
	@make print -C libft

$(NAME): $(OBJ)
	ar rc $@ $^

%.o: %.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

#
### Cleanup rules
#

clean:
	@rm -rfv $(OBJ_B)

fclean: clean
	@rm -rfv $(LIB) $(NAME)
	@make fclean -C libft

re: fclean all

rebonus: fclean bonus

.PHONY: all clean fclean re bonus rebonus
