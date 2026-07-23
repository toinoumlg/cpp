NAME = Converting

CXX = c++
CXXFLAGS = -Werror -Wextra -Wall -std=c++98

SOURCE_DIR = source/
OBJECTS_DIR = build/
INCLUDE_DIR = include/

CPP_FILES = main ScalarConverter FromType Finder Printer
HPP_FILES = ScalarConverter

SOURCES = $(addprefix $(SOURCE_DIR), $(addsuffix .cpp, $(CPP_FILES)))
OBJECTS = $(patsubst $(SOURCE_DIR)%.cpp,$(OBJECTS_DIR)%.o,$(SOURCES))
HEADERS = $(addprefix $(INCLUDE_DIR), $(addsuffix .hpp, $(HPP_FILES)))

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $@

$(OBJECTS_DIR)%.o: $(SOURCE_DIR)%.cpp $(HEADERS) | $(OBJECTS_DIR)
	$(CXX) $(CXXFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

$(OBJECTS_DIR):
	@mkdir -p $(OBJECTS_DIR)

clean:
	rm -rf $(OBJECTS_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re