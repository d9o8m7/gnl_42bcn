/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daoliver <daoliver@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 16:14:54 by daoliver          #+#    #+#             */
/*   Updated: 2023/10/05 13:19:09 by daoliver         ###   ########.fr       */
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
	size_t	long;
	size_t	i;

	i = 0;
	long = ft_strlen(s);
	if (!s)
		return (NULL);
	if (start > long)
	{
		substr = malloc(sizeof(char) * (1));
		if (!substr)
			return (NULL);
		substr[0] = '\0';
		return (substr);
	}
	if (start - len < len)
		len = long - start;
	substr = (char *)malloc(len + 1);
	if (!substr)
		return (NULL);
	while (i++ < start)
		s++;
	ft_strlcpy(substr, s, len + 1);
	return (substr);
}
