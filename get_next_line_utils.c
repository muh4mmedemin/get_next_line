#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		b;
	char	*newstr;
	int		totalstr;

	b = 0;
	i = 0;
	totalstr = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	newstr = malloc(totalstr + 1);
	if (newstr == NULL)
		return (NULL);
	while (s1[i])
	{
		newstr[i] = s1[i];
		i++;
	}
	while (s2[b])
	{
		newstr[i] = s2[b];
		b++;
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}

char	*ft_strdup(const char *s)
{
	int		srcsize;
	char	*newstr;

	srcsize = 0;
	while (s[srcsize])
		srcsize++;
	newstr = malloc(srcsize + 1);
	if (newstr == NULL)
		return (NULL);
	srcsize = 0;
	while (s[srcsize])
	{
		newstr[srcsize] = s[srcsize];
		srcsize++;
	}
	newstr[srcsize] = '\0';
	return (newstr);
}
