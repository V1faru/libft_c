# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amurtone <amurtone@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/21 08:57:27 by amurtone          #+#    #+#              #
#    Updated: 2020/09/11 16:13:41 by amurtone         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = binary.c char.c conversions.c float.c float2.c \
		format_parse.c ft_error.c ft_printf.c hex.c \
		ints.c modifiers.c octals.c pointer.c strings.c \
		support.c support2.c udecint.c \
		ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
		ft_isprint.c ft_itoa.c ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c \
		ft_memcpy.c ft_memdel.c ft_memmove.c ft_memset.c ft_putchar.c ft_putchar_fd.c \
		ft_putendl.c ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c ft_putstr.c \
		ft_putstr_fd.c ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c \
		ft_strdel.c ft_strdup.c ft_strequ.c ft_striter.c ft_striteri.c ft_strjoin.c \
		ft_strlcat.c ft_strlen.c ft_strmap.c ft_strmapi.c ft_strncat.c ft_strncmp.c \
		ft_strncpy.c ft_strnequ.c ft_strnew.c ft_strnstr.c ft_strrchr.c ft_strsplit.c \
		ft_strstr.c ft_strsub.c ft_strtrim.c ft_tolower.c ft_toupper.c ft_lstnew.c \
		ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c get_next_line.c \
		ft_itoa_base.c ft_stradd.c
DIR_S = srcs
DIR_O = objs
OBJ = $(SRC:.c=.o)
OBJS = $(addprefix $(DIR_O)/,$(OBJ))
HEADER = includes/
CC = gcc
FLAGS = -Wall -Wextra -Werror
COLOR_RESET = \033[0m
COLOR_PENDING = \033[01;33m
COLOR_SUCCESS = \033[1;32m
COLOR_DEFAULT = \033[1;34m

all: obj_directory $(NAME)
	
obj_directory:
	@echo "$(NAME)     [$(COLOR_PENDING)Compiling...$(COLOR_RESET)]"
	mkdir -p $(DIR_O)

$(DIR_O)/%.o: $(DIR_S)/%.c
	$(CC) $(FLAGS) -I $(HEADER) -c $< -o $@
	
$(NAME): $(OBJS)
	ar rc $(NAME) $^
	@ranlib $(NAME)
	@echo "\033[A\033[K\033[A"
	@echo "$(NAME)     [$(COLOR_SUCCESS)OK$(COLOR_RESET)]"
	@echo "        [$(COLOR_SUCCESS)FINISHED$(COLOR_RESET)]"
test:
	$(CC) $(NAME) main.c
	./a.out
norme:
	@echo "$(HEADER)     [$(COLOR_PENDING)Header Norm$(COLOR_RESET)]"
	norminette ./$(HEADER)/
	@echo "$(SRCS)     [$(COLOR_PENDING)Source Norm$(COLOR_RESET)]"
	norminette ./$(SRCS)/
clean:
	@rm -rf $(DIR_O)
	@echo "$(NAME): $(COLOR_SUCCESS)$(OBJ) DELETED$(COLOR_RESET)"
	@echo "$(NAME): $(COLOR_SUCCESS)All object files were deleted$(COLOR_RESET)"
fclean: clean
	@rm -rfv $(NAME)
	@echo "$(NAME): $(COLOR_SUCCESS)$(NAME) DELETED$(COLOR_RESET)"
re: fclean all
.PHONY: all clean fclean norme re