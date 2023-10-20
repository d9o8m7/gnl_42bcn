/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daoliver <daoliver@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:17:28 by daoliver          #+#    #+#             */
/*   Updated: 2023/10/06 15:27:30 by daoliver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 50
# endif

# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>

/* PROTOTYPE */

char	*get_next_line(int fd);

/* ADITIONAL FUNCTIONS */

size_t	ft_strlen(char *s);
size_t	ft_strlcpy(char *dest, char *src, size_t destsize);
char	*ft_strchr(char *s, int c);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strjoin(char *s1, char *s2);

/* MAIN FUNCTIONS */

char	*read_storage(int fd, char *storage);
char	*extract_storage(char *storage);
char	*clean_storage(char *storage);
char	*free_storage(char *storage);
#endif
