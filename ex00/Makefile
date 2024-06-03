# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amaucher <amaucher@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/23 14:22:27 by amaucher          #+#    #+#              #
#    Updated: 2024/04/25 16:34:11 by amaucher         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fixed
SOURCES = main.cpp Fixed.cpp
		
OBJS = $(SOURCES:.cpp=.o)

CC = c++ -g
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)	

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re