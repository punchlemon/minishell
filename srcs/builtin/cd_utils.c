#include "list.h"
#include "builtin.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		total_len;
	char	*ans;
	int		i;

	total_len = (int)strlen(s1) + (int)strlen(s2) + 1;
	ans = (char *)malloc(sizeof(char) * total_len);
	if (ans == NULL)
		return (NULL);
	i = 0;
	while (*s1)
	{
		ans[i] = *s1;
		s1++;
		i++;
	}
	while (*s2)
	{
		ans[i] = *s2;
		s2++;
		i++;
	}
	ans[i] = '\0';
	return (ans);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ans;
	int		len_mall;
	size_t	i;

	if (len == 0 || (unsigned int)strlen(s) <= start)
		return (strdup("\0"));
	if (strlen(s) - start < len)
	{
		len_mall = (int)strlen(s) - (int)start + 1;
		ans = (char *)malloc(sizeof(char) * (len_mall + 1));
	}
	else
		ans = (char *)malloc(sizeof(char) * (len + 1));
	if (ans == NULL)
		return (NULL);
	i = 0;
	while (s[start + i] && i < len)
	{
		ans[i] = s[start + i];
		i++;
	}
	ans[i] = '\0';
	return (ans);
}

