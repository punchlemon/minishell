.PHONY: all clean fclean re val norm test
NAME = minishell

LIBFT_DIR = libft
LIBFT_A = libft.a

INCLUDES_DIR = includes
SRCS_DIR = srcs
OUT_DIR = out

RESET = \033[0m
RED = \033[31m
GREEN = \033[32m
YELLOW = \033[33m
BLUE = \033[34m
MAGENTA = \033[35m
CYAN = \033[36m
WHITE = \033[37m

SRCS = \
$(addsuffix .c, \
	$(addprefix $(SRCS_DIR)/, \
		$(addprefix analysis/, \
			$(addprefix lexer/, \
				count \
				is \
				lexer \
				store \
			) \
			parser \
			analysis \
			checker \
			print \
			print_tkns \
			type_is \
		) \
		$(addprefix execution/, \
			count_cmd \
			count_word \
			create_heredoc \
			destroy_exe \
			execute_cmd \
			execute_cmds \
			execute_utils \
			expand_cmd \
			ft_itoa \
			get_path_cmd \
			get_path_cmd_utils \
			get_value \
			open_file \
			pipe \
			read_all_heredoc \
			read_heredoc \
			redirect \
			store_cmd \
			store_word \
		) \
		$(addprefix signal/, \
			signal_handler \
			signal \
		) \
		$(addprefix builtin/, \
			cd \
			cd_utils_1 \
			cd_utils_2 \
			echo \
			env \
			exit \
			exit_utils \
			export \
			export_utils_1 \
			export_utils_2 \
			list_utils \
			list \
			pwd \
			unset \
		) \
		main \
	) \
) \

OBJS = $(addprefix $(OUT_DIR)/, $(SRCS:.c=.o))
DEPS = $(addprefix $(OUT_DIR)/, $(SRCS:.c=.d))

NPD_FLAG = --no-print-directory

CFLAGS = -Wall -Werror -Wextra
IFLAGS = -I$(INCLUDES_DIR) -I$(INCLUDES_DIR)/analysis -I$(LIBFT_DIR)/$(INCLUDES_DIR)
LFLAGS = -lreadline -L$(LIBFT_DIR) -lft
VFLAGS = \
	--leak-check=full \
	--suppressions=readline.supp \
	--trace-children=yes \
	--track-fds=yes \
#  --track-origins=yes \
#  --show-leak-kinds=all \
#  --gen-suppressions=all
#  --show-leak-kinds=definite,indirect

# --track-origins=yes --leak-check=full --show-leak-kinds=definite,indirect --suppressions=readline.supp --gen-suppressions=all --trace-children=yes --track-fds=yes

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

de:
	@clear
	@make $(NPD_FLAG) re
	@./$(NAME)

VALGRIND_LOG = valgrind.log

val:
	@clear
	@make $(NPD_FLAG) re
	@valgrind $(VFLAGS) ./$(NAME) 2> $(VALGRIND_LOG)

norm:
	@$(call check_norminette, $(LIBFT_DIR))
	@$(call check_norminette, $(SRCS_DIR))
	@$(call check_norminette, $(INCLUDES_DIR))

define ok
	echo $1"$(GREEN)OK$(RESET)"
endef

define check_norminette
	@if norminette $1 | grep -q Error; then \
		norminette $1 | grep Error; \
	else \
		$(call ok, $1": "); \
	fi
endef

TEST_DIR = test
SUCCESS_TXT = success.txt
FAILURE_TXT = failure.txt

test: re
	@echo "[$(YELLOW)success test$(RESET)]"
	@while IFS= read -r line; do \
		echo ====================; \
		if (echo "$$line"; echo exit) | ./$(NAME) | grep -Eq "minishell: syntax error|minishell: malloc error"; then \
			echo "$$line"; echo "$(RED)KO!!!!!!$(RESET)"; \
		else \
			echo "$$line"; echo "$(GREEN)OK$(RESET)"; \
		fi; \
	done < $(TEST_DIR)/$(SUCCESS_TXT)
	@echo ====================;
	@echo ; echo ; echo ;
	@echo "[$(YELLOW)failure test$(RESET)]"
	@while IFS= read -r line; do \
		echo ====================; \
		if (echo "$$line"; echo exit) | ./$(NAME) | grep -Eq "minishell: syntax error|minishell: malloc error"; then \
			echo "$$line"; echo "$(GREEN)OK$(RESET)"; \
		else \
			echo "$$line"; echo "$(RED)KO!!!!!!$(RESET)"; \
		fi; \
	done < $(TEST_DIR)/$(FAILURE_TXT)
	@echo ====================;
