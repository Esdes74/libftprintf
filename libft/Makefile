# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eslamber <eslamber@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/18 12:35:34 by eslamber          #+#    #+#              #
#    Updated: 2022/12/08 11:19:47 by eslamber         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#
### Definitions of variables
#

# Definitions of compilation options
# FLAGS := -Wall -Werror -Wextra -fsanitize=address -fno-omit-frame-pointer
FLAGS := -Wall -Werror -Wextra
CC := gcc

# Definition of variable librairie
LIB := libft.a

# Definitions of librairies repositories
LIB_MATH := lib_math/
LIB_MATH_SRC := $(LIB_MATH)src/
LIB_MATH_OBJ := $(LIB_MATH)obj/

LIB_PRINT := lib_print/
LIB_PRINT_SRC := $(LIB_PRINT)src/
LIB_PRINT_OBJ := $(LIB_PRINT)obj/

LIB_MEM := lib_mem/
LIB_MEM_SRC := $(LIB_MEM)src/
LIB_MEM_OBJ := $(LIB_MEM)obj/

LIB_STR := lib_str/
LIB_STR_SRC := $(LIB_STR)src/
LIB_STR_OBJ := $(LIB_STR)obj/

ALL_LIB_OBJ_DIR := $(LIB_MATH_OBJ) \
				   $(LIB_PRINT_OBJ) \
				   $(LIB_MEM_OBJ) \
				   $(LIB_STR_OBJ)

ALL_LIB_SRC_DIR := $(LIB_MATH_SRC) \
				   $(LIB_PRINT_SRC) \
				   $(LIB_MEM_SRC) \
				   $(LIB_STR_SRC)

# Definition of variables needed to librairie's compilation
MATH_LIB := ft_power.c \
			ft_max.c
MATH_LIB_H := $(LIB_MATH)lib_math.h
MATH_OBJ_LIB := $(MATH_LIB:%.c=$(LIB_MATH_OBJ)%.o)

MEM_LIB := ft_bzero.c \
		   ft_calloc.c \
		   ft_memchr.c \
		   ft_memcmp.c \
		   ft_memcpy.c \
		   ft_memmove.c \
		   ft_memset.c
MEM_LIB_H := $(LIB_MEM)lib_mem.h
MEM_OBJ_LIB := $(MEM_LIB:%.c=$(LIB_MEM_OBJ)%.o)

PRINT_LIB := ft_putchar_fd.c \
			 ft_putendl_fd.c \
			 ft_putnbr_fd.c \
			 ft_putstr_fd.c
PRINT_LIB_H := $(LIB_PRINT)lib_print.h
PRINT_OBJ_LIB := $(PRINT_LIB:%.c=$(LIB_PRINT_OBJ)%.o)

STR_LIB := ft_atoi.c \
		   ft_isalnum.c \
		   ft_isascii.c \
		   ft_isprint.c \
		   ft_split.c \
		   ft_strdup.c \
		   ft_strjoin.c \
		   ft_strlcpy.c \
		   ft_strmapi.c \
		   ft_strnstr.c \
		   ft_strtrim.c \
		   ft_tolower.c \
		   ft_in.c \
		   ft_isalpha.c \
		   ft_isdigit.c \
		   ft_itoa.c \
		   ft_strchr.c \
		   ft_striteri.c \
		   ft_strlcat.c \
		   ft_strlen.c \
		   ft_strncmp.c \
		   ft_strrchr.c \
		   ft_substr.c \
		   ft_toupper.c \
		   ft_calloc_str.c
STR_LIB_H := $(LIB_STR)lib_str.h
STR_OBJ_LIB := $(STR_LIB:%.c=$(LIB_STR_OBJ)%.o)

ALL_OBJ_LIB := $(MATH_OBJ_LIB) \
			   $(MEM_OBJ_LIB) \
			   $(PRINT_OBJ_LIB) \
			   $(STR_OBJ_LIB)

#
### Compilations rules
#

all: $(LIB)

$(LIB): $(ALL_OBJ_LIB)
	ar rc $@ $^
	ranlib $@

$(MATH_OBJ_LIB): $(LIB_MATH_OBJ)%.o: $(LIB_MATH_SRC)%.c $(MATH_LIB_H) lib_fct.h
	$(CC) $(FLAGS) -c $< -o $@

$(MEM_OBJ_LIB): $(LIB_MEM_OBJ)%.o: $(LIB_MEM_SRC)%.c $(MEM_LIB_H) lib_fct.h
	$(CC) $(FLAGS) -c $< -o $@

$(PRINT_OBJ_LIB): $(LIB_PRINT_OBJ)%.o: $(LIB_PRINT_SRC)%.c $(PRINT_LIB_H) \
	lib_fct.h
	$(CC) $(FLAGS) -c $< -o $@

$(STR_OBJ_LIB): $(LIB_STR_OBJ)%.o: $(LIB_STR_SRC)%.c $(STR_LIB_H) lib_fct.h
	$(CC) $(FLAGS) -c $< -o $@

#
### Directories rules
#

make_dir:
	@echo make librairies directories
	mkdir -p $(ALL_LIB_OBJ_DIR)
	@echo done$
	@echo

#
### Prints rules
#

# Compilation of librairie with print options
print: print_ob $(ALL_OBJ_LIB) print_lb $(LIB) print_le

print_ob:
	@echo compilation lib objects files

print_oe:
	@echo compilation lib objetcs files done
	@echo

print_lb: print_oe
	@echo compilation librairie

print_le:
	@echo compilation librairie done
	@echo

#
### Cleanup rules
#

# Classiques cleaning rules
clean:
	@echo remove all objects files
	@rm -rfv $(ALL_OBJ_LIB)
	@echo

cleanlib: 
	@echo remove lib file
	@rm -rfv $(LIB)
	@echo

cleandir: 
	@echo remove all directories
	@rm -rfv $(ALL_LIB_OBJ_DIR)
	@echo

clean_git:
	@echo remove all gitignore files
	@rm -rfv ./*/obj/.gitignore
	@echo

gitignor: 
	@echo reediting of differents gitignores
	touch ./lib_math/obj/.gitignore
	@echo "*" > ./lib_math/obj/.gitignore
	@echo !.gitignore >> ./lib_math/obj/.gitignore
	cp ./lib_math/obj/.gitignore ./lib_print/obj
	cp ./lib_math/obj/.gitignore ./lib_str/obj
	cp ./lib_math/obj/.gitignore ./lib_mem/obj
	@echo

# Full cleaning rules
fclean: clean cleanlib clean_git cleandir make_dir gitignor

# Remake rules
re: fclean all

# Remakes rules with print options
reprint: fclean print

.PHONY: all make_dir print print_ob print_oe print_lb print_le clean cleandir
.PHONY: clean_git gitignor flcean re reprint clean_lib
