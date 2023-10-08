/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 00:44:49 by dasalaza          #+#    #+#             */
/*   Updated: 2023/10/08 06:27:00 by dasalaza         ###   ########.fr       */
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
 * get leng of string
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
 * concate 2 str creating a malloc
*/
char	*ft_strjoin(char *str1, char *str2)
{
	char	*new_ptr;
	int		i;

	if (!str1 && !str2)
		return (0);
	new_ptr = malloc (sizeof(char) *(ft_strlen(str1) + ft_strlen(str2) + 1));
	if (!new_ptr)
		free(new_ptr);
		return (NULL);
	i = 0;
	while (i < ft_strlen(str1) + ft_strlen(str2))
	{
		if (i < ft_strlen(str1))
			new_ptr[i] = str1[i];
		else
			new_ptr[i] = str2[i - ft_strlen(str1)];
		i++;
	}
	new_ptr[i] = '\0';
	return (new_ptr);
}

/*
 * function to read a line
*/
char	*ft_readLine(int fd)
{
	char	*readLine;
	char	*str;
	char	*buffer;
	int		i;

	if (fd == -1)
		return (NULL);
	*readLine = 1;




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
}
