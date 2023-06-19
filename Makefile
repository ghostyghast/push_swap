SRCS = moves.c parsing.c push_swap.c radix_sort.c simple_sorts.c utils.c

SRCS_B = push_swap_bonus.c do_instructions.c moves.c parsing.c utils.c

DIR = src/

BONUS = checker

SRC_PREF = $(addprefix $(DIR), $(SRCS))

SRCS_B_PREF = $(addprefix $(DIR), $(SRCS_B))

OBJ = $(SRC_PREF:.c=.o)

OBJ_B = $(SRCS_B_PREF:.c=.o)

NAME = push_swap

INCLUDES = -Iincludes -Ilibft -L./libft -lft

CC = gcc

CFLAGS = -Wall -Werror -Wextra

%.o: %.c 
	@$(CC) $(CFLAGS) -Iincludes -Ilibft -c $< -o $@

$(NAME) : $(OBJ)
	make -C ./libft
	@$(CC) $(CFLAGS) $(INCLUDES) -o $@ $(OBJ)

$(BONUS) : $(OBJ_B)
	@$(CC) $(CFLAGS) $(INCLUDES) -o $@ $(OBJ_B)

all : $(NAME)

bonus : $(BONUS)

clean :
	@make clean -C ./libft
	@rm -rf src/*.o

fclean : clean
	@make fclean -C ./libft
	@rm $(NAME) $(BONUS)

re : fclean all
	@make re -C ./libft

.PHONY: all bonus clean fclean re