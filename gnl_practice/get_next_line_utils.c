#include "get_next_line.h"

int	len_to_newline(t_list *list)
{
	int	i;
	int	len;

	if (NULL = list)
		return (0);
	len = 0;
	//list != NULL
	while (list)
	{
		i = 0;
		while (list->str_buf[i])
		{
			if (list->str_buf[i] == '\n')
			{
				++len;
				return (len);
			}
			++i;
			++len;
		}
		list = list->next;
	}
	return (len);
}
