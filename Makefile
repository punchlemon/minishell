NAME = minishell
INCLUDES_DIR = includes
SRCS_DIR = srcs
OBJS_DIR = objs
ANLS_DIR = analysis
EXEC_DIR = execution
MEMY_DIR = ft_memory
STRG_DIR = ft_string
NPK_FLAG = --noprint-directory

DIRS = \
	$(ANLS_DIR) \
	$(EXEC_DIR) \

ANLS_DIR_DIRS = \
	$(MEMY_DIR) \
	$(STRG_DIR) \

MEMY_FILES = \
	compare_bytes \
	ft_memory \
	ft_memzero \
	is_equal_mem \

STRG_FILES = \
	create_str \
	create_str_slice \
	delete_str \
	delete_str_slice \
	is_equal_str \
	str_utils \
	utils \

ANLS_FILES = \
	analysis \
	and_or \
	ft_split \
	ft_strlcpy \
	$(addprefix $(MEMY_DIR)/, $(MEMY_FILES)) \
	$(addprefix $(STRG_DIR)/, $(STRG_FILES)) \

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

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(LFLAGS) $(OBJS) -o $@

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c | $(OBJS_DIR)
	@$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

$(OBJS_DIR):
	@mkdir -p $@
	@$(foreach dir, $(DIRS), mkdir -p $@/$(dir);)
	@$(foreach dir, $(ANLS_DIR_DIRS), mkdir -p $@/$(ANLS_DIR)/$(dir);)

clean:
	@$(RM) -r $(OBJS_DIR)

fclean: clean
	@$(RM) $(NAME) $(VALGRIND_LOG)

re: fclean all

VALGRIND_LOG = valgrind.log

val: re
	@valgrind $(VFLAGS) ./$(NAME) > $(VALGRIND_LOG) 2>&1
	@code $(VALGRIND_LOG)
