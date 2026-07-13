# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alermi <alermi@student.42kocaeli.com.tr>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/07/13 13:20:34 by alermi            #+#    #+#              #
#    Updated: 2026/07/13 13:20:35 by alermi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ============================================================
#                       COLOR CODES
# ============================================================
GREEN        = \033[1;32m
YELLOW       = \033[1;33m
RED          = \033[1;31m
CYAN         = \033[1;36m
RESET        = \033[0m

# ============================================================
#                        TEST VALUES
# ============================================================

TEST_CASES = "a" "*" "0" "42" "-42" "2147483647" "-2147483648" "2147483649" \
             "-2147483649" "0.0f" "4.2f" "-4.2f" "0.0" "4.2" "-4.2" \
             "nan" "nanf" "inf" "-inf" "+inf" "inff" "-inff" "+inff" \
             "hello" "12f" "12.af" "42.42.42" ""

# ============================================================
#                       PROJECT CONFIG
# ============================================================
NAME        = convert
CXX         = c++
CXXFLAGS    = -Wall -Wextra -Werror -g -std=c++98

ARG         ?= 42

# ============================================================
#                       SOURCE & HEADER FILES
# ============================================================
HEADERS     = ScalarConvertor.hpp

SRC         = main.cpp \
              ScalarConvertor.cpp

OBJS        = $(SRC:.cpp=.o)

# ============================================================
#                    DEFAULT TARGET (make)
# ============================================================
all: $(NAME)

# ============================================================
#                    BUILD EXECUTABLE
# ============================================================
$(NAME): $(OBJS)
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)✔ Derleme tamamlandı: $(NAME)$(RESET)"

# ============================================================
#                OBJECT FILE COMPILATION RULE
# ============================================================
%.o: %.cpp $(HEADERS)
	@echo "$(CYAN)Compiling: $<...$(RESET)"
	@$(CXX) $(CXXFLAGS) -c $< -o $@

# ============================================================
#                        CLEANING
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
	@echo "\n$(GREEN)====================================================$(RESET)"
	@echo "$(YELLOW)      SCALAR CONVERTER KAPSAMLI TEST BAŞLIYOR$(RESET)"
	@echo "$(GREEN)====================================================$(RESET)\n"
	@for val in $(TEST_CASES); do \
		echo "$(CYAN)----------------------------------------------------$(RESET)"; \
		echo "$(YELLOW)Test ediliyor: ./$(NAME) '$$val'$(RESET)"; \
		echo "$(CYAN)----------------------------------------------------$(RESET)"; \
		./$(NAME) "$$val"; \
		echo ""; \
	done
	@echo "$(GREEN)>>> Tüm testler tamamlandı!$(RESET)\n"

runv: all
	@echo "$(YELLOW)>>> Valgrind ile tekli test çalıştırılıyor...$(RESET)\n"
	@echo "Kullanım: make runv ARG=\"test_degeri\""
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME) $(ARG)
# ============================================================
#                        HELP COMMAND
# ============================================================
help:
	@echo ""
	@echo "$(CYAN)====================  MAKE HELP  ====================$(RESET)"
	@echo " $(GREEN)make$(RESET)         → Programı derle"
	@echo " $(YELLOW)make clean$(RESET)   → Objeleri sil"
	@echo " $(RED)make fclean$(RESET)  → Objeleri ve executable'ı sil"
	@echo " $(CYAN)make re$(RESET)      → Baştan derle"
	@echo " $(GREEN)make run$(RESET)     → Programı çalıştır (Varsayılan arg: 42)"
	@echo "              Örn: make run ARG=\"-inff\""
	@echo " $(YELLOW)make runv$(RESET)    → Valgrind ile çalıştır"
	@echo "$(CYAN)====================================================$(RESET)"
	@echo ""

.PHONY: all clean fclean re help run runv
