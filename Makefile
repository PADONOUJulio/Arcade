##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

LDFLAGS		=	-ldl -fno-gnu-unique

## arcade

NAME		=	arcade

SRC		=	Core.cpp

OBJ		=	$(SRC:.cpp=.o)

## plugin sfml

NAME_SFML	=	lib/arcade_sfml.so

SRC_SFML	=	lgame/SFML.cpp

OBJ_SFML	=	$(SRC_SFML:.cpp=.o)

LDFLAGS_SFML	=	-shared -fPIC -lsfml-graphics -lsfml-system -lsfml-window -lsfml-audio -fno-gnu-unique

## plugin sdl

NAME_SDL	=	lib/arcade_sdl2.so

SRC_SDL		=	lgame/SDL2.cpp

OBJ_SDL		=	$(SRC_SDL:.cpp=.o)

LDFLAGS_SDL	=	-shared -fPIC -lSDL2 -lSDL2_ttf -lSDL2_image -fno-gnu-unique

## plugin Ncurse

NAME_NCURSE	=	lib/arcade_ncurses.so

SRC_NCURSE	=	lgame/Ncurse.cpp

OBJ_NCURSE	=	$(SRC_NCURSE:.cpp=.o)

LDFLAGS_NCURSE	=	-shared -fPIC -lncurses -fno-gnu-unique

## pacman

NAME_PACMAN	=	lib/arcade_pacman.so

SRC_PACMAN	=	lgame/Pacman.cpp

OBJ_PACMAN	=	$(SRC_PACMAN:.cpp=.o)

LDFLAGS_PACMAN	=	-shared -fPIC

## snake

NAME_SNAKE	=	lib/arcade_nibbler.so

SRC_SNAKE	=	lgame/Snake.cpp

OBJ_SNAKE	=	$(SRC_SNAKE:.cpp=.o)

LDFLAGS_SNAKE	=	-shared -fPIC




all:			core games graphicals

core:			$(NAME)

games:			$(NAME_PACMAN)  $(NAME_SNAKE)

graphicals:		$(NAME_SFML) $(NAME_SDL) $(NAME_NCURSE)

$(NAME_SFML):	$(SRC_SFML:.cpp=.o)
			g++ -c -fpic $(SRC_SFML)
			g++ SFML.o -o $(NAME_SFML) $(LDFLAGS_SFML)
			rm -f SFML.o

$(NAME_SDL):	$(SRC_SDL:.cpp=.o)
			g++ -c -fpic $(SRC_SDL)
			g++ SDL2.o -o $(NAME_SDL) $(LDFLAGS_SDL)
			rm -f SDL2.o

$(NAME_NCURSE):	$(SRC_NCURSE:.cpp=.o)
			g++ -c -fpic $(SRC_NCURSE)
			g++ Ncurse.o -o $(NAME_NCURSE) $(LDFLAGS_NCURSE)
			rm -f Ncurse.o

$(NAME_PACMAN):		$(OBJ_PACMAN)
			g++ -c -fpic $(SRC_PACMAN)
			g++ Pacman.o -o $(NAME_PACMAN) $(LDFLAGS_PACMAN)
			rm -f Pacman.o

$(NAME_SNAKE):		$(OBJ_SNAKE)
			g++ -c -fpic $(SRC_SNAKE)
			g++ Snake.o -o $(NAME_SNAKE) $(LDFLAGS_SNAKE)
			rm -f Snake.o

$(NAME):		$(OBJ)
			g++ $(OBJ) -o $(NAME) $(LDFLAGS)

clean:
			rm -f $(OBJ_SFML) $(OBJ_SDL) $(OBJ_NCURSE) $(OBJ_PACMAN) $(OBJ_SNAKE) $(OBJ)

fclean:			clean
			rm -f $(NAME_SFML) $(NAME_SDL) $(NAME_NCURSE) $(NAME_PACMAN) $(NAME_SNAKE) $(NAME)

re:	fclean all

.PHONY:	clean fclean re all
