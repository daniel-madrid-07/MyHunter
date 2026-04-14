##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile that build the project
##

NAME	=		my_hunter

CFLAGS	= 		-W -Wall -Wextra

SRC		=		./src/background.c \
	./src/bullets.c \
	./src/counter.c \
	./src/crosshair.c \
	./src/game.c \
	./src/game_utils.c \
	./src/game_spawn.c \
	./src/game_cleanup.c \
	./src/help.c \
	./src/init.c \
	./src/kirby.c \
	./src/my_hunter.c \
	./src/my_hunter_utils.c \
	./src/start_button.c \
	./src/text.c \
	./src/text_utils.c \
	./my_printf/src/my_0.c \
	./my_printf/src/my_c.c \
	./my_printf/src/my_d.c \
	./my_printf/src/my_e.c \
	./my_printf/src/my_ee.c \
	./my_printf/src/my_f.c \
	./my_printf/src/my_g.c \
	./my_printf/src/my_o.c \
	./my_printf/src/my_p.c \
	./my_printf/src/my_plus.c \
	./my_printf/src/my_printf_core.c \
	./my_printf/src/my_put_decimal.c \
	./my_printf/src/my_revstr.c \
	./my_printf/src/my_s.c \
	./my_printf/src/my_space.c \
	./my_printf/src/my_strlen.c \
	./my_printf/src/my_u.c \
	./my_printf/src/my_w.c \
	./my_printf/src/my_x.c \
	./my_printf/src/my_xx.c

OBJ		=		$(SRC:.c=.o)

CSFML	=		-lcsfml-graphics -lcsfml-system -lcsfml-audio \
	-lcsfml-window -lm

all:	$(OBJ)
		gcc $(OBJ) -o $(NAME) -I../include $(CFLAGS) $(CSFML)

clean:
		rm -f $(OBJ)

fclean:	clean
		rm -f $(NAME)

debug:	CFLAGS+= -g
debug:	all
