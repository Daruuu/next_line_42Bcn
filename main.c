/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 07:04:50 by dasalaza          #+#    #+#             */
/*   Updated: 2023/10/30 19:37:55 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main()
{
	int		fd;
	char	*result;

	fd = open("fd.txt", O_RDONLY);
	if (fd == -1)
		return (0);
	printf("%s", get_next_line(fd));
	while ()
	{

	}
	close(fd);
	return (0);
}

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
/*
int main()
{
	char str_buff01[20] = {'t', 'h', 'i',  's', ' ','i', 's', ' ','a', '\0', ' ','s', 't', 'r', 'i', 'n', 'g'};

	printf("Testing ft_strchr_boolean:\n");
	printf("str_buff01: %s - Result: %d\n", str_buff01, ft_strchr_boolean(str_buff01));

	return (0);
}
*/

/*
int	main()
{
	char	*str;
	char	c;

	c = 'w';
	str = "hello world!";
	//ft_strchr(str, c);
	printf("%s\n", ft_strchr(str, c));

	return (0);
}
*/
