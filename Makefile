NAME = minishell
INCLUDES_DIR = includes
SRCS_DIR = srcs
OBJS_DIR = objs
ANLS_DIR = analysis
EXEC_DIR = execution
LIBFT_DIR = libft
AND_OR_DIR = and_or
CMD_DIR = cmd
MEM_DIR = ft_memory
STR_DIR = ft_string
PIPE_DIR = pipe
NPK_FLAG = --noprint-directory
CC = clang

DIRS = \
	$(ANLS_DIR) \
	$(EXEC_DIR) \
	$(LIBFT_DIR) \

ANLS_DIR_DIRS = \
	$(AND_OR_DIR) \
	$(CMD_DIR) \
	$(MEM_DIR) \
	$(STR_DIR) \
	$(PIPE_DIR) \

AND_OR_FILES = \
	and_or \
	create_and_or \
	delete_and_or \
	print_and_or \
	split_str_and_or \

CMD_FILES = \
	create_cmd \
	delete_cmd \

MEM_FILES = \
	ft_calloc \
	ft_memcpy \
	ft_memzero \
	is_equal_mem \

STR_FILES = \
	append_str_arr \
	convert_str_to_char \
	create_str \
	create_str_arr \
	delete_str \
	delete_str_arr \
	get_str_arr \
	is_equal_str \
	put_num \
	put_str_arr \
	put_str \
	remove_str_arr \
	split_str_arr \
	split_str \
	trim_edge_str \
	trim_space_str \
	utils \

PIPE_FILES = \
	create_pipe \
	delete_pipe \

ANLS_FILES = \
	analysis \
	ft_split \
	ft_strlcpy \
	$(addprefix $(AND_OR_DIR)/, $(AND_OR_FILES)) \
	$(addprefix $(CMD_DIR)/, $(CMD_FILES)) \
	$(addprefix $(MEM_DIR)/, $(MEM_FILES)) \
	$(addprefix $(STR_DIR)/, $(STR_FILES)) \
	$(addprefix $(PIPE_DIR)/, $(PIPE_FILES)) \

EXEC_FILES = \
	exe \
	utils \

LIBFT_FILES = \
	ft_memcmp \
	ft_strcmp \
	ft_strlen \
	ft_strncmp \

ANLS_DIR_FILES = $(addprefix $(ANLS_DIR)/, $(ANLS_FILES))
EXEC_DIR_FILES = $(addprefix $(EXEC_DIR)/, $(EXEC_FILES))
LIBFT_DIR_FILES = $(addprefix $(LIBFT_DIR)/, $(LIBFT_FILES))

FILES = \
	main \
	$(ANLS_DIR_FILES) \
	$(EXEC_DIR_FILES) \
	$(LIBFT_DIR_FILES) \

CFLAGS = -Wall -Werror -Wextra
IFLAGS = -I$(INCLUDES_DIR)
LFLAGS = -lreadline
VFLAGS = \
	--track-origins=yes \
	--leak-check=full \
	--show-leak-kinds=all \
	--suppressions=readline.supp \
	--gen-suppressions=all \

SRCS = $(addprefix $(SRCS_DIR)/, $(addsuffix .c, $(FILES)))
OBJS = $(addprefix $(OBJS_DIR)/, $(addsuffix .o, $(FILES)))

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LFLAGS) -o $@

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
