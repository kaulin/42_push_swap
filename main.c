/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jajuntti <jajuntti@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:41:06 by jajuntti          #+#    #+#             */
/*   Updated: 2024/01/04 15:29:01 by jajuntti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_arr_len(char **arr)
{
	int	len;

	len = 0;
	while (arr[len])
		len++;
	return (len);
}

static void	clean_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

int	main(int argc, char *argv[])
{
	int		error;
	char	**split;

	error = 0;
	if (argc < 2)
		return (0);
	if (argc == 2)
	{
		split = ft_split(argv[1], " \t\v\n\r\f");
		argc = get_arr_len(split);
		error = push_swap(argc, split);
		clean_arr(split);
	}
	else
	{
		argv = &argv[1];
		argc = argc - 1;
		error = push_swap(argc, argv);
	}
	if (error)
		return (write(2, "Error\n", 7));
	return (0);
}
