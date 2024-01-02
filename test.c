/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jajuntti <jajuntti@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 18:15:48 by jajuntti          #+#    #+#             */
/*   Updated: 2023/12/29 18:37:18 by jajuntti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include "libft/libft.h"

int	main(int argc, char *argv[])
{
	int			index;
	long int	result;

	index = 1;
	if (argc < 2)
		return (1);
	while (index < argc)
	{
		result = atol(argv[index]);
		printf("%s becomes: %ld\n", argv[index], result);
		index++;
	}
	printf("Max int + 1 = %d\n", ft_atoi("2147483648"));
	printf("Min int - 1 = %d\n", ft_atoi("-2147483649"));
	printf("(Max int + 1) * 2 = %d\n", ft_atoi("4294967296"));
	return (0);
}