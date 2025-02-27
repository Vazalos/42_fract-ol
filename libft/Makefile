# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: david-fe <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/21 15:55:14 by david-fe          #+#    #+#              #
#    Updated: 2024/10/23 11:59:07 by david-fe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

#files

NAME = libft.a
OBJ = $(SRC:.c=.o)

SRC = ft_atoi.c ft_atol.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c \
ft_split.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
ft_strlen.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c \
ft_putendl_fd.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c \
ft_strlcat.c ft_toupper.c ft_putnbr_fd.c ft_tolower.c ft_strchr.c ft_strrchr.c \
ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
ft_printf.c ft_putunbr.c ft_puthex.c ft_putptr.c

BONUS_OBJ = $(BONUS_SRC:.c=.o)

BONUS_SRC = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
			ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c	

#rules

all: $(NAME) 

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

bonus: $(OBJ) $(BONUS_OBJ)
	ar rcs $(NAME) $(OBJ) $(BONUS_OBJ)

clean:
	$(RM) $(OBJ) $(BONUS_OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
