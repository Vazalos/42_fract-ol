# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: david-fe <david-fe@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/26 11:26:07 by david-fe          #+#    #+#              #
#    Updated: 2025/02/27 14:58:48 by david-fe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
CC = cc
RM = rm -f
CC_FLAGS = -Wall -Wextra -Werror -g
MLX_FLAGS = -lXext -lX11 -lm
OBJ_PATH = .obj
OBJ = $(addprefix $(OBJ_PATH)/, $(notdir $(SRC:.c=.o)))
SRC = $(addprefix $(SRC_PATH)/, main.c \
								color.c \
								draw_utils.c \
								events.c \
								fractal.c)
SRC_PATH = src

ARC = fractol.a
LIBFT = $(LIBFT_PATH)/libft.a
LIBFT_PATH = libft
MLX = $(MLX_PATH)/libmlx_Linux.a
MLX_PATH = mlx-linux

all: $(OBJ_PATH) $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(MLX) 
	ar rcs $(ARC) $(OBJ)
	$(CC) $(CC_FLAGS) $(MLX_FLAGS) $(OBJ) $(LIBFT) $(MLX) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_PATH)

$(MLX):
	$(MAKE) -C $(MLX_PATH)

$(OBJ_PATH):
	mkdir $(OBJ_PATH)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	$(CC) $(CC_FLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

clean:
	$(RM) $(OBJ)
	$(MAKE) -C $(LIBFT_PATH) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_PATH) fclean

re: fclean all

.Phony: all clean fclean re
