# Variables

NAME = push_swap

INCLUDE = includes

LIBFT = libs/libft

CC = cc

CFLAGS = -Wall -Wextra -Werror -I $(INCLUDE)

GREEN = \033[32m
RED = \033[31m
DEF_COLOR = \033[0m

# Sources

SRC_DIR = src/
SRC_FILES = push_swap.c push_swap_utils.c push_swap_utils2.c push_swap_utils3.c sort.c

SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))

OBJS = $(SRC:.c=.o)

# Fonctions

all: $(NAME)
	@echo "$(GREEN)Compilation successful !$(DEF_COLOR)"

$(NAME): $(OBJS)
	@$(MAKE) -C $(LIBFT) -s all || (echo "$(RED)Error in libft compilation!$(DEF_COLOR)" && exit 1)
	@$(CC) $(CFLAGS) $(OBJS) -L $(LIBFT) -lft -o $(NAME) || \
		(echo "$(RED)Error during linking!$(DEF_COLOR)" && exit 1)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@ || (echo "$(RED)Error compiling $<!$(DEF_COLOR)" && exit 1)

clean:
	@rm -f $(OBJS)
	@echo "$(GREEN)Clean successful !$(DEF_COLOR)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(GREEN)Full clean successful !$(DEF_COLOR)"

re: fclean all

.PHONY: all clean fclean re
