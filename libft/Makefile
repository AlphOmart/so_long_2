NAME = libft.a
CC = cc
FLAGS = -Wall -Werror -Wextra
SRC_PART = get_next_line.c get_next_line_utils.c ft_strncmp.c ft_calloc.c ft_bzero.c
HDRS = libft.h
OBJ_SRC = $(SRC_PART:.c=.o)

all: $(NAME)


$(NAME):	$(OBJ_SRC) 
	ar -rcs $(NAME) $(OBJ_SRC)

%.o : %.c $(HDRS)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_SRC) $(OBJ_BONUS)

fclean: clean
	rm -rf $(NAME)
	
re: fclean $(NAME) 

bonus:			$(OBJ_SRC) $(OBJ_BONUS)
				ar -rcs $(NAME) $(OBJ_SRC) $(OBJ_BONUS)

.PHONY: all clean fclean re bonus
