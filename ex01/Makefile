NAME = Bureaucrat
SRC = src/main.cpp \
		src/Bureaucrat.cpp \
		src/Form.cpp

OBJ := $(SRC:%.cpp=%.o)

CXX = c++
CXXFLAGS= -Wall -Wextra -Werror -std=c++17

define loading_bar
	@printf "Compiling: ["
	@for i in {1..20}; do \
		printf " "; \
	done; \
	printf "]"; \
	printf "\rCompiling: ["; \
	for i in {1..20}; do \
		printf "="; \
		sleep 0.05; \
	done; \
	printf "]\n";
endef

all: $(NAME)

# $(NAME):
# 	$(loading_bar)
# 	@$(CXX) $(CXXFLAGS) $(SRC) -o $(NAME) > /dev/null 2>&1 && echo "\033[32mCompilation successful!\033[0m"

$(NAME): $(OBJ)
	$(loading_bar)
	@$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME) > /dev/null 2>&1 && echo "\033[32mCompilation successful!\033[0m"

%.o: %.cpp
	@$(CXX) $(CXXFLAGS) -o $@ -c $<

# fclean:
# 	@rm -f $(NAME) > /dev/null 2>&1 && echo "\033[31mProgram cleared successfully!\033[0m"

fclean:
	@rm -f $(NAME) $(OBJ) > /dev/null 2>&1 && echo "\033[31mProgram cleared successfully!\033[0m"

re: fclean all

.PHONY: all fclean re
