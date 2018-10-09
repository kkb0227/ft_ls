# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kykim <kykim@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/25 14:16:54 by kykim             #+#    #+#              #
#    Updated: 2018/08/29 01:00:55 by kykim            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = convert_c_cc.c \
	   convert_i_d.c \
	   convert_o.c \
	   convert_o2.c \
	   convert_o3.c \
	   convert_p.c \
	   convert_s.c \
	   convert_s2.c \
	   convert_u.c \
	   convert_x.c \
	   convert_x2.c \
	   convert_x3.c \
	   convert_x4.c \
	   etc.c \
	   etc2.c \
	   etc3.c \
	   etc4.c \
	   parsing.c \
	   ft_printf.c \
	   specifier.c \
	   convert_percent.c \
	   convert_id.c \
	   convert_id2.c \
	   convert_id3.c \

SRCO = $(SRCS:.c=.o)

HEADER = ft_printf.h

FLAG = -Wall -Wextra -Werror

all: $(NAME)

$(NAME) :
	gcc -c $(FLAG) -I $(HEADER) $(SRCS)
	ar rcs $(NAME) $(SRCO)
	ranlib $(NAME)

clean :
	rm -f $(SRCO)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
