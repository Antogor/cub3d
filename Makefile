NAME = cub3D

FLAGS = gcc #-Wall -Wextra -Werror

MINILIBX = -lmlx -lXext -lX11 -lm -lbsd #-lmlx -framework OpenGl -framework AppKit #-lmlx -lXext -lX11 -lm -lbsd

FUN = cub3d.c ./Engine/create_trgb.c ./Engine/paint.c ./Engine/ft_map.c ./Engine/raycasting.c ./Engine/check_data.c ./Engine/check_map.c ./Engine/extract_color.c \
./Engine/ft_keys.c ./Engine/extract_textures.c ./Engine/movement.c ./Engine/choose_texture.c ./Engine/extract_txt_fc.c ./Engine/raycast_fc.c ./Engine/raycast_sprite.c \
./Engine/extract_sprite.c ./Engine/ft_error.c ./Engine/is_a_close_map.c ./Engine/ft_save.c ./Engine/ft_close.c

OBJ = cub3d.o ./Engine/create_trgb.o ./Engine/paint.o ./Engine/ft_map.o ./Engine/raycasting.o ./Engine/check_data.o ./Engine/check_map.o ./Engine/extract_color.o \
./Engine/ft_keys.o ./Engine/extract_textures.o ./Engine/movement.o ./Engine/choose_texture.o ./Engine/extract_txt_fc.o ./Engine/raycast_fc.o ./Engine/raycast_sprite.o \
./Engine/extract_sprite.o ./Engine/ft_error.o ./Engine/is_a_close_map.o ./Engine/ft_save.o ./Engine/ft_close.o

FUNLIB = ./srcs/GNL/get_next_line.c ./srcs/libft/ft_putchar_fd.c ./srcs/libft/ft_atoi.c ./srcs/libft/ft_strncmp.c ./srcs/libft/ft_bi_array.c ./srcs/libft/ft_fill_bi_array.c \
./srcs/libft/ft_putnbr_fd.c ./srcs/libft/ft_strchr.c ./srcs/libft/ft_strdup.c ./srcs/libft/ft_strjoin.c ./srcs/libft/ft_substr.c ./srcs/libft/ft_strlen.c ./srcs/libft/ft_strrchr.c \
./srcs/libft/ft_strnstr.c ./srcs/libft/ft_strtrim.c ./srcs/libft/ft_split.c ./srcs/libft/ft_isalpha.c ./srcs/libft/ft_memcpy.c ./srcs/libft/ft_bzero.c

OBJLIB = ./srcs/GNL/get_next_line.o ./srcs/libft/ft_putchar_fd.o ./srcs/libft/ft_atoi.o ./srcs/libft/ft_strncmp.o ./srcs/libft/ft_bi_array.o ./srcs/libft/ft_fill_bi_array.o \
./srcs/libft/ft_putnbr_fd.o ./srcs/libft/ft_strchr.o ./srcs/libft/ft_strdup.o ./srcs/libft/ft_strjoin.o ./srcs/libft/ft_substr.o ./srcs/libft/ft_strlen.o ./srcs/libft/ft_strrchr.o \
./srcs/libft/ft_strnstr.o ./srcs/libft/ft_strtrim.o ./srcs/libft/ft_split.o ./srcs/libft/ft_isalpha.o ./srcs/libft/ft_memcpy.o ./srcs/libft/ft_bzero.o

all: $(NAME)

$(NAME): $(OBJ) $(OBJLIB) cub3d.h ./srcs/key_linux.h ./srcs/key_macos.h
	@$(FLAGS) -g $(FUN) $(FUNLIB) $(MINILIBX) -o $(NAME)

clean:
	@rm -f $(OBJ) *.o ./srcs/libft/*.o ./srcs/GNL/*.o ./Enine/*.o

fclean: 
	@rm -f $(NAME)

re: clean fclean all

norminette:
	@norminette $(FUN) cub3d.h
