NAME = cub3D.out

FLAGS = gcc -Wall -Wextra -Werror

MINILIBX =   -L ./minilibx_opengl_20191021 -l mlx -framework OpenGL -framework AppKit
MINILIBX2 = -L ./minilibx_mms_20191025_beta -l mlx -framework OpenGL -framework AppKit

FUN = cub3d.c ft_map.c ft_keys.c

OBJ = cub3d.o ft_map.o ft_keys.o

FUNGNL = ./GNL/get_next_line.c ./GNL/get_next_line_utils.c ./libft/ft_putnbr_fd.c 

OBJGNL = ./GNL/get_next_line.o ./GNL/get_next_line_utils.o ./libft/ft_putnbr_fd.o 

FUNLIB = ./libft/ft_putchar_fd.c ./libft/ft_atoi.c ./libft/ft_strncmp.c

OBJLIB = ./libft/ft_putchar_fd.o ./libft/ft_atoi.o ./libft/ft_strncmp.o

all: $(NAME)

$(NAME): $(OBJ) $(OBJGNL) $(OBJLIB) cub3d.h ./minilibx_opengl_20191021/mlx.h ./libft/libft.h ./minilibx_mms_20191025_beta/mlx.h
	@$(FLAGS) $(FUN) $(FUNGNL) $(FUNLIB) $(MINILIBX) $(MINILIBX2)
	@ar rc $(NAME) $(OBJ) $(OBJGNL) $(OBJLIB)
	@ranlib $(NAME)

clean:
	@rm -f $(OBJ) *.o

fclean: 
	@rm -f $(NAME)

re: fclean all

norminette:
	@norminette $(FUN) cub3d.h