# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alermi <alermi@student.42kocaeli.com.tr>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/11 20:58:05 by alermi            #+#    #+#              #
#    Updated: 2026/01/11 20:58:06 by alermi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
# ============================================================
#                       PROJECT CONFIG
# ============================================================
NAME    = ScavTrap
CXX     = c++
CXXFLAGS  = -Wall -Wextra -Werror -g -std=c++98

# ============================================================
#                       SOURCE FILES
# ============================================================
SRC     = main.cpp \
          ClapTrap.cpp \
          ScavTrap.cpp

OBJS    = $(SRC:.cpp=.o)

# ============================================================
#                    DEFAULT TARGET (make)
# ============================================================
all: $(NAME)

# ============================================================
#                    BUILD EXECUTABLE
# ============================================================
$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

# ============================================================
#                 OBJECT FILE COMPILATION RULE
# ============================================================
%.o: %.cpp ClapTrap.hpp ScavTrap.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# ============================================================
#                        CLEANING
# ============================================================
clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

# ============================================================
#                       RUN COMMANDS
# ============================================================
run: $(NAME)
	@echo ">>> Running program..."
	@./$(NAME)

runv: $(NAME)
	@echo ">>> Running program with valgrind..."
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME)

# ============================================================
#                       HELP COMMAND
# ============================================================
help:
	@echo ""
	@echo "====================  MAKE HELP  ===================="
	@echo " make          → Programı derle"
	@echo " make clean    → .o dosyalarını sil"
	@echo " make fclean   → .o + executable'ı sil"
	@echo " make re       → Baştan derle"
	@echo " make run      → Programı çalıştır"
	@echo " make runv     → Programı valgrind ile çalıştır"
	@echo " make help     → Bu yardım mesajını göster"
	@echo "===================================================="
	@echo ""

# ============================================================
#                       PHONY TARGETS
# ============================================================
.PHONY: all clean fclean re help run runv
