NAME = pipex

SRCS =  ./src/main.c ./src/error.c ./src/utils.c

OBJS = $(SRCS:.c=.o)

LIBFTA = ./libft/libft.a

FLAGS = 

%.o: %.c
	cc $(FLAGS) -c $< -o $@

$(LIBFTA):
	make -C libft

$(NAME): $(LIBFTA) $(OBJS)
	cc $(FLAGS) $(OBJS) $(LIBFTA) -o $(NAME) 

all: $(NAME)

install:
	python3 -m pip install --upgrade pip setuptools
	python3 -m pip install norminette
	sudo apt install valgrind -y

check:
	norminette $(SRCS)

test: all
	gcc -ggdb $(FLAGS) main.c utils.c $(NAME) -o main.o

run: all
	./pipex

clean:
	rm -f $(OBJS)
	make -C libft clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean

re: fclean all

valgrind: clean fclean all
	rm -f $(OBJS) $(NAME)
	valgrind --leak-check=full ./result.out

.PHONY: clean fclean all re