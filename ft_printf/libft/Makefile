# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: schuah <schuah@student.42.kl.edu.my>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/04 10:39:06 by schuah            #+#    #+#              #
#    Updated: 2022/07/07 17:38:14 by schuah           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= ft_putstr_fd.c \
		  ft_putchar_fd.c \
		  ft_strlen.c \
		  ft_itoa.c \
		  ft_putnbr_fd.c
OBJS	= $(SRCS:.c=.o)
NAME	= libft.a
ARRC	= ar rcs
CC		= gcc
RM		= rm -f
CFLAGS	= -Wall -Wextra -Werror -I.

all		: $(NAME)

$(NAME): $(OBJS)
			$(ARRC) $(NAME) $(OBJS)

clean	:
			$(RM) $(OBJS)

fclean	: clean
			$(RM) $(NAME)

re		: fclean $(NAME)
