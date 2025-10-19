/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcuenca <dcuenca@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 11:16:10 by dcuenca           #+#    #+#             */
/*   Updated: 2025/10/19 12:43:40 by dcuenca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*extract_line(char *stash)
{

}

char	*update_stash(char *stash)
{

}

char	*ft_read_aux(int fd, char *stash)
{
	buffer = malloc(BUFFER_SIZE + 1);
		if (buffer == NULL)
			return (NULL);
		bytes_read = 1;
		while(ft_strchr(stash, '\n') == NULL && bytes_read != 0)
		{
			bytes_read = read(fd, buffer, BUFFER_SIZE);
			if (bytes_read == -1)
			{
				free(buffer);
				return (NULL);
			}
			buffer[bytes_read] = '\0';
			stash = ft_strjoin(stash, buffer);
		}
		stash = extract_line(stash);
		stash = update_stash(stash);
		free(buffer); 
}
char	*get_next_line(int fd)
{ 
		static char	*stash;
		char		*line;
		
		if (fd < 0 || BUFFER_SIZE <= 0)
			return (NULL);
		stash = ft_read_aux(fd, stash);
		if(!stash)
			return(NULL);
		line = extract_line(stash)
		if (!line)
		{
			free(stash);
			stash(NULL);
			return(NULL);
		}
		stash = extrac_line(stash);
		return (line);
		
}
