# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpoirier <mpoirier@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/07 08:53:53 by mpoirier          #+#    #+#              #
#    Updated: 2025/04/25 15:54:41 by mpoirier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJS_DIR = ./objs
SRCS_DIR = ./libft

NAME_LIBFT = libft.a
NAME_PRINTF = libprintf.a
NAME = compile

LIB_SRCS = $(SRCS_DIR)/ft_alloc.c \
	$(SRCS_DIR)/ft_error.c \
	$(SRCS_DIR)/ft_is_str2.c \
	$(SRCS_DIR)/ft_is_str.c \
	$(SRCS_DIR)/ft_str_to.c \
	$(SRCS_DIR)/ft_mem.c \
	$(SRCS_DIR)/ft_nbr_to_str2.c \
	$(SRCS_DIR)/ft_nbr_to_str.c \
	$(SRCS_DIR)/ft_len.c \
	$(SRCS_DIR)/ft_put_fd.c \
	$(SRCS_DIR)/ft_split.c \
	$(SRCS_DIR)/ft_str_duplicate.c\
	$(SRCS_DIR)/ft_str_to_nbr.c \
	$(SRCS_DIR)/ft_str_manipulate.c \
	$(SRCS_DIR)/ft_str_manipulate2.c \
	$(SRCS_DIR)/ft_str_manipulate3.c
       
B_SRCS = $(SRCS_DIR)/ft_lst_bonus.c \
	$(SRCS_DIR)/ft_lst_bonus2.c

PRINT_SRCS = $(SRCS_DIR)/ft_printf.c \
	$(SRCS_DIR)/ft_printf_utils.c \
	$(SRCS_DIR)/ft_printf_utils2.c 

L_OBJS = ${LIB_SRCS:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o}
P_OBJS = ${PRINT_SRCS:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o}
OBJS = $(L_OBJS) $(P_OBJS) 
BOBJS = ${B_SRCS:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o}

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS = rc
INCLUDES = -I$(SRCS_DIR)

all: $(NAME)

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c | $(OBJS_DIR)
	@echo "Compilation de $<"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJS_DIR) $(NAME_LIBFT) $(NAME_PRINTF)

$(NAME_LIBFT): $(OBJS_DIR) $(L_OBJS)
	@echo "Compilation des fichiers: $(L_OBJS)"
	@$(AR) $(ARFLAGS) $(NAME_LIBFT) $(L_OBJS)
	@echo "Compilation libft done."

$(NAME_PRINTF): $(OBJS_DIR) $(P_OBJS)
	@$(AR) $(ARFLAGS) $(NAME_PRINTF) $(P_OBJS)
	@echo "Compilation printf done."

bonus:	$(OBJS_DIR) $(L_OBJS) $(BOBJS)
	$(AR) $(ARFLAGS) $(NAME_LIBFT) $(L_OBJS) $(BOBJS)
	@echo "Compilation bonus_libft done."

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -rf $(NAME_LIBFT) $(NAME_PRINTF)

re: fclean all