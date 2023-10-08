/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 07:04:50 by dasalaza          #+#    #+#             */
/*   Updated: 2023/10/08 07:12:43 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
