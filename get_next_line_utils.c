/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcuenca <dcuenca@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 11:16:01 by dcuenca           #+#    #+#             */
/*   Updated: 2025/10/30 19:49:43 by dcuenca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *buffer)
{
	char	*str;
	size_t	i;
	size_t	len1;
	size_t	len2;

	i = 0;
	len1 = 0;
	len2 = 0;
	if (s1 != NULL)
		len1 = ft_strlen(s1);
	if (buffer != NULL)
		len2 = ft_strlen(buffer);
	str = malloc(len1 + len2 + 1);
	if (str == NULL)
		return (NULL);
	while (s1 != NULL && *s1 != '\0')
		str[i++] = *s1++;
	while (buffer && *buffer)
		str[i++] = *buffer++;
	str[i] = '\0';
	return (str);
}
/*
char	*ft_strjoin(char const *s1, char const *buffer)
{
	char	*str;
	size_t	i;
	size_t	len1;
	size_t	len2;

	i = 0;
	len1 = 0;
	len2 = 0;
	if (s1 != NULL)
		len1 = ft_strlen(s1);
	if (buffer != NULL)
		len2 = ft_strlen(buffer);
	str = malloc(len1 + len2 + 1);
	if (str == NULL)
		return (NULL);
	while (s1 != NULL && *s1 != '\0')
		str[i++] = *s1++;
	while (buffer && *buffer)
		str[i++] = *buffer++;
	str[i] = '\0';
	return (str);
}*/

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	if (*s == c)
		return ((char *)s);
	return (0);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(const char *s)
{
	char	*pointer;
	size_t	i;

	i = 0;
	pointer = malloc(ft_strlen(s) + 1);
	if (pointer == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		pointer[i] = s[i];
		i++;
	}
	pointer[i] = '\0';
	return (pointer);
}
