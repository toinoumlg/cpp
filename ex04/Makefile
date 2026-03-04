NAME = SED_TAKE_L
CC = c++
CPPFLAGS = -Werror -Wextra -Wall -std=c++98

CPP_FILES = main 
SOURCES = $(addsuffix .cpp, $(CPP_FILES))
OBJECTS = $(SOURCES:.cpp=.o)
HEADERS = $(addsuffix .hpp, $(HPP_FILES))

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CPPFLAGS) $(OBJECTS) -o $@

%.o: %.cpp
	$(CC) $(CPPFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re