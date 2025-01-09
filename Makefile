CC = cc 
CFLAGS = -Wall -Wextra -Werror -g
NAME = pipex
INCLUDES = -I includes/

LIBFT_DIR = libft/
LIBFT = ${LIBFT_DIR}libft.a

SRC = src/main.c

OBJ = ${SRC:.c=.o}

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	@$(CC) $(CFLAGS) $(INCLUDES) $(SRC) $(LIBFT) -o $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)
	@make -C $(LIBFT_DIR) clean

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re