/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 17:11:31 by sbouheni          #+#    #+#             */
/*   Updated: 2023/01/21 01:52:14 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;
	char		buffer[BUFFER_SIZE + 1];
	int			read_state;

	if (fd >= 0)
	{
		read_state = 1;
		while (read_state > 0)
		{
			read_state = read(fd, buffer, BUFFER_SIZE);
			stash = malloc(sizeof(char)* read_state + 1);
			stash = join_strings(stash, buffer);
			if (find_cr(stash))
			{
				line = extract_line(stash);
				return (line);
			}
		}
	}
	return (NULL);
}

char	*extract_line(char *str)
{
	char	*line;
	int		i;

	i = 0;
	while (str[i] != '\n')
		i++;
	line = malloc(sizeof(char) * i + 1);
	i = 0;
	while (str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\n';
	line[i + 1] = '\0';
	return (line);
}
