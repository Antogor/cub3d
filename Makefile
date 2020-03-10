NAME = cub3D

FLAGS = gcc #-Wall -Wextra -Werror

MINILIBX = -lmlx -lXext -lX11 -lm -lbsd #-lmlx -framework OpenGl -framework AppKit #-lmlx -lXext -lX11 -lm

FUN = cub3d.c ./Engine/create_trgb.c ./Engine/paint.c ./Engine/ft_map.c ./Engine/raycasting.c ./Engine/check_data.c ./Engine/check_map.c ./Engine/extract_color.c \
./Engine/ft_keys.c ./Engine/extract_textures.c ./Engine/movement.c ./Engine/choose_texture.c ./Engine/extract_txt_fc.c ./Engine/raycast_fc.c ./Engine/raycast_sprite.c \
./Engine/extract_sprite.c

OBJ = cub3d.o ./Engine/create_trgb.o ./Engine/paint.o ./Engine/ft_map.o ./Engine/raycasting.o ./Engine/check_data.o ./Engine/check_map.o ./Engine/extract_color.o \
./Engine/ft_keys.o ./Engine/extract_textures.o ./Engine/movement.o ./Engine/choose_texture.o ./Engine/extract_txt_fc.o ./Engine/raycast_fc.o ./Engine/raycast_sprite.o \
./Engine/extract_sprite.o

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
	@rm -f $(OBJ) *.o ./libft/*.o ./GNL/*.o ./Enine/*.o

fclean: 
	@rm -f $(NAME)

re: fclean all

norminette:
	@norminette $(FUN) cub3d.h
