.PHONY: all clean fclean re
NAME = libft.a

INCLUDES_DIR = includes
SRCS_DIR = srcs
OUT_DIR = out

SRCS = \
$(addsuffix .c, \
	$(addprefix $(SRCS_DIR)/, \
		$(addprefix extend/, \
			$(addprefix ft_printf/, \
				ft_printf_base_check \
				ft_printf_base \
				ft_printf \
				ft_putdec \
				ft_puthex \
				ft_putnumber_base \
				ft_putoct \
				ft_putptr \
			) \
			$(addprefix ft_printf_stderr/, \
				ft_printf_utils \
				format_put_letter \
				format_put_num \
				ft_printf_stderr \
			) \
			$(addprefix get_next_line/, \
				get_next_line \
				get_next_line_utils \
			) \
			$(addprefix mem/, \
				free_pp \
				ft_xcalloc \
			) \
			$(addprefix str/, \
				ft_split_func \
				ft_strcmp \
			) \
		) \
		$(addprefix mandatory/, \
			$(addprefix is/, \
				ft_isalpha \
				ft_isdigit \
			) \
			$(addprefix put/, \
				ft_putchar_fd \
				ft_putendl_fd \
			) \
			$(addprefix mem/, \
				ft_bzero \
				ft_calloc \
				ft_memcmp \
				ft_memmove \
			) \
			$(addprefix str/, \
				ft_split \
				ft_strchr \
				ft_strrchr \
				ft_strjoin \
				ft_strlen \
				ft_strncmp \
				ft_substr \
				ft_strdup \
				ft_atoi \
			) \
		) \
	) \
) \

OBJS = $(addprefix $(OUT_DIR)/, $(SRCS:.c=.o))
DEPS = $(addprefix $(OUT_DIR)/, $(SRCS:.c=.d))

CC = clang
NPK_FLAG = --noprint-directory

CFLAGS = -Wall -Werror -Wextra
IFLAGS = -I$(INCLUDES_DIR)

all: $(NAME)

$(NAME): $(OBJS)
	@$(AR) rcs $@ $(OBJS)

$(OUT_DIR)/%.o: %.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

clean:
	@$(RM) -r $(OUT_DIR)

fclean: clean
	@$(RM) $(NAME) $(VALGRIND_LOG)

re: fclean all
