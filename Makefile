# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pthiruma <pthiruma@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/28 13:04:00 by pthiruma          #+#    #+#              #
#    Updated: 2023/07/13 22:01:59 by pthiruma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := push_swap

LIBFT_A := ./inc/libft/libft.a

HEADERS := -I ./inc -I ./inc/libft

CC := cc

SRCS =  $(shell find ./src ./utils -iname "*.c")

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

LIBFT_SRCS = $(shell find ./inc/libft -iname "*.c")

LIBFT_OBJS = $(LIBFT_SRCS:.c=.o)

LIBS = -L./inc/libft -lft

all: $(NAME) $(LIBFT_A)

$(NAME): $(OBJS) $(LIBFT_A)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)

$(LIBFT_A): $(LIBFT_OBJS)
	ar -rcs $@ $^

clean:
	rm -f $(OBJS) $(LIBFT_OBJS)

fclean: clean
	rm -f $(NAME) $(LIBFT_A)

re: fclean all

.PHONY: all clean fclean re
