NAME		=	libft.a

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror

RM			=	rm -f

FT_CHAR		=	ft_char/ft_isalnum.c \
				ft_char/ft_isalpha.c \
				ft_char/ft_isascii.c \
				ft_char/ft_isdigit.c \
				ft_char/ft_isprint.c \

FT_CONV		=	ft_conv/ft_atoi.c \
				ft_conv/ft_itoa.c \
				ft_conv/ft_tolower.c \
				ft_conv/ft_toupper.c \

FT_GNL		=	ft_gnl/get_next_line.c \

FT_LST		=	ft_lst/ft_lstadd_back.c \
				ft_lst/ft_lstadd_front.c \
				ft_lst/ft_lstclear.c \
				ft_lst/ft_lstdelone.c \
				ft_lst/ft_lstiter.c \
				ft_lst/ft_lstlast.c \
				ft_lst/ft_lstmap.c \
				ft_lst/ft_lstnew.c \
				ft_lst/ft_lstsize.c \

FT_MEM		=	ft_mem/ft_bzero.c \
				ft_mem/ft_calloc.c \
				ft_mem/ft_memchr.c \
				ft_mem/ft_memcmp.c \
				ft_mem/ft_memcpy.c \
				ft_mem/ft_memmove.c \
				ft_mem/ft_memset.c \

FT_PRINTF	=	ft_printf/ft_printf.c \

FT_PUT		=	ft_put/ft_putchar_fd.c \
				ft_put/ft_putendl_fd.c \
				ft_put/ft_putnbr_base.c \
				ft_put/ft_putnbr_fd.c \
				ft_put/ft_putstr_fd.c \

FT_STR		=	ft_str/ft_split.c \
				ft_str/ft_strchr.c \
				ft_str/ft_strdup.c \
				ft_str/ft_striteri.c \
				ft_str/ft_strjoin.c \
				ft_str/ft_strlcat.c \
				ft_str/ft_strlcpy.c \
				ft_str/ft_strlen.c \
				ft_str/ft_strmapi.c \
				ft_str/ft_strncmp.c \
				ft_str/ft_strnstr.c \
				ft_str/ft_strrchr.c \
				ft_str/ft_strtrim.c \
				ft_str/ft_substr.c \

SRC 		=	$(FT_CHAR) \
				$(FT_CONV) \
				$(FT_GNL) \
				$(FT_LST) \
				$(FT_MEM) \
				$(FT_PRINTF) \
				$(FT_PUT) \
				$(FT_STR) \

OBJ			=	$(SRC:.c=.o)

all:			$(NAME)

$(NAME):		$(OBJ)
		ar -rc	$(NAME) $(OBJ)

clean:
				$(RM) $(OBJ)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)