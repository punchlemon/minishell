NAME = minishell
INCLUDES_DIR = includes
SRCS_DIR = srcs
OBJS_DIR = objs
NPK_FLAG = --noprint-directory

FILES = \
	main \

CFLAGS = -Wall -Werror -Wextra -g
IFLAGS = -I$(INCLUDES_DIR)
VFLAGS = \
	--track-origins=yes \
	--leak-check=full \
	--show-leak-kinds=all \

SRCS = $(addprefix $(SRCS_DIR)/, $(addsuffix .c, $(FILES)))
OBJS = $(addprefix $(OBJS_DIR)/, $(addsuffix .o, $(FILES)))

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c | $(OBJS_DIR)
	@$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

$(OBJS_DIR):
	@mkdir -p $@

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) -o $@

clean:
	@$(RM) -r $(OBJS_DIR)

fclean: clean
	@$(RM) $(NAME) $(VALGRIND_LOG)

re: fclean all

VALGRIND_LOG = valgrind.log

val: re
	@valgrind $(VFLAGS) ./$(NAME) > $(VALGRIND_LOG) 2>&1
	@code $(VALGRIND_LOG)
