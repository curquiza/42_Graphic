# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: curquiza <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/16 17:08:05 by curquiza          #+#    #+#              #
#    Updated: 2017/03/02 10:59:39 by curquiza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = gcc -g -Wall -Wextra -Werror
#CC = gcc -Wall -Wextra -Werror -fsanitize=address

INCL_FLAG = -I includes -I $(LIBFT_DIR)/includes -I $(MLX_DIR)

DIR_SRC = srcs
SRC = $(addprefix $(DIR_SRC)/, \
	  set.c \
	  keyboard.c \
	  get_file.c \
	  map_parsing.c \
	  draw_pix.c \
	  draw_line.c \
	  draw_map.c \
	  clear_map.c \
	  calc.c \
	  main.c)

DIR_OBJ = objs
OBJ = $(SRC:$(DIR_SRC)/%.c=$(DIR_OBJ)/%.o)

LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_DIR = libft
MLX = $(MLX_DIR)/libmlx.a
MLX_DIR = minilibx
LIBFT_FLAG = -L$(LIBFT_DIR) -lft
MLX_FLAG = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit

all : $(NAME)

$(LIBFT) :
	@echo "\033[1;31m-- LIBFT -----------------------\033[0m"
	@make -C $(LIBFT_DIR)
	@printf  "%-45s\033[1;33m%s\033[0m\n" "Make $@" "OK"
	@echo "\033[1;31m-- OBJECTS ---------------------\033[0m"

$(MLX) :
	@echo "\033[1;31m-- MINILIBX --------------------\033[0m"
	@make -C $(MLX_DIR)
	@printf  "%-45s\033[1;33m%s\033[0m\n" "Make $@" "OK"

$(NAME) : $(MLX) $(LIBFT) $(OBJ)
	@$(CC) $(OBJ) -o $@ $(LIBFT_FLAG) $(MLX_FLAG) $(INCL_FLAG)
	@echo "\033[1;31m-- EXEC ------------------------\033[0m"
	@printf  "%-45s\033[1;32m%s\033[0m\n" "Make $@" "OK"

$(DIR_OBJ)/%.o: $(DIR_SRC)/%.c
	@$(CC) -o $@ -c $< $(INCL_FLAG)
	@printf  "%-45s\033[1;32m%s\033[0m\n" "Make $@" "OK"

clean :
	@make clean -C $(LIBFT_DIR)
	@make clean -C $(MLX_DIR)
	@printf  "%-45s\033[1;33m%s\033[0m\n" "Make $@_libft" "OK"
	@printf  "%-45s\033[1;33m%s\033[0m\n" "Make $@_minilibx" "OK"
	@rm -f $(OBJ)
	@printf  "%-45s\033[1;32m%s\033[0m\n" "Make $@" "OK"

fclean : clean
	@make fclean -C $(LIBFT_DIR)
	@printf  "%-45s\033[1;33m%s\033[0m\n" "Make $@_libft" "OK"
	@printf  "%-45s\033[1;33m%s\033[0m\n" "Make $@_minilibx" "OK"
	@rm -f $(NAME)
	@printf  "%-45s\033[1;32m%s\033[0m\n" "Make $@" "OK"

re : fclean all
