# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pde-souz <pde-souz@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/31 15:54:36 by pde-souz          #+#    #+#              #
#    Updated: 2023/07/31 16:09:56 by pde-souz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SRCS = src/main.c src/utils.c src/error.c
OBJS = ${SRCS:.c=.o}

FLAGS = -Wall -Wextra -Werror -g

.c.o: %.o : %.c
	@cc ${FLAGS} -c $< -o $@

all: ${NAME}

${NAME}: ${OBJS}
	@echo "\033[33m----Compiling lib----"
	@make re -C ./libft
	@cc $(FLAGS) ${OBJS} -Llibft -lft -o ${NAME}
	@echo "\033[32mPipex Compiled! ᕦ(\033[31m♥\033[32m_\033[31m♥\033[32m)ᕤ\n"

clean:
	@make clean -C ./libft
	@rm -f ${OBJS}

fclean: clean
	@make fclean -C ./libft
	@rm -f ${NAME}
	@echo "\n\033[31mDeleting EVERYTHING! ⌐(ಠ۾ಠ)¬\n"

re:			fclean all

re_bonus:	fclean 

.PHONY: all clean fclean re re_bonus bonus party