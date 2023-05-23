SRCS = $(wildcard *.c)

OBJ_PREFIXED = $(addprefix objs/, $(OBJ))

OBJ = $(SRCS:.o=.c)

INCLUDES =  -Ilibft -lft -L./libft

NAME = push_swap

CC = gcc

CFLAGS = -Wall -Werror -Wextra #-fsanitize=address

obj/%.o: %.c push_swap.h
	@mkdir -p obj
	@$(CC) $(CFLAGS) -c $@ -o $<

$(NAME) : $(OBJ_PREFIXED)
	@make -C ./libft
	@$(CC) $(CFLAGS) $(INCLUDES) $(OBJ_PREFIXED) -o $@

all : $(NAME)

clean :
	@rm *.o

fclean : clean
	@rm $(NAME)

re : fclean