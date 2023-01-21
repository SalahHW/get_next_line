/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 03:27:29 by sbouheni          #+#    #+#             */
/*   Updated: 2023/01/21 01:48:02 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_length(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*join_strings(char *dst, char *src)
{
	int		dst_len;
	int		src_len;
	char	*new_string;
	char	*p;

	dst_len = get_length(dst);
	src_len = get_length(src);
	new_string = malloc(dst_len + src_len + 1);
	if (!new_string)
		return (NULL);
	p = new_string;
	while (*dst)
		*p++ = *dst++;
	while (*src)
		*p++ = *src++;
	*p = '\0';
	return (new_string);
}

char	*find_cr(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
		{
			return ((char *)s + i);
		}
		i++;
	}
	return (NULL);
}
