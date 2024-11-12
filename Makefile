NAME = push_swap

CC = gcc

RM = rm -f

SRC = push_swap.c push_utils.c push_stk.c push_stk2.c push_sort.c \
	push_free_n_error.c push_algo.c push_o_sp.c push_o_rr.c push_o_ro.c \
	push_utils2.c push_sort2.c\

CFLAGS = -Wall -Werror -Wextra

OPTION = -I ./

OBJS = $(SRC:.c=.o)

LIBFT_PATH = ./libft/

LIBFT = $(LIBFT_PATH)libft.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L$(LIBFT_PATH) -lft
		@echo "\033[92m--Push Swap Compiled--\033[0m"

$(LIBFT):
		@make -C $(LIBFT_PATH)

%.o: %.c
		@$(CC) $(CFLAGS) $(OPTION) -c $< -o $@

clean:
		@$(RM) $(OBJS)

fclean: clean 
		@make -C $(LIBFT_PATH) fclean
		@$(RM) $(NAME)
		@echo "\033[92m--Push Swap Cleaned--\033[0m"

re: fclean all

.PHONY: all clean fclean re