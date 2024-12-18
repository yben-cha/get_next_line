/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yben-cha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 01:02:37 by yben-cha          #+#    #+#             */
/*   Updated: 2024/11/26 01:05:25 by yben-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	char	*curent;
	char	c;

	if (*after)
	{
		if (verfier_in_midlle(*after) != ft_strlen(*after))
		{
			c = (*after)[verfier_in_midlle(*after) + 1];
			(*after)[verfier_in_midlle(*after) + 1] = '\0';
			(*result) = ft_strdup(*after);
			(*after)[verfier_in_midlle(*after) + 1] = c;
			curent = (*after);
			(*after) = ft_strdup(((*after) + verfier_in_midlle(*after) + 1));
			free(curent);
			return (1);
		}
		if (**after)
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
			(*after)[wordp - 1] = '\0';
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

	result = NULL;
	num = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (handle_after(&after, &result))
		return (result);
	while (num)
	{
		num = read(fd, tmp, BUFFER_SIZE);
		if (num == 0)
			return (result);
		if (num < 0)
			return (NULL);
		tmp[num] = '\0';
		join_and_free(&result, tmp);
		if (result_and_after(&result, &after, tmp))
			return (result);
	}
	return (result);
}
