.PHONY: all clean fclean re val norm test
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
			$(addprefix check/, \
				check_cmd \
				check_conds \
			) \
			$(addprefix lexer/, \
				count \
				lexer \
				store \
			) \
			$(addprefix parser/, \
				$(addprefix count/, \
					count_tkns_for \
				) \
				$(addprefix create/, \
					cmds_utils \
					cmds \
					conds \
					reds \
					word \
					words \
				) \
				parser \
			) \
			analysis \
			print_conds \
			print_indent \
			print_tkns \
			type_is \
		) \
		$(addprefix execution/, \
			exe \
		) \
		main \
	) \
) \

OBJS = $(addprefix $(OUT_DIR)/, $(SRCS:.c=.o))
DEPS = $(addprefix $(OUT_DIR)/, $(SRCS:.c=.d))

CC = clang
NPD_FLAG = --no-print-directory

CFLAGS = -Wall -Werror -Wextra
IFLAGS = -I$(INCLUDES_DIR) -I$(INCLUDES_DIR)/analysis -I$(LIBFT_DIR)/$(INCLUDES_DIR)
LFLAGS = -lreadline -L$(LIBFT_DIR) -lft
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
	@valgrind $(VFLAGS) ./$(NAME) 2> $(VALGRIND_LOG)

norm:
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
	while IFS= read -r line; do \
		echo "$$line" | ./$(NAME); \
	done < $(TEST_DIR)/$(SUCCESS_TXT)
	while IFS= read -r line; do \
		echo "$$line" | ./$(NAME); \
	done < $(TEST_DIR)/$(FAILURE_TXT)
