/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 00:44:49 by dasalaza          #+#    #+#             */
/*   Updated: 2023/10/08 09:24:03 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * leemos de un file descriptor FD
 * funcion para recorrer una linea y mientras no encuentres un \n no se creara 
 * un malloc de ese size() 
 * cada vez que lleges a un \n habra que imprimir la linea.
 *
 * importante es que read retorna un -1 si hay un error, 
 * si se llega al final de linea retorna un 0 
 * mientras no llegue al final del archivo, regresara los caracteres leidos
 * si hay error return NULl
 *
 */

#include "get_next_line.h"
/*
 * get length of string
*/
int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}
/*
 * funcion que lee una linea del fd y retorna esa linea a la funcion principal
 *
 * Ten en cuenta que la línea devuelta debe terminar con el caracter \n,
 * excepto si se ha llegado al final del archivo y esté termina con un caracter \0.
*/

char    *ft_readLine(int fd)
{
	char	readLine;
	char	*line_read;
	char	*buffer;
	int		i;

	if (fd == -1)
		return (NULL);

	line_read = (char *) malloc(BUFFER_SIZE);
    // leer cada character
	buffer = (char *) malloc(1);

	if (!line_read || !buffer)
	{
		free(line_read);
		free(buffer);
		return (NULL);
	}
//	while (readLine = (read(fd, buffer, 1)) != -1)
    readLine = (read(fd, buffer, 1)) != -1;
    while (readLine)
	{
		if (*buffer == '\n')
		{

		}
        readLine = (read(fd, buffer, 1)) != -1;
    }

	/*
	read(fd,buffer , BUFFER_SIZE);
	if ( == -1)
		return (-1);
	i = 0;
	while (read (fd,buffer , BUFFER_SIZE) != '\n')
	{
		str[i] =(char *) buffer;
		buffer++;
		i++;
	}
	*/

	return (0);
}
/*
 * main function
*/

char	*get_next_line(int fd)
{
	char	eoline;
	char	eofile;
	char	buffer[1000];
	char	**readfile;
	
	eoline = '\n';
	eofile = '\0';
	return (0);
}
/*
int	main()
{
	int		fd;

	fd = open("fd.txt", O_RDONLY);
	if (fd == -1)
		return (1);

	printf("fd = %d\n", fd);
	//get_next_line(openFd);
	//close(fd);

	return (0);
}
*/
/*
int main(int argc, char const *argv[])
{
    int fileDescriptor;
    char buff[1000];

    if ((fileDescriptor = open("fd.txt", O_RDONLY)) == -1)
    {
        printf("File Open Failed\n");
        exit(0);
    } else {
		printf("File Opened Successfully\n");
		printf("File Descriptor: %d\n", fileDescriptor);
    }
}*/
