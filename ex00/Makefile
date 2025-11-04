NAME = BraiiiiiiinnnzzzZ
CC = g++
CPPFLAGS = -Werror -Wextra -Wall -g3 -std=c++98

CPP_FILES = main Zombie newZombie randomChump
HPP_FILES = Zombie.class
SOURCES = $(addsuffix .cpp, $(CPP_FILES))
OBJECTS = $(SOURCES:.cpp=.o)
HEADERS = $(addsuffix .hpp, $(HPP_FILES))

all: $(NAME)

$(NAME): $(OBJECTS) $(HEADERS)
	$(CC) $(CPPFLAGS) $^ -o $@

%.o: %.cpp $(HEADERS)
	$(CC) $(CPPFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re