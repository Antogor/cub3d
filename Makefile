NAME = cub3D

INCLUDES = cub3d.h ./srcs/libft/libft.h ./Mlx/minilibx-linux/mlx.h

FLAGS = gcc -I -Wall -Wextra -Werror

FUN = cub3d.c ./Engine/create_trgb.c ./Engine/paint.c ./Engine/ft_map.c ./Engine/raycasting.c ./Engine/check_data.c  ./Engine/extract_color.c \
 ./Engine/extract_textures.c ./Engine/movement.c ./Engine/choose_texture.c  ./Engine/raycast_fc.c ./Engine/save_bitmap.c ./Engine/raycast_sprite.c \
./Engine/check_sprite.c ./Engine/extract_txt_fc.c ./Engine/ft_error.c  ./Engine/ft_close.c ./Engine/check_player.c ./Engine/ft_keys.c 

OBJ = $(FUN:.c=.o) 

LIBFT = ./srcs/libft/libft.a

PLATFORM := $(shell uname)

ifeq ($(PLATFORM), Linux)
	MLX =  ./Mlx/minilibx-linux/libmlx.a 
	MLX_CC = ./Mlx/minilibx-linux
	MINILIBX = -lmlx -lXext -lX11 -lm -lbsd
else
	MLX =  ./Mlx/minilibx_mac/libmlx.a 
	MLX_CC = ./Mlx/minilibx_mac
	MINILIBX = -lmlx -framework OpenGL -framework AppKit
endif

all: $(NAME)

$(LIBFT): 
	@$(MAKE) -C ./srcs/libft/

$(MLX):
	@$(MAKE) -C $(MLX_CC)

$(NAME): $(OBJ) $(LIBFT) $(MLX) $(INCLUDES) 
	@$(FLAGS) $(FUN) $(LIBFT) $(MLX) -Lsrcs/libft -lft -L$(MLX_CC) -lmlx $(MINILIBX) -o $(NAME)

clean:
	@rm -f $(OBJ) *.o ./srcs/libft/*.o ./srcs/GNL/*.o ./Enine/*.o

fclean: clean
	@rm -f $(NAME)
	@rm -f $(LIBFT)
	@rm -f $(MLX)

re: clean fclean all

norm:
	@~/.norminette/norminette.rb $(FUN) cub3d.h
