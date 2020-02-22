NAME = fillit

SRCS =  sources/*.c

OBJ = *.o

CFLAGS = gcc -Wall -Wextra -Werror

all: $(NAME)

.PHONY: all clean fclean re

$(NAME): lib
	$(CFLAGS) -c $(SRCS) -Isources/ -Iincludes/
	$(CFLAGS) -o $(NAME) $(OBJ) -L libft -lft

lib:
	make -C libft

clean:
	-rm $(OBJ)
	make -C libft clean

fclean: clean
	rm -rf $(NAME)
	make -C libft fclean

re: fclean all
