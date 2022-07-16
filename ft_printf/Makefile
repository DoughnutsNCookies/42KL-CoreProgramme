# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: schuah <schuah@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/07 10:52:13 by schuah            #+#    #+#              #
#    Updated: 2022/07/15 14:03:53 by schuah           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libftprintf.a
LIBFT		=	libft.a
ARRC		=	ar rcs
CC			=	gcc
RM			=	rm -f
CFLAGS		=	-Wall -Wextra -Werror
SRCS_FILES	=	ft_printf \
				ft_flags \
		  		ft_print_pointer \
		  		ft_prints_with_flags \
		  		ft_printn_with_flags \
		  		ft_printun_with_flags \
		  		ft_printh_with_flags
SRCS		= 	$(addprefix $(SRCS_DIR), $(addsuffix .c, $(SRCS_FILES)))
OBJS		= 	$(addprefix $(OBJS_DIR), $(addsuffix .o, $(SRCS_FILES)))
BONUS_FILES	=	ft_printf_bonus \
				ft_flags_bonus \
		  		ft_print_pointer_bonus \
		  		ft_prints_with_flags_bonus \
		  		ft_printn_with_flags_bonus \
		  		ft_printun_with_flags_bonus \
		  		ft_printh_with_flags_bonus
BONUS		= 	$(addprefix $(BONUS_DIR), $(addsuffix .c, $(BONUS_FILES)))
BOBJS		= 	$(addprefix $(OBJS_DIR), $(addsuffix .o, $(BONUS_FILES)))
SRCS_DIR	=	srcs/
LIBFT_DIR	=	libft
OBJS_DIR	=	objs/
BONUS_DIR	=	bonus/

all:			$(NAME)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
				$(CC) $(CFLAGS) $(HEADER) -c $< -o $@

$(OBJS_DIR)%.o: $(BONUS_DIR)%.c
				$(CC) $(CFLAGS) $(HEADER) -c $< -o $@

$(NAME):		mkdir_objs create_libft $(OBJS)
				$(ARRC) $(NAME) $(OBJS)

bonus:			mkdir_objs create_libft $(BOBJS)
				$(ARRC) $(NAME) $(BOBJS)

create_libft:
				make -C $(LIBFT_DIR)
				cp $(LIBFT_DIR)/$(LIBFT) .
				mv $(LIBFT) $(NAME)

mkdir_objs:
				mkdir -p $(OBJS_DIR)

clean:
				rm -rf $(OBJS_DIR)
				make fclean -C $(LIBFT_DIR)

fclean:			clean
				rm -rf $(NAME)
				rm -rf $(LIBFT)

re:				fclean all
