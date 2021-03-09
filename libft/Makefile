NAME = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

SRCS = ft_memset.c \
	   ft_bzero.c \
	   ft_memcpy.c \
	   ft_memccpy.c \
	   ft_memmove.c \
	   ft_memchr.c \
	   ft_memcmp.c \
	   ft_strlen.c \
	   ft_strdup.c \
	   ft_strcpy.c \
	   ft_strncpy.c \
	   ft_strcat.c \
	   ft_strncat.c \
	   ft_strlcat.c \
	   ft_strchr.c \
	   ft_strrchr.c \
	   ft_strstr.c \
	   ft_strnstr.c \
	   ft_strcmp.c \
	   ft_strncmp.c \
	   ft_atoi.c \
	   ft_isalpha.c \
	   ft_isdigit.c \
	   ft_isalnum.c \
	   ft_isascii.c \
	   ft_isprint.c \
	   ft_toupper.c \
	   ft_tolower.c \
	   ft_memalloc.c \
	   ft_memdel.c \
	   ft_strnew.c \
	   ft_strdel.c \
	   ft_strclr.c \
	   ft_striter.c \
	   ft_striteri.c \
	   ft_strmap.c \
	   ft_strmapi.c \
	   ft_strequ.c \
	   ft_strnequ.c \
	   ft_strsub.c \
	   ft_strjoin.c \
	   ft_strtrim.c \
	   ft_strsplit.c \
	   ft_itoa.c \
	   ft_putchar.c \
	   ft_putstr.c \
	   ft_putendl.c \
	   ft_putnbr.c \
	   ft_putchar_fd.c \
	   ft_putstr_fd.c \
	   ft_putendl_fd.c \
	   ft_putnbr_fd.c \
	   ft_lstnew.c \
	   ft_lstdelone.c \
	   ft_lstdel.c \
	   ft_lstadd.c \
	   ft_lstiter.c \
	   ft_lstmap.c \
	   ft_isesc.c \
	   ft_isupper.c \
	   ft_islower.c \
	   ft_strndup.c \
	   ft_print_words_table.c \
	   ft_count_letter.c \
	   ft_count_str.c \
	   ft_count_str_sep.c \
	   ft_size_nb.c \
	   ft_count.c \
	   ft_strclen.c \
	   ft_strcdup.c \
	   ft_realloc.c \
	   ft_strcchri.c \
	   ft_strclean.c \
	   ft_strrev.c \
	   ft_straddc.c \
	   ft_convert_base.c \
	   ft_itoa_base.c \
	   ft_utoa_base.c \
	   ft_str_minimize.c \
	   ft_insertc.c \
	   ft_power.c \
	   ft_strjoin_free.c \
	   ft_llftoa_base.c \
	   ft_count_char_elem.c \
	   ft_tabdup_char.c \
	   ft_intdup.c

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(AR) rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all
