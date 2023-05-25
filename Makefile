SRCS = $(wildcard *.c)

OBJ_DIR = objs/

OBJ_PREFIXED = $(addprefix $(OBJ_DIR), $(OBJ))

OBJ = $(SRCS:.c=.o)

INCLUDES =  -Ilibft -lft -L./libft

NAME = push_swap

CC = gcc

CFLAGS = -Wall -Werror -Wextra #-fsanitize=address

$(OBJ_DIR)%.o: %.c push_swap.h
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJ_PREFIXED)
	@make -C ./libft
	@$(CC) $(CFLAGS) $(INCLUDES) $(OBJ_PREFIXED) -o $@

all : $(NAME)

clean :
	@make clean -C ./libft
	@rm -rf $(OBJ_DIR)

fclean : clean
	@make fclean -C ./libft
	@rm $(NAME)

re : fclean all
	@make re -C ./libft