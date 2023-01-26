/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 17:11:31 by sbouheni          #+#    #+#             */
/*   Updated: 2023/01/26 18:07:21 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;
	char		buffer[BUFFER_SIZE];
	int			read_state;

	line = NULL;
	if (fd >= 0 && BUFFER_SIZE > 0)
	{
		read_state = 1;
		while (read_state > 0)
		{
			if (find_cr(stash))
			{
				line = extract_line(stash);
				stash = keep_remainder(stash) + (0 * ft_free_str(stash));
				return (line);
			}
			read_state = read(fd, buffer, BUFFER_SIZE);
			if (read_state < 0)
			{
				ft_free_str(stash);
				stash = NULL;
				return (NULL);
			}
			if (read_state == 0)
			{
				if (stash)
					line = keep_remainder(stash) + (0 * ft_free_str(stash));
				stash = NULL;
				return (line);
			}
			if (!stash && buffer[0])
			{
				stash = malloc(sizeof(char) * read_state + 1);
				if (!stash)
					return (NULL);
				stash[0] = '\0';
			}
			stash = join_strings(stash, buffer, read_state)
				+ ft_free_str(stash);
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
	line = malloc(sizeof(char) * i + 2);
	if (!line)
		return (NULL);
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

char	*keep_remainder(char *str)
{
	char	*new_stash;
	int		i;

	i = 0;
	new_stash = NULL;
	if (find_cr(str))
	{
		str = find_cr(str);
		str++;
	}
	while (str[i])
		i++;
	if (i > 0)
		new_stash = malloc(sizeof(char) * i + 1);
	if (!new_stash)
		return (NULL);
	i = 0;
	while (str[i])
	{
		new_stash[i] = str[i];
		i++;
	}
	new_stash[i] = '\0';
	return (new_stash);
}
