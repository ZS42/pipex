# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zsyyida <zsyyida@student42abudhabi.ae>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/28 13:27:06 by zsyyida           #+#    #+#              #
#    Updated: 2023/01/13 12:46:55 by zsyyida          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# pipex executable
NAME = pipex

#make directories
INC_DIR = include
SRC_DIR = sources
OBJ_DIR = object
LIBFT_DIR = libft
# libft.a is the library so has .a at end
LIBFT = libft.a

SRCS = main.c pipex.c path.c error.c
#will add all object files into a directory one above
# %o: %c same as .c=.o
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

CC	= gcc
RM	= rm -rf
#-fsanitize=address can be added to cflags for debugging
CFLAGS = -Wall -Werror -Wextra

#to create all of the .o files from files in SRC_DIR in OBJ_DIR
$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I $(INC_DIR) -I $(LIBFT_DIR)/$(INC_DIR) -c $< -o $@
#because the include directory for libft  is in libft.

all:	$(NAME)

# goes to file -L
# looks for library -l .All libraries have lib so ft
# this is especially important in linux. Even the order.
#"-c $< -o $@" is equivalent to "$(OBJ_SRC) -o pipex"
# -C changes the path
$(NAME): $(OBJS)
	@make all -C $(LIBFT_DIR)
	@$(CC) $(CFLAGS) $(LIBFT_DIR)/$(LIBFT) $(OBJS) -Llibft -lft -o $(NAME)
	@printf "\x1b[31mpipex ready\\x1b[0m\n";

# -o turns object files into executable (coming after it)
# @make will go to and use libft makefile to make libft
#adding an @ before a command stops it from being printed

clean:
	$(RM) $(OBJ_DIR)
	@make clean -C $(LIBFT_DIR)
	@echo "object files removed"
fclean: clean
	$(RM) $(NAME)
	@make fclean -C $(LIBFT_DIR)
	@echo "object files and binary removed"

re:	fclean all
	@echo "object files and binary removed and binary remade"

# to remove all recipes that aren't files to avoid relinking
.PHONY:		all clean fclean re