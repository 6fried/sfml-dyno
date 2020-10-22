##
## Makefile 
## Printf clôné
##


CPP =		g++

NAME =		Dino

CPPFLAGS =	-lsfml-graphics -lsfml-window -lsfml-system -IPlayer -IObstacles -IGame

SRC = 		$(shell find Player -name 'player.cpp')\
			$(shell find Obstacles -name 'obstacles.cpp')\
			$(shell find Game -name 'game.cpp')\
			main.cpp

OBJ = 		$(SRC:.cpp=.o)

all:		$(NAME) clean 

$(NAME): 	$(OBJ)
		rm -f $(NAME)
		$(CPP) -o $@ $^ $(CPPFLAGS)

clean:
		rm -f $(OBJ)

fclean: clean		
		rm -f Dino a.out Player/a.out

re: fclean all

.PHONY: fclean clean re