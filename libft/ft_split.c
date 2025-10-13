#include "libft.h"

static int is_sep(char s, char c)
{
	if (s == c)
		return (1);
	return (0);
}

static int count_words(char *s, char c)
{
	int i;
	int co;
	co = 0;
	i = 0;
	while (s[i])
	{
			while (s[i] && is_sep(s[i], c))
				i++;
			if (s[i])
			{
				co++;
				while (s[i] && !is_sep(s[i], c))
					i++;
			}
			
	}
	return (co);
}

static char *fill_it(char const *s, char c, int *index)
{
	size_t len;
	char *word;

	len = 0;
	while (s[*index + len] && !is_sep(s[*index + len], c))
		len++;
	word = malloc(len + 1);
	if (!word)
		return (NULL);
	ft_memcpy(word, s + *index, len);
	word[len] = '\0';
	*index += len;
	return (word);
}

char **ft_split(char const *s, char c)
{
	int i;
	char **arr;
	int words;
	int index;

	words = count_words((char *)s, c);
	arr = malloc(sizeof(char *) * (words + 1));
	if (!arr)
		return (NULL);
	arr[words] = NULL;
	i = 0;
	index = 0;
	while (i < words)
	{
		while (is_sep(s[index], c) && s[index])
			index++;
		arr[i] = fill_it(s, c, &index);
		if (!arr[i])
		{
			while (i > 0)
				free(arr[--i]);
			free(arr);
			return (NULL);
		}
		i++;
	}
	return (arr);
}
