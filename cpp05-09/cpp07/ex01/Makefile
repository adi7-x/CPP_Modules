CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = iter

SRCS = main.cpp

all: $(NAME)

$(NAME): $(SRCS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(NAME)

clean:
	rm -f $(NAME)

fclean: clean

re: fclean all
