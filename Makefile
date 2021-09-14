NAME		=	fp_init
CC			=	gcc

WFLAGS		= 	-Wall -Werror -Wextra

FLAGS		=	$(WFLAGS) -g

SRCS_DIR	=	.
INC_DIR		=	.
SRCS_LIST	=	main.c split.c tree_ops.c utils.c 2d_arrays.c
SRCS		=	$(addprefix $(SRCS_DIR)/, $(SRCS_LIST))
HEADERS		=	$(notdir $(*.h))
OBJS_DIR	=	./build
OBJS		=	$(SRCS:%.c=$(OBJS_DIR)/%.o)
DEPS		=	$(SRCS:%.c=$(OBJS_DIR)/%.d)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c Makefile
	@mkdir -p $(@D)
	$(CC) $(FLAGS) -MMD -c $< -o $@ -I $(HEADERS)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME) -I $(HEADERS)

clean:
	rm -rf $(OBJS)
	rm -rf $(DEPS)
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re

-include $(DEPS)
