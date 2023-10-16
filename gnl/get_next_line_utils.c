/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daoliver <daoliver@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 16:14:54 by daoliver          #+#    #+#             */
/*   Updated: 2023/10/16 14:31:22 by daoliver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	unsigned int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	if (s[i] == '\0')
		return (NULL);
	return (&s[i]);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	longitud;
	size_t	i;

	i = 0;
	longitud = ft_strlen(s);
	if (!s)
		return (NULL);
	if (start > longitud)
	{
		substr = malloc(sizeof(char) * (1));
		if (!substr)
			return (NULL);
		substr[0] = '\0';
		return (substr);
	}
	if (start - len < len)
		len = longitud - start;
	substr = (char *)malloc(len + 1);
	if (!substr)
		return (NULL);
	while (i++ < start)
		s++;
	ft_strlcpy(substr, s, len + 1);
	return (substr);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new_str;
	size_t	i;
	size_t	j;

	if (!s1)
	{
		s1 = malloc(1 * sizeof(char));
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	new_str = malloc(sizeof(char) * ((ft_strlen(s1) + ft_strlen(s2)) + 1));
	if (!s1)
		return (free_storage(s1));
	i = -1;
	j = 0;
	if (s1)
		while (s1[++i] != '\0')
			new_str[i] = s1[i];
	while (s2[j] != '\0')
		new_str[i++] = s2[j++];
	new_str[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	free(s1);
	return (new_str);
}

size_t	ft_strlcpy(char *dest, char *src, size_t destsize)
{
	unsigned int	tmp;
	unsigned int	aux;

	tmp = 0;
	aux = 0;
	while (src[tmp] != '\0')
		tmp++;
	if (destsize != '\0')
	{
		while (src[aux] != '\0' && aux < (destsize - 1))
		{
			dest[aux] = src[aux];
			aux++;
		}
		dest[aux] = '\0';
	}
	return (tmp);
}
