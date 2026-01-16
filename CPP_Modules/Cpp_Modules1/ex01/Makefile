# **************************************************************************** #
#                                   SETTINGS                                   #
# **************************************************************************** #

NAME		= zombieHorde

CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98

SRC			= main.cpp Zombie.cpp zombieHorde.cpp
OBJ			= $(SRC:.cpp=.o)
HEADER		= Zombie.hpp

# **************************************************************************** #
#                                   RULES                                      #
# **************************************************************************** #

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)
	@echo "✅ $(NAME) compiled successfully!"

%.o: %.cpp $(HEADER)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)
	@echo "🧹 Object files cleaned."

fclean: clean
	@rm -f $(NAME)
	@echo "🧨 Executable removed."

re: fclean all

# ---------------------------------------------------------------------------- #
#                                  EXTRA RULES                                 #
# ---------------------------------------------------------------------------- #

run: all
	@$(MAKE) clean
	@echo "========================================="
	@echo "🚀 Running $(NAME)..."
	@echo "========================================="
	@./$(NAME)


# **************************************************************************** #
#                                   PHONY                                      #
# **************************************************************************** #

.PHONY: all clean fclean re run
