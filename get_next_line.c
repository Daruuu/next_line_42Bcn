/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 00:44:49 by dasalaza          #+#    #+#             */
/*   Updated: 2023/11/01 19:40:09 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
/*
	 * -1: error -> return NULL
	 * 0: ha terminado de leer el archivo.
	 * ha leido BUFFER_SIZE caracteres
	*/
char	*ft_read_line_file(int fd, char *storage)
{
	char	*buff_datos_leidos;
	int		num_bytes;

	buff_datos_leidos = (char *) malloc ((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff_datos_leidos){
		free(storage);
		return (NULL);
	}
	buff_datos_leidos[0] = '\0';
	num_bytes = 1;
/* si no se cumple ft_strchr() == 0
 * si se cumple ft_strchr() == distinto de 0 */
	while (num_bytes > 0 && (!ft_strchr(buff_datos_leidos, '\n')))
	{
		/* read(de donde leo, almaceno lo que leo, cantidad por lectura)*/
		//printf("num bytes before read: %i\n", num_bytes);
		//printf("bufsize: %i\n", BUFFER_SIZE);
		num_bytes = read(fd, buff_datos_leidos, BUFFER_SIZE);
		//printf("num bytes: %i\n", num_bytes);
		//printf("buffer: %s\n", buff_datos_leidos);
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
			//printf("storage: %s\n", storage);
		}
	}
	free(buff_datos_leidos);
	//printf("storage: %s\n", storage);
	return (storage);
}

//  BUFFER = '\0sjdah\njdash'
//  BUFFER = "hola que tal\0"
//  BUFFER = "como estas\0al\0"

char	*get_next_line(int fd)
{
	static char	*storage = NULL;
	char		*line;

	if(fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if(!storage ||  (storage && !ft_strchr(storage, '\n')))
		storage = ft_read_line_file(fd, storage);
	//printf("%s\n", storage);
	if(!storage)
		return (NULL);
	//line = NULL;
	line = ft_extract_line(storage);
	if(!line)
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
