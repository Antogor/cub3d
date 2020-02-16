gcc cub3d.c raycasting.c movement.c key_press.c key_release.c \
create_trgb.c paint.c ft_map.c ./libft/ft_strncmp.c ./GNL/get_next_line.c \
./libft/ft_substr.c ./libft/ft_strdup.c ./libft/ft_strjoin.c ./libft/ft_strchr.c \
./libft/ft_strlen.c -lmlx -lXext -lX11 -lm -o TEST3D_port \
&& ./TEST3D_port ./maps/map_test.cub | tee results_gnl.txt
#gcc test_print.c create_trgb.c paint.c -lmlx -lXext -lX11 -o TEST3D_port && ./TEST3D_port