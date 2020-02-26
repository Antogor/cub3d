NAME = cub3D

FLAGS = gcc #-Wall -Wextra -Werror

MINILIBX = -lmlx -framework OpenGl -framework AppKit #-Imlx -Iinc -lmlx -framework OpenGL -framework AppKit #-lmlx -lXext -lX11 -lm \
#-L ./minilibx_opengl_20191021 -l mlx -framework OpenGL -framework AppKit

FUN = cub3d.c create_trgb.c paint.c ft_map.c raycasting.c check_data.c check_map.c extract_color.c ft_keys.c extract_textures.c movement.c \
choose_texture.c

OBJ = cub3d.o create_trgb.o paint.o ft_map.o raycasting.o check_data.o check_map.o extract_color.o ft_keys.o extract_textures.o movement.o \
choose_texture.o

FUNLIB = ./GNL/get_next_line.c ./libft/ft_putchar_fd.c ./libft/ft_atoi.c ./libft/ft_strncmp.c ./libft/ft_bi_array.c ./libft/ft_fill_bi_array.c \
./libft/ft_putnbr_fd.c ./libft/ft_strchr.c ./libft/ft_strdup.c ./libft/ft_strjoin.c ./libft/ft_substr.c ./libft/ft_strlen.c ./libft/ft_strrchr.c \
./libft/ft_strnstr.c ./libft/ft_strtrim.c ./libft/ft_split.c

OBJLIB = ./GNL/get_next_line.o ./libft/ft_putchar_fd.o ./libft/ft_atoi.o ./libft/ft_strncmp.o ./libft/ft_bi_array.o ./libft/ft_fill_bi_array.o \
./libft/ft_putnbr_fd.o ./libft/ft_strchr.o ./libft/ft_strdup.o ./libft/ft_strjoin.o ./libft/ft_substr.o ./libft/ft_strlen.o ./libft/ft_strrchr.o \
./libft/ft_strnstr.o ./libft/ft_strtrim.o ./libft/ft_split.o

all: $(NAME)

$(NAME): $(OBJ) $(OBJLIB) cub3d.h
	@$(FLAGS) -g $(FUN) $(FUNLIB) $(MINILIBX) -o $(NAME)

clean:
	@rm -f $(OBJ) *.o ./libft/*.o ./GNL/*.o

fclean: 
	@rm -f $(NAME)

re: fclean all

norminette:
	@norminette $(FUN) cub3d.h
