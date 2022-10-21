# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccottin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/03 12:16:24 by ccottin           #+#    #+#              #
#    Updated: 2022/10/21 03:37:52 by ccottin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= convert

SRCS	= main.cpp FindType.cpp Convert.cpp

CC	= c++

OBJS	= $(SRCS:.cpp=.o)

DEPS	= $(OBJS:.o=.d)

CFLAGS	= -Wall -Wextra -Werror -std=c++98 -g3 -MMD

all	:	$(NAME)

%.o	:	%.cpp
		$(CC) $(CFLAGS) -c $< -o $@

$(NAME)	:	$(OBJS)
			$(CC) $(CFLAGS) $(OBJS) -o $@

clean	:
		rm -rf $(DEPS)
		rm -rf $(OBJS)

fclean	:	clean
		rm -rf $(NAME)

re	:	fclean
		make

-include $(DEPS)

.PHONY	:	all fclean clean re
