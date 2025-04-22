# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skuhlcke <skuhlcke@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/15 14:22:46 by skuhlcke          #+#    #+#              #
#    Updated: 2025/04/21 10:44:09 by skuhlcke         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CFILES = ft_strchr.c ft_strrchr.c ft_strnstr.c ft_strdup.c ft_strlen.c\
	ft_strlcpy.c ft_strlcat.c ft_strncmp.c ft_memcmp.c ft_memcpy.c\
	ft_memmove.c ft_memset.c ft_memchr.c ft_bzero.c ft_atoi.c\
	ft_calloc.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c\
	ft_isprint.c ft_toupper.c ft_tolower.c ft_substr.c ft_strjoin.c\
	ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c\
	ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

OFILES = $(CFILES:.c=.o)

BCFILES = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c\
	ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

BOFILES = $(BCFILES:.c=.o)

CC = cc
FLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

all: $(NAME)

$(NAME): $(OFILES)

bonus: $(NAME) $(BOFILES)

$(OFILES): $(CFILES)
	$(CC) $(FLAGS) -c $^
	$(AR) $(NAME) $(OFILES)

$(BOFILES): $(BCFILES)
	$(CC) $(FLAGS) -c $^
	$(AR) $(NAME) $(BOFILES)

clean:
	$(RM) $(OFILES) $(BOFILES)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus