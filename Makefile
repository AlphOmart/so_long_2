#---COMMON_VAR-----------------------------------
NAME		=	so_long
CC			=	cc
FLAGS		=	-Wall -Werror -Wextra -O
#---LIBFT_VAR-------------------------------------
LIBFT_PATH	=	libft/
LIBFT_SRC	=	libft.a
LIBFT		=	$(addprefix $(LIBFT_PATH), $(LIBFT_SRC))
#---MLX_VAR--------------------------------------
MLX_PATH	=	./minilibx-linux/
MLX_SRC		=	libmlx.a
MLX			=	$(addprefix $(MLX_PATH), $(MLX_SRC))
MLX_FLAGS	=	-lX11 -lXext
MLX_EX		=	$(MLX) $(MLX_FLAGS)
#---SO_LONG_VAR----------------------------------
SRC			=	so_long.c mapping.c utils.c checker.c res_lab.c set_unset_pic.c move.c render.c
OBJS_DIR	=	.OBJS/
OBJS		=	$(addprefix $(OBJS_DIR), $(SRC:.c=.o))
HEADER		=	so_long.h
#---RULES----------------------------------------

all:			lib mlx	$(NAME)

$(NAME):		$(OBJS) $(HEADER)
				@echo "\033[0;33m\nCOMPILING SO_LONG...\n"
				$(CC) $(FLAGS) $(OBJS) $(LIBFT) $(MLX_EX) -o $@
				@echo "\033[1;32m./so_long created\n"

lib:
				echo "\033[0;33m\nCOMPILING $(LIBFT_PATH)\n"
				@make -sC $(LIBFT_PATH)
				@echo "\033[1;32mLIBFT_lib created\n"

mlx:
				@echo "\033[0;33m\nCOMPILING $(MLX_PATH)...\n"
				@make -sC $(MLX_PATH)
				@echo "\033[1;32mMLX_lib created\n"

$(OBJS_DIR)%.o:	%.c | $(OBJS_DIR)
				$(CC) $(FLAGS) -c $< -o $@

$(OBJS_DIR):	 dir

dir:
				@mkdir -p $(OBJS_DIR)

clean:
				@echo "\033[0;31mDeleting Obj file in $(MLX_PATH)...\n"
				@make clean -sC $(MLX_PATH)
				@echo "\033[0;31mDeleting Obj file in $(LIBFT_PATH)...\n"
				@make clean -sC $(LIBFT_PATH)
				@echo "\033[1;32mDone\n"
				@echo "\033[0;31mDeleting So_long object...\n"
				@$(RM) -rf $(OBJS_DIR)
				@echo "\033[1;32mDone\n"

fclean:			clean
				@echo "\033[0;31mDeleting so_long executable..."
				@rm -rf $(NAME)
				@make fclean -C $(LIBFT_PATH)
				@echo "\033[1;32mDone\n"

re:				fclean all

.PHONY:			all clean fclean
