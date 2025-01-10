CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -std=gnu90 -g

SRC0 = 0-backtracking_array.c 0-main.c
OBJ0 = $(SRC0:.c=.o)
NAME0 = backtracking_array

LIBS = -l libgraphs.a -l libqueues.a

.PHONY: all clean oclean

all: $(OBJ0)
	$(CC) $(OBJ0) $(LIBS) -o $(NAME0)

clean:
	$(RM) *~ $(NAME0)

oclean:
	$(RM) $(OBJ0)


backtracking: $(OBJ0)
	$(CC) $(OBJ0) $(LIBS) -o $(NAME0)


