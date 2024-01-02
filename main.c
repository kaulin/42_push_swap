/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jajuntti <jajuntti@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:41:06 by jajuntti          #+#    #+#             */
/*   Updated: 2024/01/02 17:50:33 by jajuntti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_arr_len(char **arr)
{
	int	len;

	len = 0;
	while(arr[len])
		len++;
	return (len);
}

static void	clean_arr(char **arr)
{
	char	*str;

	str = *arr;
	while (str)
	{
		free(str);
		str++;
	}
	free(arr);
}

int	main(int argc, char *argv[])
{
	int	one_arg;

	one_arg = 0;
	if (argc < 2)
		return (0);
	if (argc == 2)
	{
		one_arg = 1;
		argv = ft_split(argv[1], ' ');
		argc = get_arr_len(argv);
	}
	else
	{
		argv = &argv[1];
		argc = argc -1;
	}
	if (!push_swap(argc, argv))
	{
		if (one_arg)
			clean_arr(argv);
		return (write(2, "Error\n", 7));
	}
	if (one_arg)
		clean_arr(argv);
	return (0);
}