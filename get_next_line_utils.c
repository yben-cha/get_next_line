#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	const char	*sr;
	char		*ds;

	if (!dst && !src)
		return (NULL);
	sr = src;
	ds = dst;
	while (n--)
		*(ds++) = *(sr++);
	return (dst);
}

char	*ft_strdup(const char *s)
{
	char	*result;
	size_t	size;

	size = ft_strlen(s) + 1;
	result = malloc(size);
	if (result == NULL)
		return (NULL);
	ft_memcpy(result, s, size);
	return (result);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*r;
	char	*p;

	if (!s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	r = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (r == NULL)
		return (NULL);
	p = r;
	while (*s1)
		*(p++) = *(s1++);
	while (*s2)
		*(p++) = *(s2++);
	*p = '\0';
	return (r);
}

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		++i;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}
