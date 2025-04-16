# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpoirier <mpoirier@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/24 11:46:32 by mpoirier          #+#    #+#              #
#    Updated: 2025/04/15 14:32:25 by mpoirier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS = main.c ./handle_errors.c ./init_a_to_b.c ./init_b_to_a.c \
		./sort_stacks.c ./sort_three.c ./stack_init.c ./stack_sorted.c \
		./commands/push.c ./commands/rev_rotate.c ./commands/rotate.c ./commands/swap.c \
		./Libft/ft_isdigit.c ./Libft/ft_split.c ./Libft/ft_strlcpy.c ./Libft/ft_strlen.c \

OBJS = ${SRCS:.c=.o}

CC = cc
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address,leak,undefined
INCLUDES = -I ./

all : $(NAME)

$(NAME):	$(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) -o $(NAME)

.c.o:
	$(CC) $(CFlAGS) $(INCLUDES) -c $< -o ${<:.c=.o}
		
clean : 
	rm -rf $(OBJS)

fclean : clean
		rm -rf $(NAME)

re : fclean all

test : re 
		rm -rf $(OBJS)
		clear
