# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alermi <alermi@student.42kocaeli.com.tr>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/07/14 15:18:33 by alermi            #+#    #+#              #
#    Updated: 2026/07/14 15:18:33 by alermi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ============================================================
#                        COLOR CODES
# ============================================================
GREEN        = \033[1;32m
YELLOW       = \033[1;33m
RED          = \033[1;31m
CYAN         = \033[1;36m
RESET        = \033[0m

# ============================================================
#                        PROJECT CONFIG
# ============================================================
NAME        = Array
CXX         = c++
CXXFLAGS    = -Wall -Wextra -Werror -g -std=c++98

# ============================================================
#                        SOURCE & HEADER FILES
# ============================================================
HEADERS     = Array.tpp


SRC         = main.cpp

OBJS        = $(SRC:.cpp=.o)

# ============================================================
#                         DEFAULT TARGET
# ============================================================
all: $(NAME)

$(NAME): $(OBJS)
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)✔ Derleme tamamlandı: $(NAME)$(RESET)"

%.o: %.cpp $(HEADERS)
	@echo "$(CYAN)Compiling: $<...$(RESET)"
	@$(CXX) $(CXXFLAGS) -c $< -o $@

# ============================================================
#                            CLEANING
# ============================================================
clean:
	@rm -f $(OBJS)
	@echo "$(YELLOW)󰃢 Objeler temizlendi.$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)󰃢 Executable ve objeler silindi.$(RESET)"

re: fclean all

# ============================================================
#                        RUN COMMANDS
# ============================================================
run: all
	@./$(NAME) $(ARG)

runv: all
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME) $(ARG)

help:
	@echo ""
	@echo "$(CYAN)====================  MAKE HELP  ====================$(RESET)"
	@echo " make          → Programı derle"
	@echo " make run      → Tekli çalıştır (Kullanım: make run ARG=\"Alp\")"
	@echo " make clean    → Objeleri sil"
	@echo " make fclean   → Executable ve objeleri sil"
	@echo " make re       → Baştan derle"
	@echo "$(CYAN)====================================================$(RESET)"
	@echo ""

.PHONY: all clean fclean re help run runv

