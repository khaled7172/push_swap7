
NAME = push_swap

SRCS = parsing/parse_flags.c \
       parsing/Error.c \
       parsing/ft_strcmp.c \
       parsing/parse_numbers_main.c \
       parsing/parse_numbers.c \
       parsing/parsing_utils.c \
       parsing/validation.c \
       stack_utils/rank.c \
       stack_utils/util.c \
       stack_utils/disorder.c \
       simple/sort_simple.c \
       operations/operations.c \
       operations/reverse_operations.c \
       operations/stack_helpers.c \
       medium/medium_utils.c \
       medium/sort_medium.c \
       complex/sort_complex.c \
       bonus/checker.c \
       bonus/helpers.c \
       bonus/checker_main.c \
       bench/benchmark.c \
       adaptive.c \
       push_swap.c
OBJS = $(SRCS:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
INCLUDES = -I . -I $(LIBFT_DIR)
RM = rm -rf

all: $(NAME)


$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	make bonus -C $(LIBFT_DIR)

bonus: $(OBJ) $(BNS_OBJ)
	$(AR) $(NAME) $(OBJ) $(BNS_OBJ)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	make clean -C $(LIBFT_DIR)
	$(RM) $(OBJS)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re