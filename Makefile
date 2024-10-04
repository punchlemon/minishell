NAME = minishell
INCLUDES_DIR = includes
SRCS_DIR = srcs
OBJS_DIR = objs
ANLS_DIR = analysis
EXEC_DIR = execution
CMD_DIR = cmd
MEM_DIR = ft_memory
STR_DIR = ft_string
NPK_FLAG = --noprint-directory

DIRS = \
	$(ANLS_DIR) \
	$(EXEC_DIR) \

ANLS_DIR_DIRS = \
	$(CMD_DIR) \
	$(MEM_DIR) \
	$(STR_DIR) \

CMD_FILES = \
	create_cmd_node \
	create_pipe_cmd \
	delete_cmd_node \
	delete_pipe_cmd \
	print_cmd_node \

MEM_FILES = \
	ft_calloc \
	ft_memcpy \
	ft_memzero \
	is_equal_mem \

STR_FILES = \
	append_str_slice \
	create_str \
	create_str_slice \
	delete_str \
	delete_str_slice \
	get_str_slice \
	insert_str_slice \
	is_equal_str \
	put_num \
	put_str_slice \
	put_str \
	remove_str_slice \
	split_str_slice \
	split_str \
	str_to_char \
	trim_edge_str \
	trim_space_str \
	utils \

ANLS_FILES = \
	analysis \
	and_or \
	ft_split \
	ft_strlcpy \
	is_valid_str_and_or \
	split_str_and_or \
	$(addprefix $(CMD_DIR)/, $(CMD_FILES)) \
	$(addprefix $(MEM_DIR)/, $(MEM_FILES)) \
	$(addprefix $(STR_DIR)/, $(STR_FILES)) \

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
