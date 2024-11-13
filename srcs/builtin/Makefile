NAME = a.out
CC = cc
LFLAGS = -lreadline
VFLAGS = --leak-check=full --show-leak-kinds=all --track-origins=yes
SRCS = list_utils.c list.c cd.c pwd.c readline.c \
		echo.c env.c exit.c export.c export_utils.c unset.c \
		./libft/ft_split.c \
		./libft/ft_strlen.c \
		./libft/ft_strdup.c \
		./libft/ft_substr.c \
		./libft/ft_strjoin.c \
		./libft/ft_isalpha.c \
		./libft/ft_isdigit.c \
		./libft/ft_atoi.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(LFLAGS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

val: re
	valgrind $(VFLAGS) ./$(NAME)

.PHONY: all clean fclean re