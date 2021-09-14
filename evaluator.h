#ifndef EVALUATOR_H
# define EVALUATOR_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdint.h>
# include <readline/readline.h>
# include <readline/history.h>

# define EMPTY		0
# define NUM		'n'
# define PLUS		'+'
# define MINUS		'-'
# define MULTI		'*'
# define DIVIDE		'/'
# define OPEN_BRACK	'('
# define CLOSE_BRACK ')'
# define RESET		"\033[0m"
# define BLACK		"\033[30m"      /* Black */
# define RED		"\033[31m"      /* Red */
# define GREEN		"\033[32m"      /* Green */
# define YELLOW		"\033[33m"      /* Yellow */
# define BLUE		"\033[34m"      /* Blue */
# define MAGENTA	"\033[35m"      /* Magenta */
# define CYAN		"\033[36m"      /* Cyan */
# define WHITE		"\033[37m"      /* White */

typedef struct	s_node
{
	char				type;
	int					value;
	struct s_node		*left;
	struct s_node		*right;
}						t_node;

t_node		*new_node(char type, void *value);
int			*num_add(char *str);
int8_t		whatType(char sym);
void		parse_tokens(char **args);
double		void_multi(void *a, void *b);
double		void_divide(void *a, void *b);
double		void_plus(void *a, void *b);
double 		void_minus(void *a, void *b);
void		calculate_value(t_node *root);
void		print_postorder(t_node *root);
char		*rl_gets(char *line);
char		**split(char *s, char c);
int64_t		ft_atoi(char const *str);
void		free_2d_array(char **arr);
#endif