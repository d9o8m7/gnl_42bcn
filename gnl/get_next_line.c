/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daoliver <daoliver@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 16:12:12 by daoliver          #+#    #+#             */
/*   Updated: 2023/10/20 13:49:11 by daoliver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_storage(int fd, char *storage)
{
	char	*tmp_storage;
	int		read_bytes;

	read_bytes = 1;
	tmp_storage = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!tmp_storage)
		return (NULL);
	tmp_storage[0] = '\0';
	while (read_bytes > 0 && !(ft_strchr(tmp_storage, '\n')))
	{
		read_bytes = read(fd, tmp_storage, BUFFER_SIZE);
		if (read_bytes > 0)
		{
			tmp_storage[read_bytes] = '\0';
			storage = ft_strjoin(storage, tmp_storage);
		}
	}
	free(tmp_storage);
	if (read_bytes == -1)
		return (free_storage(storage));
	return (storage);
}

char	*extract_storage(char *storage)
{
	char	*aux;
	char	*line;
	int		len;

	aux = ft_strchr(storage, '\n');
	len = (aux - storage) + 1;
	line = ft_substr(storage, 0, len);
	if (!line)
		return (NULL);
	return (line);
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
