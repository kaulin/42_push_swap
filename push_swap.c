/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jajuntti <jajuntti@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:41:06 by jajuntti          #+#    #+#             */
/*   Updated: 2024/01/26 14:12:07 by jajuntti         ###   ########.fr       */
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

/*
Combines all parameters into one big string, where they are separated 
by spaces.
*/
static int	make_string(int argc, char *argv[], char **string)
{
	int		index;
	char	*temp;

	index = 1;
	while (index < argc)
	{
		temp = ft_strjoin(*string, argv[index]);
		if (!temp)
		{
			free(*string);
			return (1);
		}
		free(*string);
		*string = temp;
		temp = ft_strjoin(*string, " ");
		if (!temp)
		{
			free(*string);
			return (1);
		}
		free(*string);
		*string = temp;
		index++;
	}
	return (0);
}

static int	push_swap(char *str[])
{
	t_dlist	*a;
	t_dlist	*b;
	int		len;

	a = make_list(str);
	if (!a)
		return (1);
	b = NULL;
	len = dl_lstsize(a);
	if (len == 1 || check_order(a))
	{
		min_to_top(&a, &b);
		dl_lstclear(&a);
		return (0);
	}
	sort_control(len, &a, &b);
	min_to_top(&a, &b);
	dl_lstclear(&a);
	return (0);
}

int	main(int argc, char *argv[])
{
	char	*string;
	char	**array;
	int		error;

	if (argc < 2)
		return (0);
	string = malloc(1);
	if (!string)
		return (ft_putendl_fd("Error", 2));
	*string = 0;
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
