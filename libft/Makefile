# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eslamber <eslamber@student.42.ft>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/08 07:23:10 by eslamber          #+#    #+#              #
#    Updated: 2022/11/16 17:22:37 by eslamber         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#
### Variables allocations
#

SRC := ft_atoi.c \
	   ft_strjoin.c \
	   ft_bzero.c \
	   ft_strlcat.c \
	   ft_calloc.c \
	   ft_strlcpy.c \
	   ft_isalnum.c \
	   ft_strlen.c \
	   ft_isalpha.c \
	   ft_strmapi.c \
	   ft_isascii.c \
	   ft_memchr.c \
	   ft_strncmp.c \
	   ft_isdigit.c \
	   ft_memcmp.c \
	   ft_strnstr.c \
	   ft_isprint.c \
	   ft_memcpy.c \
	   ft_strchr.c \
	   ft_strrchr.c \
	   ft_itoa.c \
	   ft_memmove.c \
	   ft_strtrim.c \
	   ft_memset.c \
	   ft_substr.c \
	   ft_split.c \
	   ft_tolower.c \
	   ft_strdup.c \
	   ft_toupper.c \
	   ft_striteri.c \
	   ft_putchar_fd.c \
	   ft_putstr_fd.c \
	   ft_putendl_fd.c \
	   ft_putnbr_fd.c
OBJ := $(SRC:%.c=%.o)

SRC_BONUS := $(SRC) \
			 ft_lstiter_bonus.c \
			 ft_lstlast_bonus.c \
			 ft_lstmap_bonus.c \
			 ft_lstnew_bonus.c \
			 ft_lstsize_bonus.c \
			 ft_lstadd_back_bonus.c \
			 ft_lstadd_front_bonus.c \
			 ft_lstclear_bonus.c \
			 ft_lstdelone_bonus.c
OBJ_BONUS := $(SRC_BONUS:%.c=%.o)

NAME := libft.a
HEADER := libft.h

FLAGS := -Wall -Wextra -Werror
CC := cc

#
### compilations rules
#

all: $(NAME)

bonus: $(OBJ_BONUS)
	ar rcs $(NAME) $^

$(NAME): $(OBJ)
	ar rcs $@ $^

%.o: %.c $(HEADER) Makefile
	$(CC) $(FLAGS) -c $< -o $@

#
### Cleaning rules
#

clean: 
	@rm -v $(OBJ)

clean_bonus:
	@rm -v $(OBJ_BONUS)

fclean: clean
	@rm -v $(NAME)

fclean_bonus: clean_bonus
	@rm -v $(NAME)

re: fclean all

rebonus: fclean_bonus bonus

.PHONY: clean fclean re all clean_bonus bonus fclean_bonus rebonus
