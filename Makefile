NAME = cub3d

FLAGS = gcc #-Wall -Wextra -Werror

MINILIBX = -Imlx -Iinc -lmlx -framework OpenGL -framework AppKit #-lmlx -lXext -lX11 -lm \
#-L ./minilibx_opengl_20191021 -l mlx -framework OpenGL -framework AppKit 

FUN = cub3d.c create_trgb.c paint.c ft_map.c movement.c raycasting.c #ft_keys.c

OBJ = cub3d.o create_trgb.o paint.o ft_map.o movement.o raycasting.o #ft_keys.o

FUNLIB = ./GNL/get_next_line.c ./libft/ft_putchar_fd.c ./libft/ft_atoi.c ./libft/ft_strncmp.c ./libft/ft_bi_array.c ./libft/ft_fill_bi_array.c \
./libft/ft_putnbr_fd.c ./libft/ft_strchr.c ./libft/ft_strdup.c ./libft/ft_strjoin.c ./libft/ft_substr.c ./libft/ft_strlen.c


OBJLIB = ./GNL/get_next_line.o ./libft/ft_putchar_fd.o ./libft/ft_atoi.o ./libft/ft_strncmp.o ./libft/ft_bi_array.o ./libft/ft_fill_bi_array.o \
./libft/ft_putnbr_fd.o ./libft/ft_strchr.o ./libft/ft_strdup.o ./libft/ft_strjoin.o ./libft/ft_substr.o ./libft/ft_strlen.o

all: $(NAME)

$(NAME): $(OBJ) $(OBJLIB) cub3d.h #./libft/libft.h ./GNL/get_next_line.h ./minilibx_opengl_20191021/mlx.h  ./minilibx_mms_20191025_beta/mlx.h
	@$(FLAGS) $(FUN) $(FUNLIB) $(MINILIBX) -o $(NAME)

clean:
	@rm -f $(OBJ) *.o ./libft/*.o ./GNL/*.o

fclean: 
	@rm -f $(NAME)

re: fclean all

norminette:
	@norminette $(FUN) cub3d.h