/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 17:11:31 by sbouheni          #+#    #+#             */
/*   Updated: 2023/02/17 16:12:38 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "stdio.h"

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;
	char		buffer[BUFFER_SIZE + 1];
	int			read_state;

	line = NULL;
	if (fd >= 0 && BUFFER_SIZE > 0)
	{
		read_state = 1;
		while (read_state > 0)
		{
			while (find_cr(stash))
			{
				line = extract_line(&stash);
				stash = keep_remainder(&stash);
				return (line);
			}
			read_state = read(fd, buffer, BUFFER_SIZE);
			if (read_state < 0)
			{
				ft_free(&stash);
				return (NULL);
			}
			buffer[read_state] = '\0';
			if (read_state == 0)
			{
				if (stash)
					line = keep_remainder(&stash);
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
			stash = join_strings(&stash, buffer);
		}
	}
	return (NULL);
}

char	*extract_line(char **stash)
{
	char	*line;
	char	*line_ptr;
	char	*stash_ptr;

	line = NULL;
	stash_ptr = *stash;
	while (*stash_ptr != '\n')
		stash_ptr++;
	line = malloc((sizeof(char) * (stash_ptr - *stash)) + 2);
	if (!line)
		return (ft_free(stash));
	if (*stash)
		stash_ptr = *stash;
	line_ptr = line;
	while (*stash_ptr != '\n')
		*line_ptr++ = *stash_ptr++;
	*line_ptr = '\n';
	*++line_ptr = '\0';
	return (line);
}

char	*keep_remainder(char **stash)
{
	char	*new_stash;
	char	*stash_ptr;
	char	*cr_ptr;
	char	*new_stash_ptr;

	if (find_cr(*stash))
	{
		cr_ptr = find_cr(*stash);
		stash_ptr = find_cr(*stash);
		while (*stash_ptr)
			stash_ptr++;
		new_stash = malloc((sizeof(char) * (stash_ptr - cr_ptr)));
		if (!new_stash)
			return (ft_free(stash));
		new_stash_ptr = new_stash;
		stash_ptr = find_cr(*stash) + 1;
		while (*stash_ptr)
			*new_stash_ptr++ = *stash_ptr++;
		*new_stash_ptr = '\0';
		ft_free(stash);
		return (new_stash);
	}
	else
	{
		return (*stash);
	}
}
