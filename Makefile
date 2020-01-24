NAME = cub3D

FLAGS = gcc -Wall -Wextra -Werror

FUN = cub3d.c ./GNL/get_next_line.c ./GNL/get_next_line_utils.c

OBJ = cub3d.o ./GNL/get_next_line.o ./GNL/get_next_line_utils.o

all: $(NAME)

$(NAME): $(OBJ) cub3d.h
	@$(FLAGS) $(FUN)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

clean:
	@rm -f $(OBJ) *.o

fclean: 
	@rm -f $(NAME)

re: fclean all

norminette:
	@norminette $(FUN) cub3d.h