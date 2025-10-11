# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alermi <alermi@student.42kocaeli.com.tr>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/05 15:53:36 by alermi            #+#    #+#              #
#    Updated: 2025/09/05 17:15:44 by alermi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                               Makefile                                      #
# **************************************************************************** #

CXX     := c++
CXXFLAGS:= -Wall -Wextra -Werror -std=c++98

NAME    := phonebook

SRC     := main.cpp Contact.cpp PhoneBook.cpp
OBJ     := $(SRC:.cpp=.o)

DEPS    := Contact.hpp PhoneBook.hpp

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp $(DEPS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
