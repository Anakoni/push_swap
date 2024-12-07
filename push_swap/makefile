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
SRC_FILES = push_swap.c

SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))

OBJS = $(SRC:.c=.o)

# Fonctions

all: $(NAME)
	@echo -e "$(GREEN)Compilation successful !$(DEF_COLOR)"

$(NAME): $(OBJS)
	@$(MAKE) -C $(LIBFT) -s all || (echo -e "$(RED)Error in libft compilation!$(DEF_COLOR)" && exit 1)
	@$(CC) $(CFLAGS) $(OBJS) -L $(LIBFT) -lft -o $(NAME) || \
		(echo -e "$(RED)Error during linking!$(DEF_COLOR)" && exit 1)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@ || (echo "$(RED)Error compiling $<!$(DEF_COLOR)" && exit 1)

clean:
	@rm -f $(OBJS)
	@echo -e "$(GREEN)Clean successful !$(DEF_COLOR)"

fclean: clean
	@rm -f $(NAME)
	@echo -e "$(GREEN)Full clean successful !$(DEF_COLOR)"

re: fclean all

.PHONY: all clean fclean re