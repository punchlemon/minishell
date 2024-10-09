.PHONY: all clean fclean re
NAME = libft.a

INCLUDES_DIR = includes
SRCS_DIR = srcs
OBJS_DIR = objs

EXTEND_DIR = extend
MANDATORY_DIR = mandatory

IS_DIR = is
MEM_DIR = mem
STR_DIR = str

NPK_FLAG = --noprint-directory
CC = clang

DIRS = \
	$(EXTEND_DIR) \
	$(MANDATORY_DIR) \

EXTEND_DIR_DIRS = \
	$(IS_DIR) \
	$(MEM_DIR) \
	$(STR_DIR) \

MANDATORY_DIR_DIRS = \
	$(MEM_DIR) \
	$(STR_DIR) \

EXTEND_IS_FILES = \
	ft_isspace \

EXTEND_MEM_FILES = \
	free_pp \

EXTEND_STR_FILES = \
	ft_split_func \
	ft_strcmp \

MANDATORY_MEM_FILES = \
	ft_bzero \
	ft_calloc \
	ft_memcmp \
	ft_memmove \

MANDATORY_STR_FILES = \
	ft_split \
	ft_strlen \
	ft_strncmp \

EXTEND_FILES = \
	$(addprefix $(IS_DIR)/, $(EXTEND_IS_FILES)) \
	$(addprefix $(MEM_DIR)/, $(EXTEND_MEM_FILES)) \
	$(addprefix $(STR_DIR)/, $(EXTEND_STR_FILES)) \

MANDATORY_FILES = \
	$(addprefix $(MEM_DIR)/, $(MANDATORY_MEM_FILES)) \
	$(addprefix $(STR_DIR)/, $(MANDATORY_STR_FILES)) \

EXTEND_DIR_FILES = $(addprefix $(EXTEND_DIR)/, $(EXTEND_FILES))
MANDATORY_DIR_FILES = $(addprefix $(MANDATORY_DIR)/, $(MANDATORY_FILES))

FILES = \
	$(EXTEND_DIR_FILES) \
	$(MANDATORY_DIR_FILES) \

CFLAGS = -Wall -Werror -Wextra
IFLAGS = -I$(INCLUDES_DIR)

SRCS = $(addprefix $(SRCS_DIR)/, $(addsuffix .c, $(FILES)))
OBJS = $(addprefix $(OBJS_DIR)/, $(addsuffix .o, $(FILES)))

all: $(NAME)

$(NAME): $(OBJS)
	@$(AR) rcs $@ $(OBJS)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c | $(OBJS_DIR)
	@$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

$(OBJS_DIR):
	@mkdir -p $@
	@$(foreach dir, $(DIRS), mkdir -p $@/$(dir);)
	@$(foreach dir, $(EXTEND_DIR_DIRS), mkdir -p $@/$(EXTEND_DIR)/$(dir);)
	@$(foreach dir, $(MANDATORY_DIR_DIRS), mkdir -p $@/$(MANDATORY_DIR)/$(dir);)

clean:
	@$(RM) -r $(OBJS_DIR)

fclean: clean
	@$(RM) $(NAME) $(VALGRIND_LOG)

re: fclean all
