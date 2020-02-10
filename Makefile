NAME = cub3D

FLAGS = gcc -Wall -Wextra -Werror

MINILIBX = -L ./minilibx_opengl_20191021 -l mlx -framework OpenGL -framework AppKit #-Imlx -Iinc -Ilibft -Lmlx/ -lmlx -framework OpenGL -framework AppKit

FUN = test_print.c create_trgb.c paint.c #ft_map.c ft_keys.c

OBJ = test_print.o create_trgb.o paint.o #ft_map.o ft_keys.o

FUNGNL = ./GNL/get_next_line.c ./GNL/get_next_line_utils.c ./libft/ft_putnbr_fd.c

OBJGNL = ./GNL/get_next_line.o ./GNL/get_next_line_utils.o ./libft/ft_putnbr_fd.o

FUNLIB = ./libft/ft_putchar_fd.c ./libft/ft_atoi.c ./libft/ft_strncmp.c ./libft/ft_bi_array.c ./libft/ft_fill_bi_array.c

OBJLIB = ./libft/ft_putchar_fd.o ./libft/ft_atoi.o ./libft/ft_strncmp.o ./libft/ft_bi_array.o ./libft/ft_fill_bi_array.o

all: $(NAME)

$(NAME): $(OBJ) $(OBJGNL) $(OBJLIB) cub3d.h #./minilibx_opengl_20191021/mlx.h ./libft/libft.h ./minilibx_mms_20191025_beta/mlx.h
	@$(FLAGS) $(FUN) $(FUNGNL) $(FUNLIB) $(MINILIBX) -o $(NAME)
	@ar rc $(NAME) $(OBJ) $(OBJGNL) $(OBJLIB)
	@ranlib $(NAME)

clean:
	@rm -f $(OBJ) *.o

fclean: 
	@rm -f $(NAME)

re: fclean all

norminette:
	@norminette $(FUN) cub3d.h