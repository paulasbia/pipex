NAME = pipex

SRCS =  ./src/main.c ./src/error.c

OBJS = $(SRCS:.c=.o)

LIBFTA = ./libft/libft.a

FLAGS = -Wall -Wextra -Werror

%.o: %.c
	cc $(FLAGS) -c $< -o $@

$(LIBFTA):
	make -C libft

all: $(NAME)

$(NAME): $(LIBFTA) $(OBJS)
	cc $(FLAGS) $(OBJS) $(LIBFTA) -o $(NAME) 

install:
	python3 -m pip install --upgrade pip setuptools
	python3 -m pip install norminette
	sudo apt install valgrind -y

check:
	norminette $(SRCS)

test: all
	gcc -ggdb $(FLAGS) ft_printf.c $(NAME) -o result.out

run: all
	./pipex

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	MAKE -c libft fclean

re: fclean all

valgrind: clean fclean all
	rm -f $(OBJS) $(NAME)
	valgrind --leak-check=full ./result.out

.PHONY: clean fclean all re