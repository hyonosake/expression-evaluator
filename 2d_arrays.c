#include "evaluator.h"

void	free_2d_array(char **arr)
{
	int32_t	i;

	i = 0;
	while (arr && arr[i])
	{
		free(arr[i]);
		++i;
	}
	if (arr)
		free(arr);
}
