NAME		=	libft.a
CC			=	cc
FLAGS		=	-Wall -Werror -Wextra
SRC_PART	=	get_next_line_utils.c get_next_line.c ft_strncmp.c ft_printf.c ft_printf_str.c \
				ft_printf_nbr.c ft_calloc.c ft_bzero.c
HDRS		=	libft.h
OBJ_SRC		=	$(SRC_PART:.c=.o)

all:			$(NAME)


$(NAME):		$(OBJ_SRC)
				ar -rcs $(NAME) $(OBJ_SRC)

%.o	: 			%.c $(HDRS)
				$(CC) $(FLAGS) -c $< -o $@

clean:
				rm -rf $(OBJ_SRC)

fclean:			clean
				rm -rf $(NAME)

re:				fclean $(NAME)

.PHONY: all clean fclean re bonus
