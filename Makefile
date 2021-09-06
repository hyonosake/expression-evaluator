NAME =	evaluator
SRCS =	main.c \
		utils.c \
		split.c \
		tree_ops.c \
		2d_arrays.c
OBJS = $(SRCS:.c=.o)

SRC_D = $(SRCS:.c=.d)

USR = $(shell whoami)
CC =	gcc

LRD_INC =	-I/Users/$(USR)/.brew/opt/readline/include
LLRD_INC =	-I/usr/local/Cellar/readline/8.1/include
LRD_LIB =	-lreadline -L/Users/$(USR)/.brew/opt/readline/lib
LLRD_LIB =	-lreadline -L/usr/local/Cellar/readline/8.1/lib

FLAGS = -g -MMD \
		-Wall -Wextra -Werror \
		-O2 \
		#-fsanitize=address

.c.o:
			$(CC)  $(FLAGS) -c -I nodes.h  $(LRD_INC) $< -o ${<:.c=.o} 

$(NAME):	$(OBJS)
			$(CC)  $(FLAGS) $(OBJS) -o $(NAME) $(LRD_LIB)
	@echo	"Binary created"

all:		$(NAME)

c:			all clean
clean:
			rm -f $(OBJS)
			rm -f $(SRC_D)
	@echo "Object files were deleted"

fclean:		clean
			rm -f $(NAME)
	@echo "Everithing was deleted"

re:			fclean all

-include $(SRC_D)
#.SILENT: