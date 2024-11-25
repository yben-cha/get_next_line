#include "get_next_line.h"

unsigned long	verfier_in_midlle(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (i);
}

int	handle_after(char **after, char **result)
{
	int		i;
	char	*curent;

	*result = NULL;
	i = 0;
	if (*after)
	{
		while ((*after)[i])
		{
			if ((*after)[i] == '\n')
			{
				(*after)[i++] = '\0';
				(*result) = ft_strdup(*after);
				curent = (*after);
				(*after) = ft_strdup((*after) + i);
				free(curent);
				return (1);
			}
			i++;
		}
		*result = ft_strdup(*after);
		free(*after);
		*after = NULL;
	}
	return (0);
}

void	join_and_free(char **result, char *tmp)
{
	char	*curent;

	if (ft_strlen(tmp) == verfier_in_midlle(tmp))
	{
		curent = *result;
		*result = ft_strjoin(*result, tmp);
		free(curent);
	}
}

int	result_and_after(char **result, char **after, char *tmp)
{
	int		wordp;
	char	*curent;
	char	*before;

	before = NULL;
	if (!(ft_strlen(tmp) == verfier_in_midlle(tmp)))
	{
		wordp = verfier_in_midlle(tmp);
		before = malloc(wordp + 2);
		ft_strncpy(before, tmp, wordp + 1);
		before[wordp + 1] = '\0';
		wordp = ft_strlen(tmp) - verfier_in_midlle(tmp);
		curent = *result;
		*result = ft_strjoin(*result, before);
		if (!(verfier_in_midlle(tmp) == (ft_strlen(tmp) - 1)))
		{
			*after = malloc(wordp);
			ft_strncpy(*after, tmp + verfier_in_midlle(tmp) + 1, wordp);
			(*after)[wordp] = '\0';
		}
		free(before);
		free(curent);
		return (1);
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*after;
	char		tmp[BUFFER_SIZE + 1];
	char		*result;
	ssize_t		num;

	num = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (handle_after(&after, &result))
		return (result);
	while (num)
	{
		num = read(fd, tmp, BUFFER_SIZE);
		if (num <= 0)
			return (result);
		tmp[num] = '\0';
		join_and_free(&result, tmp);
		if (result_and_after(&result, &after, tmp))
			return (result);
	}
	return (result);
}
#include<stdio.h>
#include<fcntl.h>
int main()
{
	int fd = open("test1.text",O_RDONLY);
	int i=0;
	char *curent;
	while(i <9)
	{
		curent =get_next_line(fd);
		printf("%s \n",curent);
		free(curent);
		i++;
	}
	close(fd);

}
