CC = gcc
CFLAGS = -Wall -Wextra -g -Iinclude

TARGET = main
SRC = main.c src/arrayadt.c
OBJ = $(SRC:.c=.o)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)
run: $(TARGET)
	./$(TARGET)