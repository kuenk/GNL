/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcuenca <dcuenca@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 11:16:01 by dcuenca           #+#    #+#             */
/*   Updated: 2025/10/19 11:23:08 by dcuenca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_utils.h"

char    *ft_strjoin(char const *s1, char const *s2)
{
    size_t	len;
    char	*str;
	size_t	i;

	i = 0;
	if(s1 == NULL && s2 == NULL)
		return(NULL);
	len = (ft_strlen(s1) + ft_strlen(s2));
	str = malloc(len + 1);
	if (str == NULL)
		return(NULL);
	while(*s1)
	{
		str[i] = *s1;
		s1++;
		i++;
	}
	while(*s2)
	{
		str[i] = *s2;
		s2++;
		i++;
	}
	str[i] = '\0';
	return(str);
}

char *ft_strchr(const char *s, int c)
{
    while(*s != '\0')
    {
        if(*s == c)
            return((char *)s);
        s++;
    }
    if(*s == c)
        return((char *)s);
    return 0;
}