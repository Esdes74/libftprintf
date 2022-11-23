# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eslamber <eslamber@student.42.ft>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/21 10:00:43 by eslamber          #+#    #+#              #
#    Updated: 2022/11/23 09:02:59 by eslamber         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC := clang
FLAGS := -Wall -Werror -Wextra -fsanitize=address -fno-omit-frame-pointer
# FLAGS := -Wall -Werror -Wextra

NAME := libftprintf.a
HEADER := libftprintf.h

DIR_LIB := libft/
LIB := $(DIR_LIB)lib_fct.a
HEADER_LIB := $(DIR_LIB)lib_fct.h

SRC := ft_printf.c \
	   conv_ten_to_hex.c
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
	ar rcs $(NAME) $^
	ranlib $(NAME)

$(LIB): $(HEADER_LIB)
	@make -C ./libft

$(NAME): $(OBJ)
	ar rcs $@ $^
	ranlib $@

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
