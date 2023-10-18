/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 07:04:50 by dasalaza          #+#    #+#             */
/*   Updated: 2023/10/18 13:59:01 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
int	main()
{
	char	*str1;
	char	*str2;
	char	*result;

	str1 = "hello";
	str2 = "world!";
	result = ft_strjoin(str1, str2);
	printf("%s\n", result);

	return (0);
}
*/

int main() {

    int     fd;
    char    buffer[1024];
    ssize_t bytes_leidos;

    fd = open("fd.txt", O_RDONLY);
    if (fd == -1)
        printf("Error al abrir el archivo");

    bytes_leidos = read(fd, buffer, sizeof(BUFFER_SIZE));

    if (bytes_leidos == -1) {
        perror("Error al leer el archivo");
        exit(1);
    }

    close(fd);
    printf("Se leyeron %zd bytes: %s\n", bytes_leidos, buffer);

    return 0;
}

