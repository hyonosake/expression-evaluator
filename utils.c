#include "evaluator.h"

char	*rl_gets(char *line)
{
	if (line)
	{
		free(line);
		line = NULL;
	}
	rl_on_new_line();
	line = readline("\033[33mevaluator:> \033[0m");
	if (line && *line)
		add_history(line);
	return (line);
}

int64_t		ft_atoi(char const *str)
{
	int			i;
	uint64_t	result;
	int			sign;

	i = 0;
	result = 0;
	sign = 1;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= (-1);
		i++;
	}
	while (isdigit(str[i]))
	{
		if (result * 10 < result)
		{
			if (sign < 0)
				return (-1);
			return (0);
		}
		result = result * 10 + (str[i] - 48);
		i++;
	}
	return (result * sign);
}

