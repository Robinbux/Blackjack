NAME = blackjack
SOURCE = checkFunctions.c getValueFunctions.c initializeFunctions.c utilities.c main.c
OBJECTS = checkFunctions.o getValueFunctions.o initializeFunctions.o utilities.o main.o

all: $(NAME)

$(NAME):
	gcc $(SOURCE) -o $(NAME)

clean:
	/bin/rm -f $(OBJECTS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all