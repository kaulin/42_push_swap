/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jajuntti <jajuntti@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:41:06 by jajuntti          #+#    #+#             */
/*   Updated: 2024/01/25 08:48:34 by jajuntti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	clean_arr(char **arr)
{
	int	index;

	index = 0;
	while (arr[index])
		free(arr[index++]);
	free(arr);
}

static int	make_string(int argc, char *argv[], char **string)
{
	int		index;
	char	*temp;

	index = 1;
	*string = "";
	while (index < argc)
	{
		temp = ft_strjoin(*string, argv[index]);
		if (!temp)
		{
			free(*string);
			return (1);
		}
		*string = temp;
		temp = ft_strjoin(*string, " ");
		if (!temp)
		{
			free(*string);
			return (1);
		}
		*string = temp;
		index++;
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	char	*string;
	char	**array;
	int		error;
	
	if (argc < 2)
		return (0);
	error = make_string(argc, argv, &string);
	if (error)
		return (ft_putendl_fd("Error", 2));
	array = ft_split(string, " \t\v\n\r\f");
	error = push_swap(array);
	free(string);
	clean_arr(array);
	if (error)
		return (ft_putendl_fd("Error", 2));
	return (0);
}
