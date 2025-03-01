#include <stdlib.h>
#include <stdio.h>

int	delim_check(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	string_count(char *str, char *charset)
{
	int	strings;
	int	i;

	i = 0;
	while (str[i])
	{
		while (str[i] && delim_check(str[i], charset))
			i++;
		if (str[i] == '\0')
			break ;
		strings++;
		while (str[i] && !delim_check(str[i], charset))
			i++;
	}
	return (strings);
}

char	**malloc_string(char *str, char *charset, char **array)
{
	int	i;
	int	j;
	int	size;

	i = 0;
	j = 0;
	while(str[i])
	{
		size = 0;
		while (str[i] && delim_check(str[i], charset))
			i++;
		if (str[i] == '\0')
			break ;
		while (str[i] && !delim_check(str[i], charset))
		{
			i++;
			size++;
		}
		array[j] = malloc((size + 1) * (sizeof(char)));
		if (!array)
			return (NULL);
		j++;
	}
	return (array);
}

char **copy_string(char *str, char *charset, char **array)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	while (str[i])
	{
		k = 0;
		while (str[i] && delim_check(str[i], charset))
			i++;
		if (str[i] == '\0')
			break ;
		while (str[i] && !delim_check(str[i], charset))
		{
			array[j][k] = str[i];
			i++;
			k++;
		}
		array[j][k] = '\0';
		j++;
	}
	array[j] = 0;
	return (array);
}

char	**ft_split(char *str, char *charset)
{
	char	**split_array;
	int		count;

	count = string_count(str, charset);
	split_array = malloc((count + 1) * (sizeof(char *)));
	if (!split_array)
		return (NULL);
	split_array = malloc_string(str, charset, split_array);
	split_array = copy_string(str, charset, split_array);
	return (split_array);
}

int	main(void)
{
	char    *str = "ASD  _T Qwert   yuip";
    char    *sep = " _T";
    char    **split;
    int i = 0;
	
	split = ft_split(str, sep);
	while (split[i] != 0)
	{
		printf("%s\n", split[i]);
		i++;
	}	
	return 0;
}
