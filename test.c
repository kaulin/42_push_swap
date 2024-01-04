/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jajuntti <jajuntti@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 18:15:48 by jajuntti          #+#    #+#             */
/*   Updated: 2024/01/04 15:06:23 by jajuntti         ###   ########.fr       */
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
		printf("%s atol becomes: %ld\n", argv[index], result);
		result = ft_atol(argv[index]);
		printf("%s ft_atol becomes: %ld\n", argv[index], result);
		index++;
	}
	/*
	printf("Max int + 1 = %d\n", ft_atoi("2147483648"));
	printf("Min int - 1 = %d\n", ft_atoi("-2147483649"));
	printf("(Max int + 1) * 2 = %d\n", ft_atoi("4294967296"));
	printf("ft_atol '1111a11' = %d\n", (int)ft_atol("1111a11"));
	printf("atol '1111a11' = %d\n", (int)atol("1111a11"));
	printf("ft_atol '99999999999999999999999999' = %ld\n", ft_atol("99999999999999999999999999"));
	printf("atol '99999999999999999999999999' = %ld\n", atol("99999999999999999999999999"));
	*/
	return (0);
}