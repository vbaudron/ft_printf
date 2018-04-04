# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cruiz <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/20 10:24:43 by cruiz             #+#    #+#              #
#    Updated: 2017/09/27 14:32:31 by vbaudron         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf
LIB = libft.a
LIB_PRINTF = libftprintf.a
CC = gcc
FLAGS = -Wall -Wextra -Werror
GENERAL_PATH = ./

PATH_LIB = $(GENERAL_PATH)/libft/
PATH_FT_PRINTF = $(GENERAL_PATH)srcs/
PATH_HEADERS = $(GENERAL_PATH)includes/
HEADERS = libft.h ft_printf.h
SRC_LIB = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
		  ft_isdigit.c ft_isprint.c ft_itoa.c ft_lstadd.c ft_lstdel.c \
		  ft_lstdelone.c ft_lstiter.c ft_lstmap.c ft_lstnew.c ft_memalloc.c \
		  ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memdel.c \
		  ft_memmove.c ft_memset.c ft_putchar.c ft_putchar_fd.c ft_putendl.c \
		  ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c ft_putstr.c \
		  ft_putstr_fd.c ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c \
		  ft_strcpy.c ft_strdel.c ft_strdup.c ft_strequ.c ft_striter.c \
		  ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlen.c ft_strmap.c \
		  ft_strmapi.c ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strnequ.c \
		  ft_strnew.c ft_strnstr.c ft_strrchr.c ft_strsplit.c ft_strstr.c \
		  ft_strsub.c ft_strtrim.c ft_tolower.c ft_toupper.c ft_power.c \
		  ft_ito_oct.c ft_putwchar.c ft_putnwstr.c

SRC_FT_PRINTF = crea_struct.c ft_c.c crea_targ.c ft_d.c ft_format.c \
			ft_free_struct.c ft_ito_hexa.c ft_o.c ft_p.c ft_printf.c \
			ft_s.c ft_spec_len.c ft_u.c ft_unsigint_tooct.c ft_x.c \
			has_specif.c crea_t_specif.c ft_unsi_toa.c free_targs.c\
			ft_pourcent.c ft_putstr_i.c has_flags.c ft_search_str.c \
			ft_return.c ft_struct_has_prec.c ft_imax_toa.c ft_uimax_toa.c \
			ito_adress.c ft_s_maj.c oct_toa.c empty_specif.c no_specif_gab.c \
			make_d.c make_o.c make_p.c make_u.c make_x.c what_flags.c \
			free_wstr.c



OBJ_LIB = $(SRC_LIB:.c=.o)
OBJ_FT_PRINTF = $(SRC_FT_PRINTF:.c=.o)

$(NAME):
	$(CC) $(FLAGS) -c $(addprefix $(PATH_LIB), $(SRC_LIB)) $(addprefix $(PATH_FT_PRINTF), $(SRC_FT_PRINTF)) -I$(PATH_HEADERS)
	ar rc $(LIB_PRINTF) $(OBJ_LIB) $(OBJ_FT_PRINTF)
	ranlib $(LIB_PRINTF)

all: $(NAME)

clean:
	rm -rf $(OBJ_LIB) $(OBJ_FT_PRINTF)

fclean: clean
	rm -f $(LIB_PRINTF)

re: fclean all
