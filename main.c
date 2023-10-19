/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 07:04:50 by dasalaza          #+#    #+#             */
/*   Updated: 2023/10/19 13:53:21 by dasalaza         ###   ########.fr       */
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
	char str_buff01[17] = {'t', 'h', 'i',  's', ' ','i', 's', ' ','a', '\0', ' ','s', 't', 'r', 'i', 'n', 'g'};

//	char str_buff02[12] = {'n','o',' ','n','u','l','l', ' ','c','h','a','r'};
	char	size_buff01;
//	char	size_buff02;
	size_buff01 = sizeof(str_buff01);
//	size_buff02 = sizeof(str_buff02);

	printf("Testing ft_strchr_boolean:\n");
	printf("str_buff01: %s - Result: %d\n", str_buff01, ft_strchr_boolean(str_buff01, size_buff01));
//	printf("str_buff2: %s - Result: %d\n", str_buff02, ft_strchr_boolean(str_buff02, size_buff02));

	return (0);
}
