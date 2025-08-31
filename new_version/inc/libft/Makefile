# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rjesus-d <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/09 19:09:48 by rjesus-d          #+#    #+#              #
#    Updated: 2025/02/27 20:06:22 by rjesus-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = libft.a

SRCS = ft_isalpha.c \
       ft_isdigit.c \
       ft_isalnum.c \
       ft_isascii.c \
       ft_isprint.c \
       ft_strlen.c \
       ft_memset.c \
       ft_bzero.c \
       ft_memcpy.c \
       ft_memmove.c \
       ft_strlcpy.c \
       ft_strlcat.c \
       ft_toupper.c \
       ft_tolower.c \
       ft_strchr.c \
       ft_strrchr.c \
       ft_strncmp.c \
       ft_memchr.c \
       ft_memcmp.c \
       ft_strnstr.c \
       ft_atoi.c \
       ft_calloc.c \
       ft_strdup.c \
       ft_strtrim.c \
       ft_split.c \
       ft_itoa.c \
       ft_strmapi.c \
       ft_striteri.c \
       ft_putchar_fd.c \
       ft_putstr_fd.c \
       ft_putendl_fd.c \
       ft_putnbr_fd.c

OBJS = $(SRCS:.c=.o)

BONUS = ft_lstnew.c \
        ft_lstadd_front.c \
        ft_lstsize.c \
        ft_lstlast.c \
        ft_lstadd_back.c \
        ft_lstdelone.c \
        ft_lstclear.c \
        ft_lstiter.c \
        ft_lstmap.c

BONUS_OBJS = $(BONUS:.c=.o)

SRCS_FT_PRINTF = ft_printf/ft_printf.c \
		ft_printf/ft_print_char.c \
		ft_printf/ft_print_hex.c \
		ft_printf/ft_print_int.c \
		ft_printf/ft_print_pointer.c \
		ft_printf/ft_print_str.c \
		ft_printf/ft_print_unsigned_int.c

FT_PRINTF_OBJS = $(SRCS_FT_PRINTF:.c=.o)

SRCS_GNL = get_next_line/get_next_line.c \
		get_next_line/get_next_line_utils.c

GNL_OBJS = $(SRCS_GNL:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(BONUS_OBJS) $(FT_PRINTF_OBJS) $(GNL_OBJS)
	@ar rcs $(NAME) $(OBJS) $(BONUS_OBJS) $(FT_PRINTF_OBJS) $(GNL_OBJS)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJS) $(BONUS_OBJS) $(FT_PRINTF_OBJS) $(GNL_OBJS)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
