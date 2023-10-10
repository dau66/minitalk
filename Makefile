CFLAGS = -Wall -Wextra -Werror
SRCS = client.c server.c
# OBJS = $(SRCS:.c=.o)
LIBFT = libft/libft.a

all: server client
# $(NAME): $(OBJS)
# 	$(MAKE) -C libft
# 	cp libft/libft.a $(NAME)
# 	ar rcs $@ $(OBJS)
# 	$(CC) -Wall -Wextra -Werror $(NAME) client.c -o client
# 	$(CC) -Wall -Wextra -Werror $(NAME) server.c -o server

# %.o: %.c
#  $(CC) $(CFLAGS) -c $< -o $@

server: server.c $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $^

client: client.c $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $^

$(LIBFT):
	make -C libft

clean: 
	$(RM) $(OBJS)
	$(MAKE) -C libft clean

fclean: clean
	$(RM) client
	$(RM) server
	$(MAKE) -C libft fclean

re: fclean all

.PHONY: all clean fclean re
