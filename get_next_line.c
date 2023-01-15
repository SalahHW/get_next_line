/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 17:11:31 by sbouheni          #+#    #+#             */
/*   Updated: 2023/01/10 14:24:58 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>

char	*get_next_line(int fd)
{
	int		read_state;
	char	*buffer;
	char	*line_str;

	if (fd < 0)
		return (NULL);
	buffer = malloc(sizeof(char) * BUFFER_SIZE);
	if (!buffer)
		return (NULL);
	read_state = read(fd, buffer, BUFFER_SIZE);
	if (read_state < 0)
	{
		free(buffer);
		return (NULL);
	}
	if (read_state > 0)
		line_str = malloc(sizeof(char) * read_state + 1);
	while (read_state > 0)
	{
		line_str = join_strings(line_str, buffer);
		read_state = read(fd, buffer, BUFFER_SIZE);
	}
	free(buffer);
	return (line_str);
}
