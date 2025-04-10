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

##############
## COMPILES ##
##############
NAME = fractol
ARCH = fractol.a

######################
## COMMANDS & FLAGS ##
######################
CC = cc
RM = rm -rf
CC_FLAGS = -Wall -Wextra -Werror -g
MLX_FLAGS = -lXext -lX11 -lm

##################
## SOURCE FILES ##
##################
OBJ_PATH = .obj
OBJ = $(addprefix $(OBJ_PATH)/, $(notdir $(SRC:.c=.o)))
SRC_PATH = src
SRC = $(addprefix $(SRC_PATH)/, main.c \
								parse.c \
								color_utils.c \
								color_profiles.c \
								render.c \
								draw_utils.c \
								math_utils.c \
								events.c \
								event_helpers.c \
								fractal.c \
								inits.c )

###############
## LIBRARIES ##
###############
LIBFT = $(LIBFT_PATH)/libft.a
LIBFT_PATH = libft
MLX = $(MLX_PATH)/libmlx_Linux.a
MLX_PATH = mlx-linux

###########
## RULES ##
###########
all: $(OBJ_PATH) $(NAME)

$(NAME): $(MLX) $(OBJ) $(LIBFT) 
	@ar rcs $(ARCH) $(OBJ)
	@echo created archive
	$(CC) $(CC_FLAGS) $(MLX_FLAGS) $(OBJ) $(LIBFT) $(MLX) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_PATH)

$(MLX):
	@ git clone git@github.com:42paris/minilibx-linux.git $(MLX_PATH)
	@ echo minilibx cloned
	$(MAKE) -C $(MLX_PATH)

$(OBJ_PATH):
	mkdir $(OBJ_PATH)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	$(CC) $(CC_FLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

clean:
	$(RM) $(OBJ)
	$(RM) $(OBJ_PATH)
	@echo "deleted objects and object path"
	$(MAKE) -C $(LIBFT_PATH) clean
	@echo "deleted libft objects"

fclean: clean
	$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT_PATH) fclean
	$(RM) $(MLX_PATH)
	$(RM) $(ARCH)

re: fclean all

.Phony: all clean fclean re
