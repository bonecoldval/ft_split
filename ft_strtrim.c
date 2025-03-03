#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void	ft_errorhandle()
{
	size_t len;

	
}

int	delim_check(char c, const char *sep)
{
	int	i;

	i = 0;
	while (sep[i] != '\0')
	{
		if (c == sep[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	trim_len(const char *str, const char *sep)
{
	int		i;
	int		j;
	int		new_len;

	i = 0;
	j = ft_strlen(str) - 1;
	while (str[i] && delim_check(str[i], sep))
		i++;
	while (j > i && delim_check(str[j], sep))
		j--;
	new_len = j - i + 1;
	return (new_len);
}

void	ft_cpystr(char *dest, char const *str, int start, int dest_len)
{
	int	i;
	
	i = 0;
	while (i < dest_len)
	{
		dest[i] = str[start + i];
		i++;
	}
	dest[i] = '\0';
}

char	*ft_strtrim(const char *str, const char *sep)
{
	int		start;
	int		end;
	int		len;
	char	*trimmed_str;
	
	start = 0;
	end = ft_strlen(str) - 1;
	len = trim_len(str, sep);
	trimmed_str = malloc((len + 1) * (sizeof(char)));
	if (!trimmed_str)
		return (NULL);
	while (str[start] && delim_check(str[start], sep))
		start++;
	if (start == ft_strlen(str))
	{
		trimmed_str = malloc(1);
		trimmed_str[0] = '\0';
		return (trimmed_str);
	}
	while (delim_check(str[end], sep))
		end--;
	ft_cpystr(trimmed_str, str, start, len);
	return (trimmed_str);
}

int main()
{
	char str1[] = "!!HELLOWORLD$$";
	char str2[] = "asdHELLOasd ";
	char str3[] = "";

	char *trim1 = ft_strtrim(str1, "!$");
	char *trim2 = ft_strtrim(str2, "asd");
	char *trim3 = ft_strtrim(str3, "asd");

	printf("%s\n", trim1);
	printf("%s\n", trim2);
	printf("%s\n", trim3);
	free(trim1);
	free(trim2);
	free(trim3);
	return 0;
}
