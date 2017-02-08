NAME    = JsonTest

SOURCES = ../src

SRC     = main.cpp \
	$(SOURCES)/Json.cpp \

OBJ     = $(SRC:.cpp=.o)

CXXFLAGS    = -std=c++11 -W -Wall -Werror

all: $(NAME)

$(NAME): $(OBJ)
	g++ $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
