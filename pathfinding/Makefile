CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -I.

SRC0 = 0-backtracking_array.c 0-main.c
OBJ0 = $(SRC0:.c=.o)
NAME0 = backtracking_array

SRC1 = 1-backtracking_graph.c 1-main.c
OBJ1 = $(SRC1:.c=.o)
NAME1 = backtracking_graph

SRC2 = 2-dijkstra_graph.c 2-main.c
OBJ2 = $(SRC2:.c=.o)
NAME2 = dijkstra_graph

LIBS = -L. -lgraphs -lqueues -lm

.PHONY: all clean oclean

all: $(OBJ0) $(OBJ1) $(OBJ2)
	$(CC) $(OBJ0) $(LIBS) -o $(NAME0)
	$(CC) $(OBJ1) $(LIBS) -o $(NAME1)
	$(CC) $(OBJ2) $(LIBS) -o $(NAME2)

clean:
	$(RM) *~ $(NAME0)
	$(RM) *~ $(NAME1)
	$(RM) *~ $(NAME2)

oclean:
	$(RM) $(OBJ0)
	$(RM) $(OBJ1)
	$(RM) $(OBJ2)


backtracking: $(OBJ0)
	$(CC) -o $(NAME0) $(CFLAGS) $(obj0) $(LIBS)

graph: $(OBJ1)
	$(CC) -o $(NAME1) $(CFLAGS) $(OBJ1) $(LIBS)

dijkstra: $(OBJ2)
	$(CC) -o $(NAME2) $(CFLAGS) $(OBJ2) $(LIBS)

