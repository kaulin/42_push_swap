/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jajuntti <jajuntti@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:40:50 by jajuntti          #+#    #+#             */
/*   Updated: 2024/01/02 16:12:13 by jajuntti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*clean(t_list **list)
{
	dl_lstclear(list);
	return (NULL);
}

static int	check_form(char *str)
{
	int	i;
	
	i = 0;
	while (str[i] && ft_strchr(" \t\v\n\r\f", str[i]) != NULL)
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!ft_isdigit(str[i]))
		return (1);
	return (0);
}

static int	check_dup(t_list *list, long num)
{
	while (list)
	{
		if (list->content == (int)num)
			return (1);
		list = list->next;
	}
	return (0);
}

t_list	*make_list(int n, char *str[])
{
	int			index;
	long int	content;
	t_list		*list;
	t_list		*node;

	index = 0;
	list = NULL;
	while (index < n)
	{
		if (check_form(str[index]))
			return (clean(&list));
		content = ft_atol(str[index]);
		if (content > 2147483647 || content < -2147483648 
			|| check_dup(list, content))
			return (clean(&list));
		node = dl_lstnew((int)content);
		if (!node)
			return (clean(&list));
		dl_lstadd_back(&list, node);
		index++;
	}
	return (list);
}
