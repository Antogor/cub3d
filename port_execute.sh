gcc cub3d.c raycasting.c movement.c create_trgb.c paint.c -lmlx -lXext -lX11 -lm -o TEST3D_port && ./TEST3D_port | tee result2.txt
#gcc test_print.c create_trgb.c paint.c -lmlx -lXext -lX11 -o TEST3D_port && ./TEST3D_port