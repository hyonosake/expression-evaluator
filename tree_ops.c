#include "evaluator.h"


void		perror_exit(const char *msg, int exit_status)	{
	perror(msg);
	exit(exit_status);
}
t_node		*create_token(char *token)
{
	t_node *new = calloc(1, sizeof(t_node));
	new->type = whatType(*token);
	if (new->type == -1 || !*token)
		perror_exit("Unknown token to parse.\n", *token);
	return (new);
}

void		parse_tokens(char **args)
{
	t_node	*token;
	static t_node	*root;
	static t_node	*curr_branch;
	t_node			*curr_cmd;
	int				i = 0;

	while (args[i])
		curr_cmd = create_token(args[i]);
	if (curr_cmd->type == NUM)	{
		if (!curr_branch->left)
			curr_branch->left = curr_cmd;
		else if (!curr_branch->right)
			curr_branch->right = curr_cmd;
		else
			perror_exit("Making 2 operands in a row.\n", 127);
	}
}

void		fill_in_tree(t_node **head, t_node **curr_branch, t_node *cmd)
{
	if (!*head)
	{
		*head
	}
}

double		void_multi(void *a, void *b)
{
	char *a_str = (char *)a;
	char *b_str = (char *)b;

	return (atoi(a_str) * atoi(b_str));
}

double		void_divide(void *a, void *b)
{
	char *a_str = (char *)a;
	char *b_str = (char *)b;

	return (atoi(a_str) / atoi(b_str));
}

double		void_plus(void *a, void *b)
{
	char *a_str = (char *)a;
	char *b_str = (char *)b;

	return (atoi(a_str) + atoi(b_str));
}
double 	void_minus(void *a, void *b)
{
	char *a_str = (char *)a;
	char *b_str = (char *)b;

	return (atoi(a_str) - atoi(b_str));
}

void	calculate_value(t_node *root)
{
	if (!root)
		return ;
	calculate_value(root->left);
	calculate_value(root->right);
	if (root->type == NUM)
		return ;
	if (root->type == MULTI)
	{
		root->value = malloc(sizeof(double));
		*((double *)(root->value)) = *((double *)root->left->value) * *((double *)root->right->value);
	}
	else if (root->type == DIVIDE)
	{
		root->value = malloc(sizeof(double));
		*((double *)root->value) = *((double *)root->left->value) / *((double *)root->right->value);
	}
	else if (root->type == PLUS)
	{
		root->value = malloc(sizeof(double));
		*((double *)root->value) = *((double *)root->left->value) + *((double *)root->right->value);
	}
	else if (root->type == MINUS)
	{
		root->value = malloc(sizeof(double));
		*((double *)root->value) = *((double *)root->left->value) - *((double *)root->right->value);
	}
	// no free here.
	root->left = NULL;
	root->right = NULL;
}

void print_postorder(t_node *root)
{
    if(!root)
		return ;
    print_postorder(root->left);
    print_postorder(root->right);
	if (root->type == NUM)
		printf("%d ", *((int *)root->value));
	else
		printf("'%c' ", root->type);
}
