NAME = minishell
INCLUDES_DIR = includes
SRCS_DIR = srcs
OBJS_DIR = objs
ANLS_DIR = analysis
EXEC_DIR = execution
NPK_FLAG = --noprint-directory

DIRS = \
	$(ANLS_DIR) \
	$(EXEC_DIR) \

ANLS_FILES = \
	and_or \
	compare_bytes \
	copy_bytes \
	ft_split \
	ft_string_slice \
	ft_string \
	ft_strlcpy \
	mem_zero \
	split_string \
	string_to_char \
	string_utils \

EXEC_FILES = \
	exe \
	utils \

ANLS_DIR_FILES = $(addprefix $(ANLS_DIR)/, $(ANLS_FILES))

EXEC_DIR_FILES = $(addprefix $(EXEC_DIR)/, $(EXEC_FILES))

FILES = \
	main \
	$(ANLS_DIR_FILES) \
	$(EXEC_DIR_FILES) \

CFLAGS = -Wall -Werror -Wextra -g
IFLAGS = -I$(INCLUDES_DIR)
LFLAGS = -lreadline
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
	@$(foreach dir, $(DIRS), mkdir -p $@/$(dir);)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(LFLAGS) $(OBJS) -o $@

clean:
	@$(RM) -r $(OBJS_DIR)

fclean: clean
	@$(RM) $(NAME) $(VALGRIND_LOG)

re: fclean all

VALGRIND_LOG = valgrind.log

val: re
	@valgrind $(VFLAGS) ./$(NAME) > $(VALGRIND_LOG) 2>&1
	@code $(VALGRIND_LOG)
