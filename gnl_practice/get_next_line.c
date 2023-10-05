
#include "get_next_line.h"

void	create_list(t_list **list, int fd)
{
	//Necessary to place \0 -> "string\0"
	int		char_read;
	char	*buf;

	//Scan line if '\n' present
	while (!found_newline(*list))
	{
		buf = malloc(BUFFER_SIZE + 1);
		if (NULL == buf)
			return ;
									//10
		char_read = read(fd, buf, BUFFER_SIZE);
		//		EOF
		if (!char_read)
		{
			free(buf);
			return ;
		}
		buf[char_read] = '\0';
		// Apend the node
		append(list, buf);
	}
}
	// Take fd
	// Give back next_string

char	*get_next_line(int fd)
{
	static t_list	*storage = NULL;
	char			*line;

	// fd only positives | read gives -1 if some problem on reading
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &next_line, 0) < 0)
		return (NULL);

	// Create List till '\n'
	create_list(&list, fd);

	if (list == NULL)
		return (NULL);

	// Fetch the line from the list
	next_line = get_line(list);

	//
	polish_list(&list);
	return (next_line);
}
