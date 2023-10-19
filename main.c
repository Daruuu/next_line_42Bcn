/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 07:04:50 by dasalaza          #+#    #+#             */
/*   Updated: 2023/10/19 13:04:41 by dasalaza         ###   ########.fr       */
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

// test STRCHR_BOOLEAN

int main()
{
	char str_buff1[] = "this is a\\0string";
	char str_buff2[] = "no null character";

	printf("Testing ft_strchr_boolean:\n");
	printf("str_buff1: %s - Result: %d\n", str_buff1, ft_strchr_boolean(str_buff1));
	printf("str_buff2: %s - Result: %d\n", str_buff2, ft_strchr_boolean(str_buff2));

	return (0);
}

/*
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
*/

