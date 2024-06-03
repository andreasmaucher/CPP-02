# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amaucher <amaucher@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/23 14:22:27 by amaucher          #+#    #+#              #
#    Updated: 2024/06/03 17:40:47 by amaucher         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fixed
SOURCES = main.cpp Fixed.cpp
		
OBJS = $(SOURCES:.cpp=.o)

CXX = c++
RM = rm -f
CXXFLAGS = -g -Wall -Wextra -Werror -std=c++98

all: $(NAME)	

$(NAME): $(OBJS)
	$(CXX) $(CXXLAGS) $(OBJS) -o $(NAME)

#rule for building .o files from .cpp files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re