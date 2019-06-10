##
## EPITECH PROJECT, 2018
## EvalExpr
## File description:
## Makefile
##

SRC	=	src/main.c 	\
		src/manage_file.c 	\
		src/parsing_command.c 	\
		src/parsing_tag.c 	\
		src/verif_line.c 	\
		src/stock_info/stock_compartment.c 	\
		src/stock_info/stock_model.c 	\
		src/stock_info/stock_one_tag.c 	\
		src/stock_info/stock_reaction.c 	\
		src/stock_info/stock_sbml.c 	\
		src/stock_info/stock_specie.c 	\
		src/stock_info/stock_specieref.c 	\

SRCLIB	=	lib/my/my_strdup.c	\
		lib/my/my_strlen.c	\
		lib/my/my_strcmp.c 	\
		lib/my/my_putchar.c 	\
		lib/my/my_putstr.c 	\
		lib/my/my_strncmp.c 	\
		lib/my/search_str.c 	\

OBJ	=	$(SRC:.c=.o)

OBJLIB	=	$(SRCLIB:.c=.o)

NAME	=	SBMLparser

NAMELIB	=	libmy.a

SCFLAGS=	-fno-builtin -W -Wall -Wextra

LCFLAGS=	-Ll ./lib/$(NAMELIB)

CFLAGS	+=	-I./include

$(NAME):	lib $(OBJ)
		gcc -o $(NAME) $(OBJ) $(SCFLAGS) $(LCFLAGS)

.PHONY:	all clean fclean re

all:	$(NAME)

lib:	$(OBJLIB)
		ar rc lib/$(NAMELIB) $(OBJLIB)

clean:
		rm -f $(OBJLIB)
		rm -f $(OBJ)
		rm -f *.gcno
		rm -f *.gcda

fclean:	clean
		rm -f lib/$(NAMELIB)
		rm -f $(NAME)
		rm -f unit_tests

re:	fclean all
