#include "evaluator.h"


void	print_prompt()
{
	printf("Print");
	printf(RED);
	printf(" EXIT ");
	printf(RESET);
	printf("to quit. Or just SIGINT ;).\n");
}

void	print_result(char root_type, int res)
{
	printf("\n");
	printf("Root now is '%c' and holds value of", root_type);
	printf ("\033[1m\033[32m %d\n", res);
	printf(RESET);
	printf("\n\n\n");
}

int main(void)
{
	t_node	*root;
	t_node	*curr;
	int		i = 0;
	char	*input;
	char	**args;

	input = NULL;
	root = new_node(EMPTY, NULL);
	curr = root;
	while (1)
	{
		print_prompt();
		input = rl_gets(input);
		args = split(input, ' ');
		parse_tokens(args);
		free_2d_array(args);
		printf("Postorder traversal calculation\n");
		calculate_value(root);
		print_result(root->type, *((int *)root->value));
	}
	return 0;
}