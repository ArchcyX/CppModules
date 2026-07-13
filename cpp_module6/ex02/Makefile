# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alermi <alermi@student.42kocaeli.com.tr>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/07/13 14:39:55 by alermi            #+#    #+#              #
#    Updated: 2026/07/13 15:37:36 by alermi           ###   ########.fr        #
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
NAME        = serializer
CXX         = c++
CXXFLAGS    = -Wall -Wextra -Werror -g -std=c++98

# ============================================================
#                        SOURCE & HEADER FILES
# ============================================================
HEADERS     = ClassA.hpp	\
			  ClassB.hpp	\
			  ClassC.hpp	\
			  Base.hpp

SRC         = main.cpp \
			  Base.cpp

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
# Tek bir değer test etmek istersen: make run ARG="Alp"
# Tüm testleri çalıştırmak istersen: make test
run: all
	@./$(NAME) $(ARG)

test: all
	@echo "$(GREEN)>>> Kapsamlı Serialization Testleri Başlıyor...$(RESET)\n"
	@for val in $(TEST_CASES); do \
		echo "$(CYAN)----------------------------------------------------$(RESET)"; \
		echo "$(YELLOW)Test ediliyor: ./$(NAME) '$$val'$(RESET)"; \
		./$(NAME) "$$val"; \
		echo ""; \
	done
	@echo "$(GREEN)>>> Tüm testler başarıyla tamamlandı!$(RESET)\n"

runv: all
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME) $(ARG)

help:
	@echo ""
	@echo "$(CYAN)====================  MAKE HELP  ====================$(RESET)"
	@echo " make          → Programı derle"
	@echo " make test     → Tüm senaryoları sırayla test et"
	@echo " make run      → Tekli çalıştır (Kullanım: make run ARG=\"Alp\")"
	@echo " make clean    → Objeleri sil"
	@echo " make fclean   → Executable ve objeleri sil"
	@echo " make re       → Baştan derle"
	@echo "$(CYAN)====================================================$(RESET)"
	@echo ""

.PHONY: all clean fclean re help run test runv
