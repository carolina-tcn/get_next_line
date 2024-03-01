/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctacconi <ctacconi@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 17:52:33 by ctacconi          #+#    #+#             */
/*   Updated: 2024/03/01 23:23:41 by ctacconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
/*char	*ft_strdup(const char *s1)
{
	char	*ptr_dst;
	size_t	i;

	ptr_dst = (char *)malloc(ft_strlen(s1) + 1);
	if (!ptr_dst)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		ptr_dst[i] = s1[i];
		i++;
	}
	ptr_dst[i] = '\0';
	return (ptr_dst);
}*/

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}
size_t	ft_strlen_whit_n_too(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
	{
		i++;
	}
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0' && s[i] != (char)c)
		i++;
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	return (0);
}


char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char			*ptr;
	unsigned int	i;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		len = 0;
	else if (ft_strlen(&s[start]) < len)
		len = ft_strlen(&s[start]);
	ptr = malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < len && s[start] != '\0')
	{
		ptr[i] = s[start];
		i++;
		start++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ptr;
	size_t	i;
	size_t	j;

	if (!s1)
	{
		s1 = malloc(sizeof(char) * 1);
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	ptr = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!ptr)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		ptr[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		ptr[i++] = s2[j++];
	}
	ptr[i] = '\0';
	return (ptr);
}

//strchr, strdup, strlen, substr, strjoin

//Con strchr encontrar la aparicion de \n

//Con strjoin voy concatenando con cada read

//	Con strdup reservo memoria para copiar una string

//Con substr creo una substr a partir de una string entre \n y \n
