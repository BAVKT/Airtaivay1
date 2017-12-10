# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/27 17:07:31 by vmercadi          #+#    #+#              #
#    Updated: 2017/12/10 17:48:20 by vmercadi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = RTv1
SRC = srcs/maintest2.c srcs/error.c
INCLUDES = -I includes -I libft -I lib/SDL2/Headers
CFLAGS = -Wall -Wextra -Werror $(INCLUDES)
MFLAGS = -lpthread -O3
SDL = lib/SDL2/SDL2
SRCO = $(SRC:%.c=%.o)
LIB = lib/libft/libft.a

.PHONY: all re cleans

all: $(NAME)

$(NAME):$(SRCO)
	@make -s -C lib/libft/
	@echo "\033[32;4mLIBFT\x1b[0m	\033[32;7mcompiled\x1b[0m"
	@gcc $(CFLAGS) $(SDL) $(LIB) -o $(NAME) $(SRC) $(MFLAGS)
	@echo "\033[32;4mRTV1\x1b[0m	\033[32;7mcompiled\x1b[0m"
	@echo "\033[32;3m-----------------------------------"
	@echo "Things went great ! For this time.."
	@echo "-----------------------------------\x1b[0m"

it: all
	@./RTv1

clean:
	@rm -rf $(SRCO)
	@make clean -s -C lib/libft/

fclean: clean
	@rm -rf $(NAME)

re: fclean all

ultra: all clean

reit: re clean
	@./RTv1