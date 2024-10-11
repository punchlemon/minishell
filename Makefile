.PHONY: all clean fclean re
NAME = minishell
LIBFT_DIR = libft
LIBFT_A = libft.a

INCLUDES_DIR = includes
SRCS_DIR = srcs
OUT_DIR = out

SRCS = \
$(addsuffix .c, \
	$(addprefix $(SRCS_DIR)/, \
		$(addprefix analysis/, \
			$(addprefix and_or/, \
				delete_and_or \
				print_and_or \
			) \
			$(addprefix cmd/, \
				create_cmd \
				delete_cmd \
			) \
			$(addprefix ft_string/, \
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
			) \
			$(addprefix lexer/, \
				check_lex \
				count_lex \
				lexer \
				store_lex \
			)
			$(addprefix pipe/, \
				create_pipe \
				delete_pipe \
			) \
		) \
		$(addprefix execution/, \
			exe \
			utils \
		) \
		main \
	) \
) \

OBJS = $(addprefix $(OUT_DIR)/, $(SRCS:.c=.o))
DEPS = $(addprefix $(OUT_DIR)/, $(SRCS:.c=.d))

CC = clang
NPD_FLAG = --no-print-directory

CFLAGS = -Wall -Werror -Wextra
IFLAGS = -I$(INCLUDES_DIR) -I$(LIBFT_DIR)/$(INCLUDES_DIR)
LFLAGS = -lreadline -lft
VFLAGS = \
	--track-origins=yes \
	--leak-check=full \
	--show-leak-kinds=all \
	--suppressions=readline.supp \
	--gen-suppressions=all \

all: $(NAME)

$(NAME): $(LIBFT_DIR)/$(LIBFT_A) | $(OBJS)
	@$(CC) $(OBJS) $(LFLAGS) -o $@

$(LIBFT_DIR)/$(LIBFT_A):
	@make $(NPD_FLAG) -C $(LIBFT_DIR) all

$(OUT_DIR)/%.o: %.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

clean:
	@make $(NPD_FLAG) -C $(LIBFT_DIR) clean
	@$(RM) -r $(OUT_DIR)

fclean: clean
	@make $(NPD_FLAG) -C $(LIBFT_DIR) fclean
	@$(RM) $(NAME) $(VALGRIND_LOG)

re: fclean all

VALGRIND_LOG = valgrind.log

val: re
	@valgrind $(VFLAGS) ./$(NAME) > $(VALGRIND_LOG) 2>&1
