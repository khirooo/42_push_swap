# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kfergani <kfergani@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/10 15:40:02 by kfergani          #+#    #+#              #
#    Updated: 2022/07/21 06:52:57 by kfergani         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap
BONUS	=	checker
CC	=	gcc
CFLAGS	=	-Wall -Wextra -Werror
INCLUDE	=	includes
LIBFT	=	libftprintf.a
PRINTF_DIR	=	./ft_printf
SRCDIR	=	src
OBJDIR	=	obj
BONUSDIR = bonus
SOURCES	=	a_utils.c b_utils.c commun_utils.c array_utils.c push_swap_utils.c sort_utils.c push_swap.c
BONUS_SOURCES	=	a_utils.c b_utils.c checker.c commun_utils.c get_next_line_utils.c get_next_line.c push_swap_utils.c 
SRCS	=	$(addprefix $(SRCDIR)/, $(SOURCES))
OBJS	=	$(addprefix $(OBJDIR)/, $(SOURCES:.c=.o))
BNSSRC	= 	$(addprefix $(BONUSDIR)/, $(BONUS_SOURCES))
BNSOBJ	=	$(BNSSRC:.c=.o)

all	: $(NAME)

bonus	: $(BONUS) $(BNSOBJ)

$(BONUS)	: $(BNSOBJ) $(LIBFT)
	$(CC) -o $(BONUS) $(BNSOBJ) $(LIBFT)

$(BNSOBJ)	:	%.o:%.c
	$(CC) $(CFLAGS) -o $@ -c $<

$(NAME)	:	$(OBJS) $(LIBFT)
	$(CC) -o $(NAME) $(OBJS) $(LIBFT)

$(OBJDIR)/%.o : $(SRCDIR)/%.c 
	mkdir -p $(OBJDIR)
	$(CC) $(FLAGS) -o $@ -c $<

$(LIBFT) : $(PRINTF_DIR)
	make -C $(PRINTF_DIR)
	cp	$(PRINTF_DIR)/$(LIBFT) ./

clean:
	make clean -C $(PRINTF_DIR)
	rm -rf $(LIBFT)
	rm -rf $(OBJDIR)
	rm -rf $(BNSOBJ)

fclean:	clean
	make fclean -C $(PRINTF_DIR)
	rm -rf $(NAME)
	rm -rf $(BONUS)

re	: fclean all
