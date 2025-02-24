# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpoirier <mpoirier@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/24 11:46:32 by mpoirier          #+#    #+#              #
#    Updated: 2025/02/24 15:01:38 by mpoirier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS =  main.c ft_isdigit.c ./handle_errors.c ./init_a_to_b.c ./init_b_to_a.c \
		./sort_stacks.c ./sort_three.c ./split.c ./stack_init.c ./stack_sorted.c \
		./commands/push.c ./commands/rev_rotate.c ./commands/rotate.c ./commands/swap.c \

OBJS = ${SRCS:.c=.o}

CC = cc 
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I ./

.c.o:
	$(CC) $(CFlAGS) $(INCLUDES) -c $< -o ${<:.c=.o}

all : $(NAME)

$(NAME):	$(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) -o $(NAME)

clean : 
	rm -rf $(OBJS)

fclean : clean
		rm -rf $(NAME)

re : fclean all