NAME = weapon
CC = c++
CPPFLAGS = -Werror -Wextra -Wall -std=c++98

CPP_FILES = main Weapon HumanA HumanB Weapon
HPP_FILES = Weapon HumanA HumanB
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