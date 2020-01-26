NAME = cub3D.out

FLAGS = gcc -Wall -Wextra -Werror

MINILIBX = -lmlx -lXet -lX11 #-L ./minilibx_opengl_20191021/ #-lmlx -framework OpenGL -framework AppKit

FUN = cub3d.c ./GNL/get_next_line.c ./GNL/get_next_line_utils.c

OBJ = cub3d.o ./GNL/get_next_line.o ./GNL/get_next_line_utils.o

all: $(NAME)

$(NAME): $(OBJ) cub3d.h #./minilibx_opengl_20191021/mlx.h
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