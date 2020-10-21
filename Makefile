##
## Makefile 
## Printf clôné
##


CPP =		g++

NAME =		Dino

CPPFLAGS =	-lsfml-graphics -lsfml-window -lsfml-system -IPlayer

SRC = 		$(shell find Player -name 'player.cpp')\
			main.cpp

OBJ = 		$(SRC:.cpp=.o)

all:		fclean $(NAME) clean 

$(NAME): 	$(OBJ)
		rm -f $(NAME)
		$(CPP) -o $@ $^ $(CPPFLAGS)

clean:
		rm -f $(OBJ)

fclean: clean		
		rm -f Dino a.out Player/a.out

re: fclean all

.PHONY: fclean clean re