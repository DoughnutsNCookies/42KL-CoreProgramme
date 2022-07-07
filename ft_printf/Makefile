# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: schuah <schuah@student.42.kl.edu.my>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/07 10:52:13 by schuah            #+#    #+#              #
#    Updated: 2022/07/07 14:16:21 by schuah           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= ft_printf.c \
		  printstring.c
OBJS	= ${SRCS:.c=.o}
NAME	= libftprintf.a
ARRC	= ar rcs
CC		= gcc
RM		= rm -f
CFLAGS	= -Wall -Wextra -Werror

all		: $(NAME)

$(NAME)	: $(OBJS)
			make -C libft
			cp libft/libft.a ./$(NAME)
			$(ARRC) $(NAME) $(OBJS)

clean	:
			make clean -C libft
			$(RM) $(OBJS)

fclean	: clean
			make fclean -C libft
			$(RM) $(NAME)

re		: fclean $(NAME)
