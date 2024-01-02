/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dl_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jajuntti <jajuntti@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:41:06 by jajuntti          #+#    #+#             */
/*   Updated: 2023/12/29 16:41:49 by jajuntti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*dl_lstnew(int content)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = content;
	node->previous = node;
	node->next = NULL;
	return (node);
}

void	dl_lstadd_front(t_list **lst, t_list *new)
{
	if (!new)
		return ;
	if (*lst == NULL)
	{
		new->previous = new;
		new->next = NULL;
		*lst = new;
	}
	else
	{
		new->next = *lst;
		new->previous = (*lst)->previous;
		new->next->previous = new;
		*lst = new;
	}
}

void	dl_lstadd_back(t_list **lst, t_list *new)
{
	if (!new)
		return ;
	if (*lst == NULL)
	{
		new->previous = new;
		new->next = NULL;
		*lst = new;
	}
	else
	{
		new->next = NULL;
		new->previous = (*lst)->previous;
		new->previous->next = new;
		(*lst)->previous = new;
	}
}

int	dl_lstsize(t_list *lst)
{
	int		size;

	size = 0;
	while (lst)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}

void	dl_lstclear(t_list **lst)
{
	t_list	*next_node;

	if (lst == NULL)
		return ;
	while (*lst)
	{
		next_node = (*lst)->next;
		free(*lst);
		*lst = next_node;
	}
}
