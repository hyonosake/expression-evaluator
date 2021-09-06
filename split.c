#include "evaluator.h"

static char	*substr(const char *s, uint32_t start, uint32_t len)
{
	char		*substr;
	uint32_t	j;
	int32_t		i;

	if (!s)
		return (NULL);
	j = start;
	i = 0;
	substr = (char *)calloc(sizeof(char), (len + 1));
	if (!substr)
		return (NULL);
	while (len > 0 && s[j])
	{
		substr[i] = s[j];
		j++;
		i++;
		len--;
	}
	substr[i] = '\0';
	return (substr);
}

static int	word_len(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static int	word_count(const char *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[j])
	{
		while (s[j] == c && s[j])
			j++;
		if (!s[j])
			break ;
		i++;
		while (s[j] != c && s[j])
			j++;
	}
	return (i);
}

static char	**fill(char **str, char *s, char ch, int len)
{
	int	i;
	int	g;

	i = 0;
	while (i < len)
	{
		while (*s == ch && *s)
			s++;
		g = word_len(s, ch);
		str[i] = substr(s, 0, g);
		if (!str[i])
			exit(1);
		while (*s != ch && *s)
			s++;
		i++;
	}
	str[i] = NULL;
	return (str);
}

char	**split(char *s, char c)
{
	int		len;
	char	**res;

	if (!s)
		return (NULL);
	len = word_count(s, c);
	res = (char **)calloc(sizeof(char *), (len + 1));
	if (!res)
		return (NULL);
	res = fill(res, s, c, len);
	return (res);
}
