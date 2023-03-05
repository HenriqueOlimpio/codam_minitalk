CC=gcc
CFLAGS=-Wall -Wextra -Werror
SOURCES=server.c client.c utils.c
NAME=server client

all: $(NAME)

server: server.c utils.c
	$(CC) $(CFLAGS) $^ -o $@

client: client.c utils.c
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all

PHONY: all clean fclean
