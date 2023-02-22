/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 03:27:29 by sbouheni          #+#    #+#             */
/*   Updated: 2023/02/22 14:11:15 by sbouheni         ###   ########.fr       */
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
	char	*new_string;
	char	*new_string_ptr;
	char	*dst_ptr;
	char	*src_ptr;

	src_ptr = src;
	dst_ptr = *dst;
	while (*dst_ptr)
		dst_ptr++;
	while (*src_ptr)
		src_ptr++;
	new_string = malloc(sizeof(char) * ((src_ptr - src) + (dst_ptr - *dst) + 1));
	if (!new_string)
	{
		ft_free(dst);
		return (NULL);
	}
	new_string_ptr = new_string;
	dst_ptr = *dst;
	while (*src)
		*new_string_ptr++ = *src++;
	*new_string_ptr = '\0';
	ft_free(dst);
	return (new_string);
}

char	*find_cr(char **str)
{
	char	*str_ptr;

	if (!*str)
		return (NULL);
	str_ptr = *str;
	while (*str_ptr)
	{
		if (*str_ptr == '\n')
			return (str_ptr);
		str_ptr++;
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
