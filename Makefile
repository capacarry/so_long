NAME = so_long
HEADER = so_long.h
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -g
OBJS = $(SRC:.c=.o)
SRC = so_long.c check_path.c check_and_handle.c free_everything.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c remove_break.c element_frames.c close_window.c helper.c helper_2.c
LIBFT = ./libft/libft.a
MLX = minilibx-linux/libmlx.a
MLX_FLAGS = -lm -lX11 -lXext

$(NAME):	$(OBJS)
			$(MAKE) -s -C libft
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT) $(MLX) $(MLX_FLAGS) -g

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re