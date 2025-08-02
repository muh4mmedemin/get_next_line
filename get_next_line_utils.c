#include "get_next_line.h"
#include <stdlib.h>

size_t	ft_strlen(const char *s)
{
	size_t i = 0;
	while (s && s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	len1 = ft_strlen(s1);
	size_t	len2 = ft_strlen(s2);
	char	*res = malloc(len1 + len2 + 1);
	size_t	i = 0, j = 0;
	if (!res)
		return (NULL);
	while (s1 && s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	while (s2 && s2[j])
		res[i++] = s2[j++];
	res[i] = '\0';
	free(s1);
	return (res);
}

char	*ft_strdup(const char *s)
{
	size_t	len = ft_strlen(s);
	char	*copy = malloc(len + 1);
	size_t	i;
	if (!copy)
		return (NULL);
	for (i = 0; i < len; i++)
		copy[i] = s[i];
	copy[i] = '\0';
	return (copy);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return NULL;
	while (*s)
	{
		if (*s == (char)c)
			return (char *)s;
		s++;
	}
	if (c == '\0')
		return (char *)s;
	return NULL;
}

