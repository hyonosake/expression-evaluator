#ifndef NODES_H
# define NODES_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

# define EMPTY 0
# define NUM 'n'
# define PLUS '+'
# define MINUS '-'
# define MULTI '*'
# define DIVIDE '/'
# define IS_OPERAND(c) c == NUM || c == PLUS || c == MINUS || c == MULTI || c == DIVIDE
# define ISDIGIT(c) c >= '0' && c <= '9'
# define KGRN  "\x1B[32m"
# define KWHT  "\x1B[37m"
typedef struct	s_node
{
	char				type;
	void				*value;
	struct s_node		*left;
	struct s_node		*right;
}						t_node;

#endif