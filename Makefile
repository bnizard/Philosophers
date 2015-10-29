#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bnizard <bnizard@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/08/28 16:20:22 by bnizard           #+#    #+#              #
#    Updated: 2015/08/28 16:20:31 by bnizard          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME =			philo

CC =			gcc $(FLAGS) $(INCLUDES)

LIBFT =			-L/Volumes/Data/nfs/zfs-student-2/users/2013/bnizard/.brew/lib -lSDLmain -lSDL -Wl,-framework,Cocoa 

INCLUDES =		-I/Volumes/Data/nfs/zfs-student-2/users/2013/bnizard/.brew/include -D_GNU_SOURCE=1 -D_THREAD_SAFE 

 SRC =			main.c init.c print.c draw.c ft_putchar.c ft_putnbr.c

 OBJ =			$(SRC:.c=.o)

 FLAGS =		-Wall -Werror -Wextra

 all:			$(NAME)

$(NAME):		$(OBJ)
				echo "\033[32m[Make]\033[0m   " | tr -d '\n'
				echo "\033[36m[$(NAME)]\033[0m " | tr -d '\n'
				echo "Building $(NAME)... " | tr -d '\n'
				$(CC) -o $(NAME) $(OBJ) $(LIBFT)
				echo "\033[32m   -> \033[0m" | tr -d '\n'
				echo "\033[36m$(NAME) \033[0m\033[32mcreated\033[0m"
clean:
				@echo "\033[31m[clean] " | tr -d '\n'
				@echo "\033[36m[$(NAME)]\033[0m Remove ofiles"
				rm -f $(OBJ)

fclean:
				rm -f $(OBJ)
				rm -f $(NAME)
				@echo "\033[31m[fclean] \033[36m[$(NAME)]\033[0m" | tr -d '\n'
				@echo " Remove ofiles & $(NAME)"

cleansdl:
				rm -rf SDL1

re:				fclean all

.PHONY:			all clean re fclean
.SILENT:

%.o:			%.c
				$(CC) -c $< -o $@