NAME = polymorph
CC = c++
CPPFLAGS = -Werror -Wextra -Wall -g3 -std=c++98

CPP_FILES = main Animal Cat Dog WrongAnimal WrongCat
HPP_FILES = Animal Cat Dog WrongAnimal WrongCat
SOURCES = $(addsuffix .cpp, $(CPP_FILES))
OBJECTS = $(SOURCES:.cpp=.o)
HEADERS = $(addsuffix .hpp, $(HPP_FILES))

all: $(NAME)

$(NAME): $(OBJECTS) $(HEADERS)
	$(CC) $(CPPFLAGS) $(OBJECTS) -o $@

%.o: %.cpp $(HEADERS)
	$(CC) $(CPPFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re