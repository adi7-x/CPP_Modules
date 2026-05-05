NAME = bureaucrat

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCDIR = .
OBJDIR = obj

SOURCES = main.cpp Bureaucrat.cpp
OBJECTS = $(SOURCES:%.cpp=$(OBJDIR)/%.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(NAME)
	@echo "✅ $(NAME) compiled successfully!"

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJDIR)
	@echo "🧹 Object files cleaned"

fclean: clean
	@rm -f $(NAME)
	@echo "🧹 Executable cleaned"

re: fclean all

.PHONY: all clean fclean re