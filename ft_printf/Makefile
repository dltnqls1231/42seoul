# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sublee <sublee@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/11 16:39:54 by sublee            #+#    #+#              #
#    Updated: 2021/05/11 16:39:58 by sublee           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
FILES = ft_printf \
		ft_parsing \
		ft_format \
		ft_num_print \
		ft_txt_print \
		ft_utils

AR = ar rcus
RM = rm -fr

SRCS_DIR = ./
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))

OBJS_DIR = ./
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))

.c .o : $(SRCS)
	$(CC) $(CFLAGS) -c -o $@ $<

all : $(NAME) 

$(NAME) : $(OBJS)
	$(AR) $@ $^

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME) a.out

re : fclean all
