
#include "get_next_line.h"

	//Get my line
char	*get_line(t_list *list)
{
	int		str_len;
	char	*next_str;

	if (NULL == list)
		return (NULL);

	//Count CHAR till '\n'
	//So i know how much malloc
	str_len = len_to_newline(list);
	next_str = malloc(str_len + 1);
	if (NULL == next_str)
		return (NULL);

	//Copy string in buffer and return it
	copy_str(list, next_str);
	return (next_str);
}

	//Append one Node to the end of LIST
void	append(t_list **list, char *buf)
{
	t_list	*new_node;
	t_list	*last_node;

	last_node = find_last_node(*list);
	new_node = malloc(sizeof(t_list));
	if (NULL == new_node)
		return ;
	// If list is empty
	// If null == *lis
	if (NULL == last_node)
		*list = new_node;
	else
		last_node->next = new_node;

	new_node->str_buf = buf;
	new_node->next = NULL;
}

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
