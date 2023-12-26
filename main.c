/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jajuntti <jajuntti@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:41:06 by jajuntti          #+#    #+#             */
/*   Updated: 2023/12/26 14:18:36 by jajuntti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Used libft functions: ft_printf, ft_isdigit, 

#include "push_swap.h"

static int	check_num(char *str)
{
	int	index;

	index = 0;
	while (str[index])
	{
		if (!ft_isdigit(str[index]) && str[index] != '-')
			return (1);
		index++;
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
			ft_lstclear(&list);
			return (NULL);
		}
		ft_lstadd_back(&list, node);
		index++;
	}
	return (list);
}

int	main(int argc, char *argv[])
{
	t_list	*a;
	t_list	*b;
	
	if (argc < 2)
		return (0);
	if (check_args(argc, argv))
		return (ft_printf("ARG Error!\n"));
	a = make_int_list(argc, argv);
	b = NULL;
	if (!a)
		return (ft_printf("LIST Error!\n"));
	push_swap(&a, &b, argc - 1);
	ft_lstclear (a);
	ft_lstclear (b);
	return (0);
}