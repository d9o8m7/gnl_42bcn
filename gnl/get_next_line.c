/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daoliver <daoliver@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 16:12:12 by daoliver          #+#    #+#             */
/*   Updated: 2023/10/06 16:04:07 by daoliver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_storage(int fd, char *storage)
{
}

char	*extract_storage(char *storage)
{
}

char	*clean_storage(char *storage)
{
	char	*new_storage;
	char	*character;
	int		len;

	character = ft_strchr(storage, '\n');
	if (!character)
	{
		new_storage = NULL;
		return (free_storage(storage));
	}
	len = (character - storage) + 1;
	if (storage[len] == '\0')
		return (free_storage(storage));
	new_storage = ft_substr(storage, len, ft_strlen(storage) - len);
	free_storage(storage);
	if (!new_storage)
		return (NULL);
	return (new_storage);
}

char	*free_storage(char *storage)
{
	free(storage);
	storage = NULL;
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*storage = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	storage = read_storage(fd, storage);
	if (!storage)
		return (NULL);
	line = extract_storage(storage);
	if (!line)
		return (free_storage(storage));
	storage = clean_storage(storage);
	return (line);
}

/*int	main(void)
{
	int		fd;
	char	*p;

	fd = open("alo.txt", O_RDONLY);
	if (!fd)
		return (-1);
	int i = 0;
	while (i++ < 5)
	{
		(p = get_next_line(fd));
		printf ("%s", p);
		free(p);
	}
	close(fd);
	return 0;
}*/
