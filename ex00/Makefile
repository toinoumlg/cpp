NAME = megaphone
CC = c++
CPPFLAGS = -Werror -Wextra -Wall -std=c++98

CPP_FILES = $(NAME)
SOURCES = $(addsuffix .cpp, $(CPP_FILES))
OBJECTS = $(SOURCES:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CPPFLAGS) $^ -o $@

%.o: %.cpp
	$(CC) $(CPPFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re