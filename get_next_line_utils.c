/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 03:27:29 by sbouheni          #+#    #+#             */
/*   Updated: 2023/02/16 19:25:00 by sbouheni         ###   ########.fr       */
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

char	*join_strings(char **dst, char *src)
{
	int		dst_len;
	int		src_len;
	char	*new_string;
	char	*p;
	char	*dst_ptr;

	if (!dst || !src)
		return (NULL);
	dst_len = ft_strlen(*dst);
	src_len = ft_strlen(src);
	new_string = malloc(dst_len + src_len + 1);
	if (!new_string)
		return (ft_free(dst));
	p = new_string;
	dst_ptr = *dst;
	while (*dst_ptr)
		*p++ = *dst_ptr++;
	while (*src)
		*p++ = *src++;
	*p = '\0';
	ft_free(dst);
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

char	*ft_free(char **str)
{
	if (str && *str)
	{
		free(*str);
		*str = NULL;
	}
	return (NULL);
}
