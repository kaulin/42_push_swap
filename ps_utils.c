/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jajuntti <jajuntti@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:40:50 by jajuntti          #+#    #+#             */
/*   Updated: 2024/01/25 10:13:36 by jajuntti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
Clears the list and returns NULL.
*/
t_dlist	*clean(t_dlist **list)
{
	dl_lstclear(list);
	return (NULL);
}

/*
Checks that the string complies with number format.
*/
static int	check_form(char *str)
{
	int	i;
	int	sign;

	i = 0;
	sign = 0;
	while (str[i] && ft_strchr(" \t\v\n\r\f", str[i]) != NULL)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		i++;
		sign = 1;
	}
	if (!str[i] && sign)
		return (1);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (1);
		i++;
	}
	return (0);
}

/*
Checks that the number is not already in the list.
*/
static int	check_dup(t_dlist *list, long num)
{
	while (list)
	{
		if (list->value == (int)num)
			return (1);
		list = list->next;
	}
	return (0);
}

/*
Makes a double linked list of integers from an array of an array of strings.
*/
t_dlist	*make_list(char *str[])
{
	int			index;
	long int	value;
	t_dlist		*list;
	t_dlist		*node;

	index = 0;
	list = NULL;
	while (str[index])
	{
		if (check_form(str[index]))
			return (clean(&list));
		value = ft_atol(str[index]);
		if (value > 2147483647 || value < -2147483648
			|| check_dup(list, value))
			return (clean(&list));
		node = dl_lstnew((int)value);
		if (!node)
			return (clean(&list));
		node->stack = 'a';
		dl_lstadd_back(&list, node);
		index++;
	}
	return (list);
}
