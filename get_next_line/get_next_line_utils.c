/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taya <taya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 03:56:30 by taya              #+#    #+#             */
/*   Updated: 2024/11/13 15:53:51 by taya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *str, int c)
{
	size_t	i;

	i = 0;
	while (str[i] && str[i] != (char)c)
		i++;
	if (str[i] == (char)c)
		return ((char *)(str + i));
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	int		len;
	int		i;

	if (!s1) 
		s1 = "";
	if (!s2) 
		s2 = "";
	len = ft_strlen(s1) + ft_strlen(s2);
	s3 = malloc((len + 1) * sizeof(char));
	if (!s3)
		return (NULL);
	i = 0;
	while (*s1)
	{
		s3[i++] = *s1++;
	}
	while (*s2)
	{
		s3[i++] = *s2++;
	}
	s3[i] = '\0';
	return (s3);
}

char	*ft_strdup(const char *s)
{
	char	*d;
	int		len;
	int		i;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	d = malloc((len + 1) * sizeof(char));
	i = 0;
	if (!d)
		return (NULL);
	while (i < len)
	{
		d[i] = s[i];
		i++;
	}
	d[i] = '\0';
	return (d);
}

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return(0);
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strncpy(char *dest, const char *src, int len)
{
	int	i;

	i = 0;
	if (!dest || !src)
		return (NULL);
	while (i < len && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
