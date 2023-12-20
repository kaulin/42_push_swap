/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jajuntti <jajuntti@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:41:06 by jajuntti          #+#    #+#             */
/*   Updated: 2023/12/20 16:33:32 by jajuntti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_num(char *str)
{
	while (*str)
	{
		if (!ft_isdigit(*str) || !ft_strchr("-+", *str))
			return (1);
		str++;
	}
	return (0);
}

int	check_args(int argc, char *argv[])
{
	int	index;

	index = 1;
	while (index < argc)
	{
		if (check_num(argv[index]))
			return (1);
		index++;
	}
	return (0);	
}

int	main (int argc, char *argv[])
{
	if (argc < 2)
		return (0);
	if (check_args(argc, argv))
		return (ft_printf("Error!\n"));
	return (ft_printf("Perkele"));
}