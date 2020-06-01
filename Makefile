NAME = cub3D

FLAGS = gcc -I -Wall -Wextra -Werror

#MINILIBX = -lmlx -framework OpenGL -framework AppKit
MINILIBX = -lmlx -lXext -lX11 -lm -lbsd

FUN = cub3d.c ./Engine/create_trgb.c ./Engine/paint.c ./Engine/ft_map.c ./Engine/raycasting.c ./Engine/check_data.c ./Engine/check_map.c ./Engine/extract_color.c \
./Engine/ft_keys.c ./Engine/extract_textures.c ./Engine/movement.c ./Engine/choose_texture.c ./Engine/extract_txt_fc.c ./Engine/raycast_fc.c ./Engine/raycast_sprite.c \
./Engine/extract_sprite.c ./Engine/ft_error.c ./Engine/is_a_close_map.c ./Engine/ft_save.c ./Engine/ft_close.c

OBJ = $(FUN:.c=.o) 

LIBFT = ./srcs/libft/libft.a

MLX = ./Mlx/libmlx.dylib

all: $(NAME)

$(LIBFT): 
	@$(MAKE) -C ./srcs/libft/

$(MLX):
	@$(MAKE) -C ./Mlx/

$(NAME): $(OBJ) $(LIBFT) cub3d.h
	@$(FLAGS) $(FUN) $(LIBFT) $(MINILIBX) -o $(NAME)

clean:
	@rm -f $(OBJ) *.o ./srcs/libft/*.o ./srcs/GNL/*.o ./Enine/*.o

fclean: clean
	@rm -f $(NAME)
	@rm -f $(LIBFT)

re: clean fclean all

norminette:
	@norminette $(FUN) cub3d.h
