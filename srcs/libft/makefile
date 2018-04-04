# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vbaudron <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/08 18:41:39 by vbaudron          #+#    #+#              #
#    Updated: 2016/12/02 16:40:02 by vbaudron         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_lstadd.c ft_memcmp.c ft_putnbr.c ft_strdel.c ft_strmapi.c \
   	  ft_strstr.c ft_atoi.c ft_lstdel.c ft_memcpy.c  ft_putnbr_fd.c \
	  ft_strdup.c ft_strncat.c ft_strsub.c ft_bzero.c ft_lstdelone.c \
	  ft_memdel.c ft_putstr.c ft_strequ.c ft_strncmp.c ft_strtrim.c \
	  ft_isalnum.c ft_lstiter.c ft_memmove.c ft_putstr_fd.c ft_striter.c  \
	  ft_strncpy.c ft_tolower.c ft_isalpha.c ft_lstmap.c ft_memset.c \
	  ft_strcat.c ft_striteri.c ft_strnequ.c ft_toupper.c ft_isascii.c \
   	  ft_lstnew.c ft_putchar.c ft_strchr.c ft_strjoin.c ft_strnew.c \
	  ft_isdigit.c ft_memalloc.c ft_putchar_fd.c ft_strclr.c ft_strlcat.c \
  	  ft_strnstr.c ft_isprint.c ft_memccpy.c ft_putendl.c ft_strcmp.c \
	  ft_strlen.c  ft_strrchr.c ft_itoa.c ft_memchr.c ft_putendl_fd.c \
	  ft_strcpy.c ft_strmap.c ft_strsplit.c ft_ito_oct.c ft_power.c ft_ito_oct.c \
	  ft_putwchar.c ft_putnwstr.c

all: $(NAME)

$(NAME) :
	gcc -c -Wall -Wextra -Werror $(SRC)
	ar rc $(NAME) ft_lstadd.o ft_memcmp.o ft_putnbr.o ft_strdel.o ft_strmapi.o \
   	  ft_strstr.o ft_atoi.o ft_lstdel.o ft_memcpy.o  ft_putnbr_fd.o \
	  ft_strdup.o ft_strncat.o ft_strsub.o ft_bzero.o ft_lstdelone.o \
	  ft_memdel.o ft_putstr.o ft_strequ.o ft_strncmp.o ft_strtrim.o \
	  ft_isalnum.o ft_lstiter.o ft_memmove.o ft_putstr_fd.o ft_striter.o  \
	  ft_strncpy.o ft_tolower.o ft_isalpha.o ft_lstmap.o ft_memset.o \
	  ft_strcat.o ft_striteri.o ft_strnequ.o ft_toupper.o ft_isascii.o \
   	  ft_lstnew.o ft_putchar.o ft_strchr.o ft_strjoin.o ft_strnew.o \
	  ft_isdigit.o ft_memalloc.o ft_putchar_fd.o ft_strclr.o ft_strlcat.o \
  	  ft_strnstr.o ft_isprint.o ft_memccpy.o ft_putendl.o ft_strcmp.o \
	  ft_strlen.o  ft_strrchr.o ft_itoa.o ft_memchr.o ft_putendl_fd.o \
	  ft_strcpy.o ft_strmap.o ft_strsplit.o ft_ito_oct.o ft_power.o ft_ito_oct.o \
	  ft_putwchar.o ft_putnwstr.o
	ranlib $(NAME)

clean :
	rm -rf ft_lstadd.o ft_memcmp.o ft_putnbr.o ft_strdel.o ft_strmapi.o \
   	  ft_strstr.o ft_atoi.o ft_lstdel.o ft_memcpy.o  ft_putnbr_fd.o \
	  ft_strdup.o ft_strncat.o ft_strsub.o ft_bzero.o ft_lstdelone.o \
	  ft_memdel.o ft_putstr.o ft_strequ.o ft_strncmp.o ft_strtrim.o \
	  ft_isalnum.o ft_lstiter.o ft_memmove.o ft_putstr_fd.o ft_striter.o  \
	  ft_strncpy.o ft_tolower.o ft_isalpha.o ft_lstmap.o ft_memset.o \
	  ft_strcat.o ft_striteri.o ft_strnequ.o ft_toupper.o ft_isascii.o \
   	  ft_lstnew.o ft_putchar.o ft_strchr.o ft_strjoin.o ft_strnew.o \
	  ft_isdigit.o ft_memalloc.o ft_putchar_fd.o ft_strclr.o ft_strlcat.o \
  	  ft_strnstr.o ft_isprint.o ft_memccpy.o ft_putendl.o ft_strcmp.o \
	  ft_strlen.o  ft_strrchr.o ft_itoa.o ft_memchr.o ft_putendl_fd.o \
	  ft_strcpy.o ft_strmap.o ft_strsplit.o ft_ito_oct.o ft_power.o ft_ito_oct.o \
	  ft_putwchar.o ft_punwstr.o

fclean : clean
	rm -rf $(NAME)

re : fclean all
