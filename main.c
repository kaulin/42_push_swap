/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jajuntti <jajuntti@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:41:06 by jajuntti          #+#    #+#             */
/*   Updated: 2023/12/22 14:36:27 by jajuntti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Used libft functions: ft_printf, ft_isdigit, 

#include "push_swap.h"

static int	check_num(char *str)
{
	while (*str)
	{
		if (!ft_isdigit(*str) || *str != '-')
			return (1);
		str++;
	}
	return (0);
}

static int	check_args(int argc, char *argv[])
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

static t_list	*make_int_list(int argc, char *argv[])
{
	int		index;
	int		content;
	t_list	*list;
	t_list	*node;

	index = 1;
	list = NULL;
	while (index < argc)
	{
		content = ft_atoi(argv[index]);
		node = ft_lstnew(content);
		if (!node)
		{
			ft_lstclear(list);
			return (1);
		}
		ft_lstadd_back(&list, node);
		free(node);
		index++;
	}
}

int	main(int argc, char *argv[])
{
	t_list	*a;
	t_list	*b;
	
	if (argc < 2)
		return (0);
	if (check_args(argc, argv))
		return (ft_printf("Error!\n"));
	a = make_int_list(argc, argv);
	if (!a)
		return (ft_printf("Error!\n"));
	push_swap(&a, &b, argc - 1);
	return (0);
}