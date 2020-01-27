NAME = cub3D.out

FLAGS = gcc -Wall -Wextra -Werror

MINILIBX =   -L ./minilibx_opengl_20191021 -l mlx -framework OpenGL -framework AppKit

FUN = cub3d.c ./GNL/get_next_line.c ./GNL/get_next_line_utils.c ./libft/ft_putnbr_fd.c ./libft/ft_putchar_fd.c

OBJ = cub3d.o ./GNL/get_next_line.o ./GNL/get_next_line_utils.o ./libft/ft_putnbr_fd.o ./libft/ft_putchar_fd.o

all: $(NAME)

$(NAME): $(OBJ) cub3d.h ./minilibx_opengl_20191021/mlx.h ./libft/libft.h
	@$(FLAGS) $(FUN) $(MINILIBX)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

clean:
	@rm -f $(OBJ) *.o

fclean: 
	@rm -f $(NAME)

re: fclean all

norminette:
	@norminette $(FUN) cub3d.h