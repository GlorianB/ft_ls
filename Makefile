# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lachille <lachille@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/26 17:11:30 by santa             #+#    #+#              #
#    Updated: 2020/03/06 13:49:25 by lachille         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rc
RM = rm -rf
	
LIBFT = libft
INCDIR = includes
OBJDIR = objects
SRCDIR = sources

SOURCES = 	main.c \
			ft_ls.c \
			parsing.c \
			opt.c \
			print_arg_files.c \
			print_no_join_free.c \
			fill_tab.c \
			fill_tab2.c \
			sort.c \
			singleton.c \
			utils.c \
			utils2.c \
			utils3.c \
			sort_utils.c \
			print_classic.c
			

INC = ft_ls.h

SRCS = $(addprefix $(SRCDIR)/, $(SOURCES))
OBJS = $(addprefix $(OBJDIR)/, $(SOURCES:.c=.o))


all : $(OBJDIR) $(NAME)

$(NAME) : $(INCDIR)/$(INC) $(OBJS) 
	make -C $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT)/libft.a -o $(NAME)

$(OBJDIR) :
	mkdir -p objects

$(OBJDIR)/%.o : $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -I $(INCDIR) -c $< -o $@

clean :
	$(RM) $(OBJS)
	make -C $(LIBFT) clean

fclean : clean
	$(RM) $(NAME)
	make -C $(LIBFT) fclean

re : fclean all

debug: $(INCDIR)/$(INC)
	make -C $(LIBFT)
	$(CC) $(CFLAGS) -g3 $(SRCS) $(LIBFT)/libft.a

debugS: $(INCDIR)/$(INC)
	make -C $(LIBFT)
	$(CC) $(CFLAGS) -g3 -fsanitize=address $(SRCS) $(LIBFT)/libft.a
