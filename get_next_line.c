/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcuenca <dcuenca@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 23:57:54 by dcuenca           #+#    #+#             */
/*   Updated: 2025/10/31 00:03:23 by dcuenca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*update_stash(char *stash)
{
	int		i;
	int		j;
	char	*stash_rema;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	stash_rema = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (stash_rema == NULL)
	{
		free(stash);
		return (NULL);
	}
	j = 0;
	while (stash[i] != '\0')
		stash_rema[j++] = stash[i++];
	stash_rema[j] = '\0';
	free(stash);
	stash = NULL;
	return (stash_rema);
}

char	*extract_line(char *stash)
{
	int		i;
	char	*line;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	line = (char *)malloc((i + 1) * sizeof(char));
	if (line == NULL)
		return (NULL);
	i = 0;
	while (stash [i] && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*new_line(int fd, char *stash, char *tmp)
{
	ssize_t	num_bytes;

	while (ft_strchr(stash, '\n') == NULL)
	{
		num_bytes = read(fd, stash, BUFFER_SIZE);
		if (num_bytes < 0)
		{
			free (tmp);
			tmp = NULL;
			return (NULL);
		}
		if (num_bytes == 0)
			return (tmp);
		stash[num_bytes] = '\0';
		tmp = ft_strjoin(tmp, stash);
		if (tmp == NULL)
		{
			free (tmp);
			return (NULL);
		}
	}
	return (tmp);
}

char	*ft_read_aux(int fd, char *stash)
{
	char	*tmp;

	tmp = NULL;
	if (stash == NULL)
	{
		stash = (char *)malloc(BUFFER_SIZE + 1);
		if (stash == NULL)
			return (NULL);
		ft_memset(stash, 0, BUFFER_SIZE + 1);
	}
	else
	{
		tmp = ft_strjoin(tmp, stash);
		if (tmp == NULL)
			return (NULL);
	}
	tmp = new_line(fd, stash, tmp);
	free (stash);
	stash = NULL;
	if (tmp == NULL)
		return (NULL);
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	stash = ft_read_aux(fd, stash);
	if (stash == NULL || *stash == '\0')
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	line = extract_line(stash);
	stash = update_stash(stash);
	if (!stash)
		free(stash);
	return (line);
}
