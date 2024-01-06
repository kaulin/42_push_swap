/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dl_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jajuntti <jajuntti@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:41:06 by jajuntti          #+#    #+#             */
/*   Updated: 2024/01/06 12:53:07 by jajuntti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_dlist	*dl_lstnew(int value)
{
	t_dlist	*node;

	node = malloc(sizeof(t_dlist));
	if (!node)
		return (NULL);
	node->value = value;
	node->prev = node;
	node->next = NULL;
	return (node);
}

void	dl_lstadd_front(t_dlist **lst, t_dlist *new)
{
	if (!new)
		return ;
	if (*lst == NULL)
	{
		new->prev = new;
		new->next = NULL;
		*lst = new;
	}
	else
	{
		new->next = *lst;
		new->prev = (*lst)->prev;
		new->next->prev = new;
		*lst = new;
	}
}

void	dl_lstadd_back(t_dlist **lst, t_dlist *new)
{
	if (!new)
		return ;
	if (*lst == NULL)
	{
		new->prev = new;
		new->next = NULL;
		*lst = new;
	}
	else
	{
		new->next = NULL;
		new->prev = (*lst)->prev;
		new->prev->next = new;
		(*lst)->prev = new;
	}
}

int	dl_lstsize(t_dlist *lst)
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

void	dl_lstclear(t_dlist **lst)
{
	t_dlist	*next_node;

	if (lst == NULL)
		return ;
	while (*lst)
	{
		next_node = (*lst)->next;
		free(*lst);
		*lst = next_node;
	}
}
