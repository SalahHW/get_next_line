/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 19:08:10 by sbouheni          #+#    #+#             */
/*   Updated: 2023/01/23 19:08:13 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.c"
#include "get_next_line.h"
#include "get_next_line_utils.c"
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int	main(void)
{
	int	fd;

	fd = open("textfiles/only_nl.txt", O_RDONLY);
	if (fd >= 0)
	{
		printf("- %s", get_next_line(fd));
		printf("- %s", get_next_line(fd));
		printf("- %s", get_next_line(fd));
		printf("- %s", get_next_line(fd));
		printf("- %s", get_next_line(fd));
		printf("- %s", get_next_line(fd));
		printf("- %s", get_next_line(fd));
		printf("- %s", get_next_line(fd));
		printf("- %s", get_next_line(fd));
		printf("- %s", get_next_line(fd));
		close(fd);
	}
	else
	{
		printf("%s\n", strerror(errno));
	}
	return (0);
}
