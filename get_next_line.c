/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 00:44:49 by dasalaza          #+#    #+#             */
/*   Updated: 2023/11/03 19:58:05 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_line_file(int fd, char *storage)
{
	char	*buff_datos_leidos;
	int		num_bytes;

	buff_datos_leidos = (char *) malloc ((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff_datos_leidos)
	{
		free(storage);
		return (NULL);
	}
	buff_datos_leidos[0] = '\0';
	num_bytes = 1;
	while (num_bytes > 0 && (!ft_strchr(buff_datos_leidos, '\n')))
	{
		num_bytes = read(fd, buff_datos_leidos, BUFFER_SIZE);
		if (num_bytes == -1)
		{
			free(buff_datos_leidos);
			free(storage);
			return (NULL);
		}
		else
		{
			buff_datos_leidos[num_bytes] = '\0';
			storage = ft_strjoin(storage, buff_datos_leidos);
		}
	}
	free(buff_datos_leidos);
	return (storage);
}

char	*get_next_line(int fd)
{
	static char	*storage = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!storage || (storage && !ft_strchr(storage, '\n')))
		storage = ft_read_line_file(fd, storage);
	if (!storage)
		return (NULL);
	line = ft_extract_line(storage);
	if (!line)
	{
		free(storage);
		storage = NULL;
		return (NULL);
	}
	storage = ft_update_storage(storage);
	return (line);
}
/*
int	main()
{
	int		fd;
	char	*result;

	result = NULL;
	fd = open("fd.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("error opened file");
		return (1);
	}
	printf("%s\n", get_next_line(fd));
	close(fd);
	return (0);
}
*/
