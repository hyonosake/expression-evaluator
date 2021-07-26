#include "nodes.h"


t_node	*new_node(char type, void *value)
{
	t_node *new;

	new = (t_node *)malloc(sizeof(t_node));
	new->type = type;
	new->value = value;
	new->left = NULL;
	new->right = NULL;
	return (new);
}

int		*num_add(char *str)
{
	int	*new;

	new = (int *)malloc(sizeof(int));
	*new = atoi(str);
	return (new);
}

void	parse_tokens(t_node **root_node, t_node **curr, char *node_value)
{
	t_node	*token;
	int		*num;
	if (IS_OPERAND(node_value[0]))
	{
		if (!(*root_node)->type)
		{
				printf("Filling in the 1st node...\n");
				(*root_node)->type = *node_value;
		}
		else if (!((*root_node)->right))
		{
			printf("Trying to make 2 operations in a row. Not gonna work tho\n");
			exit(1);
		}
		else if (*node_value == '-' || *node_value == '+')
		{
			printf("Node is %c. Rebuilding a tree\n", *node_value);
			//make root changes
			token = new_node(*node_value, NULL);
			token->left = *root_node;
			*root_node = token;
			*curr = *root_node;
		}
		else if (*node_value == '*' || *node_value == '/')
		{
			printf("Node is %c. Getting further down the tree\n", *node_value);
			//make root changes
			token = new_node(*node_value, NULL);
			token->left = (*root_node)->right;
			(*root_node)->right = token;
			*curr = token;
		}
	}
	//does not check for "12g4"-like arrays
	else if (ISDIGIT(*node_value))
	{
		token = new_node(NUM, (void *)node_value);
		num = num_add((char *)node_value);
		if (!((*curr)->left))
			(*curr)->left = new_node(NUM, num);
		else if (!((*curr)->right))
			(*curr)->right = new_node(NUM, num);
		else
		{
			printf("Trying to insert 2 operands without an operation between'em. Not gonna work tho\n");
			exit(1);
		}
	}
	else
	{
		printf("What is '%c' token? It's not allowed here!\n", *node_value);
		exit(1);
	}
}

int		void_multi(void *a, void *b)
{
	char *a_str = (char *)a;
	char *b_str = (char *)b;

	return (atoi(a_str) * atoi(b_str));
}

int		void_divide(void *a, void *b)
{
	char *a_str = (char *)a;
	char *b_str = (char *)b;

	return (atoi(a_str) / atoi(b_str));
}

int		void_plus(void *a, void *b)
{
	char *a_str = (char *)a;
	char *b_str = (char *)b;

	return (atoi(a_str) + atoi(b_str));
}
int 	void_minus(void *a, void *b)
{
	char *a_str = (char *)a;
	char *b_str = (char *)b;

	return (atoi(a_str) - atoi(b_str));
}

void	calculate_value(t_node *root)
{
	if (root->left && root->left->type != NUM)
		calculate_value(root->left);
	else if (root->right && root->right->type != NUM)
		calculate_value(root->right);

	if (root->type == MULTI)
	{
		root->value = malloc(sizeof(int));
		*((int *)(root->value)) = *((int *)root->left->value) * *((int *)root->right->value);
		root->type = NUM;
	}
	else if (root->type == DIVIDE)
	{
		root->value = malloc(sizeof(int));
		*((int *)root->value) = *((int *)root->left->value) / *((int *)root->right->value);
		root->type = NUM;
	}
	else if (root->type == PLUS)
	{
		root->value = malloc(sizeof(int));
		*((int *)root->value) = *((int *)root->left->value) + *((int *)root->right->value);
		root->type = NUM;
	}
	else if (root->type == MINUS)
	{
		root->value = malloc(sizeof(int));
		*((int *)root->value) = *((int *)root->left->value) - *((int *)root->right->value);
		root->type = NUM;
	}
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
		printf("%d\t", *((int *)root->value));
	else
		printf("'%c'\t", root->type);
}

int main(int ac, char **av)
{
	t_node	*root;
	t_node	*curr;
	int		i;

	i = 1;
	root = new_node(EMPTY, NULL);
	curr = root;
	while (av[i])
	{
		printf("\n======== Adding token '%s' ========\n", av[i]);
		parse_tokens(&root, &curr, av[i]);
		printf("Root ptr points to \t%p\n", root);
		printf("Current ptr points to \t%p\n", curr);
		printf("Root now stores '%c'\n", root->type);
		i++;
		usleep(250000);
	}
	print_postorder(root);
	printf("\nPicture that: '%c'\n", root->left->left->left->type);
	printf("\nFarmost left holds: %d\n", *((int*)root->left->left->left->left->value));
	//calculate_value(root);
	//printf("\nRoot now is '%c' and holds value of \x1B[32m %d\n \x1B[37m", root->type, *((int *)root->value));
	return 0;
}