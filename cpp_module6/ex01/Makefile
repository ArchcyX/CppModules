# ============================================================
#                       COLOR CODES
# ============================================================
GREEN        = \033[1;32m
YELLOW       = \033[1;33m
RED          = \033[1;31m
CYAN         = \033[1;36m
RESET        = \033[0m

# ============================================================
#                       PROJECT CONFIG
# ============================================================
NAME        = convert
CXX         = c++
CXXFLAGS    = -Wall -Wextra -Werror -g -std=c++98

# Varsayılan test argümanı (make run ARG="nan" şeklinde değiştirilebilir)
ARG         ?= 42

# ============================================================
#                       SOURCE & HEADER FILES
# ============================================================
HEADERS     = ScalarConverter.hpp

SRC         = main.cpp \
              ScalarConverter.cpp

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
	@echo "$(GREEN)>>> Running program with argument: '$(ARG)'...$(RESET)\n"
	@./$(NAME) $(ARG)

runv: all
	@echo "$(YELLOW)>>> Running program with valgrind, argument: '$(ARG)'...$(RESET)\n"
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
