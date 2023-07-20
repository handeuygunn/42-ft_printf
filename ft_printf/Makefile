# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: huygun <huygun@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/18 19:15:47 by huygun            #+#    #+#              #
#    Updated: 2023/07/19 18:00:18 by huygun           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



SRCS = ft_printf.c ft_printfd.c ft_printfhex.c ft_printfhexp.c

NAME = libftprintf.a
OBJS = ${SRCS:.c=.o}
CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) rcs $@ $(OBJS)


.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
