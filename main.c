/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 20:27:55 by dasalaza          #+#    #+#             */
/*   Updated: 2023/11/08 23:04:23 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	main()
{
	int		fd;
	char	*result;

	result = NULL;
	fd = open("fda.txt", O_RDONLY);
	//fd = open("fd.txt", O_RDONLY);
	//fd = open("fd2.txt", O_RDONLY);
	//fd = open("fd3.txt", O_RDONLY);
	//fd = open("fd4.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("error opened file");
		return (1);
	}

	while ((result = get_next_line(fd)) != NULL)
	{
		printf("contenido de la linea: |%s|\n", result);
		free(result);
	}
	close(fd);
	return (0);
}

/*
int	main()
{
	int		fd;
	int		fd2;
	int		fd3;
	char	*result;

	result = NULL;
	fd = open("fd.txt", O_RDONLY);
	fd2 = open("fd2.txt", O_RDONLY);
	fd3 = open("fd3.txt", O_RDONLY);

	printf("file 1 line 1: %s\n", get_next_line(fd));
	printf("file 1 line 2: %s\n", get_next_line(fd));
	printf("file 1 line 3: %s\n", get_next_line(fd));
	printf("-------------------------\n");
	printf("file 2 line 1: %s\n", get_next_line(fd2));
	printf("file 2 line 2: %s\n", get_next_line(fd2));
	printf("-------------------------\n");
	printf("file 3 line 1: %s\n", get_next_line(fd3));
	close(fd);
	close(fd2);

	return (0);
}
*/
