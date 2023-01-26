/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 03:27:29 by sbouheni          #+#    #+#             */
/*   Updated: 2023/01/26 14:15:05 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		i++;
	}
	return (i);
}

char	*join_strings(char *dst, char *src, int src_len)
{
	int		dst_len;
	int 	i;
	char	*new_string;
	char	*p;

	i = 0;
	if (!dst || !src)
		return (NULL);
	dst_len = ft_strlen(dst);
	new_string = malloc(dst_len + src_len + 1);
	if (!new_string)
		return (NULL);
	p = new_string;
	while (*dst)
		*p++ = *dst++;
	while (i++ < src_len)
		*p++ = *src++;
	*p = '\0';
	ft_free_str(dst);
	return (new_string);
}

char	*find_cr(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
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

int	ft_free_str(char *str)
{
	if (str)
	{
		free(str);
		str = NULL;
		return (1);
	}
	else
		return (0);
}
