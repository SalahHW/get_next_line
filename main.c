/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 19:08:10 by sbouheni          #+#    #+#             */
/*   Updated: 2023/02/22 14:05:04 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.c"
#include "get_next_line.h"
#include "get_next_line_utils.c"
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int	main(void)
{
	int	fd;
	char *toto;
	fd = open("./textfiles/lines_around_10.txt", O_RDONLY);
	toto = get_next_line(fd);
	while (toto)
	{
		printf("%p\n", toto);
		free(toto);
		toto = get_next_line(fd);
	}
	return (0);
}
