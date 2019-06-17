/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatrouf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 23:18:32 by mmatrouf          #+#    #+#             */
/*   Updated: 2019/06/04 23:39:04 by mmatrouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	char	*line;
	char	*line2;
	int		fd;
	int		r;
	int		i;

	i = 0;
	fd = open(argv[1], O_RDONLY);
	while ((r = get_next_line(fd, &line)) > 0)
	{
		printf("line %d is : %s\n", i, line);
		free(line);
		i++;
	}
	printf("//return value id : %d//\n", r);
	return (0);
}
