.PHONY: all clean fclean re
NAME = minishell
LIBFT_DIR = libft
LIBFT_A = libft.a

INCLUDES_DIR = includes
SRCS_DIR = srcs
OBJS_DIR = objs

ANALYSIS_DIR = analysis
EXECUTION_DIR = execution

AND_OR_DIR = and_or
CMD_DIR = cmd
STR_DIR = ft_string
PIPE_DIR = pipe

NPD_FLAG = --no-print-directory
CC = clang

DIRS = \
	$(ANALYSIS_DIR) \
	$(EXECUTION_DIR) \
	$(LIBFT_DIR) \

ANALYSIS_DIR_DIRS = \
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

ANALYSIS_FILES = \
	analysis \
	$(addprefix $(AND_OR_DIR)/, $(AND_OR_FILES)) \
	$(addprefix $(CMD_DIR)/, $(CMD_FILES)) \
	$(addprefix $(MEM_DIR)/, $(MEM_FILES)) \
	$(addprefix $(STR_DIR)/, $(STR_FILES)) \
	$(addprefix $(PIPE_DIR)/, $(PIPE_FILES)) \

EXECUTION_FILES = \
	exe \
	utils \

ANALYSIS_DIR_FILES = $(addprefix $(ANALYSIS_DIR)/, $(ANALYSIS_FILES))
EXECUTION_DIR_FILES = $(addprefix $(EXECUTION_DIR)/, $(EXECUTION_FILES))
LIBFT_DIR_FILES = $(addprefix $(LIBFT_DIR)/, $(LIBFT_FILES))

FILES = \
	main \
	$(ANALYSIS_DIR_FILES) \
	$(EXECUTION_DIR_FILES) \
	$(LIBFT_DIR_FILES) \

CFLAGS = -Wall -Werror -Wextra
IFLAGS = -I$(INCLUDES_DIR) -I$(LIBFT_DIR)/$(INCLUDES_DIR)
LFLAGS = -lreadline -lft
VFLAGS = \
	--track-origins=yes \
	--leak-check=full \
	--show-leak-kinds=all \
	--suppressions=readline.supp \
	--gen-suppressions=all \

SRCS = $(addprefix $(SRCS_DIR)/, $(addsuffix .c, $(FILES)))
OBJS = $(addprefix $(OBJS_DIR)/, $(addsuffix .o, $(FILES)))

all: $(NAME)

$(NAME): $(LIBFT_DIR)/$(LIBFT_A) | $(OBJS)
	@$(CC) $(OBJS) $(LFLAGS) -o $@

$(LIBFT_DIR)/$(LIBFT_A):
	@make $(NPD_FLAG) -C $(LIBFT_DIR) all

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c | $(OBJS_DIR)
	@$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

$(OBJS_DIR):
	@mkdir -p $@
	@$(foreach dir, $(DIRS), mkdir -p $@/$(dir);)
	@$(foreach dir, $(ANALYSIS_DIR_DIRS), mkdir -p $@/$(ANALYSIS_DIR)/$(dir);)

clean:
	@make $(NPD_FLAG) -C $(LIBFT_DIR) clean
	@$(RM) -r $(OBJS_DIR)

fclean: clean
	@make $(NPD_FLAG) -C $(LIBFT_DIR) fclean
	@$(RM) $(NAME) $(VALGRIND_LOG)

re: fclean all

VALGRIND_LOG = valgrind.log

val: re
	@valgrind $(VFLAGS) ./$(NAME) > $(VALGRIND_LOG) 2>&1
