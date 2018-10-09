# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kykim <kykim@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/28 21:25:08 by kykim             #+#    #+#              #
#    Updated: 2018/08/29 12:45:32 by kykim            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

CFILES = *.c

OFILES = $(CFILES:.c=.o)

PRINTF = ft_printf -lftprintf

CLFAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
		make -C $(PRINTF)
		gcc $(CFLAGS) -c $(CFILES) -I.
		gcc $(OFILES) -L $(PRINTF) -o $(NAME)

clean:
		make -C ft_printf/ clean
		rm -f $(OFILES)

fclean: clean
		rm -f $(NAME)
		make -C ft_printf/ fclean

re: fclean all

.PHONY: re all fclean clean
