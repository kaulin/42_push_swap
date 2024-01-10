/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jajuntti <jajuntti@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 15:47:55 by jajuntti          #+#    #+#             */
/*   Updated: 2024/01/10 11:03:36 by jajuntti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_dlist **from, t_dlist **to)
{
	t_dlist	*node;

	if (!(*from))
		return ;
	node = *from;
	if (node->next)
		node->next->prev = node->prev;
	*from = node->next;
	dl_lstadd_front(to, node);
}

void	swap(t_dlist **list)
{
	t_dlist	*node;

	if (!(*list))
		return ;
	node = (*list)->next;
	(*list)->next->next->prev = *list;
	(*list)->next = (*list)->next->next;
	dl_lstadd_front(list, node);
}

void	rotate(t_dlist **list)
{
	if (!(*list))
		return ;
	(*list)->prev->next = *list;
	*list = (*list)->next;
	(*list)->prev->next = NULL;
}

void	revrot(t_dlist **list)
{
	if (!(*list))
		return ;
	(*list)->prev->next = *list;
	*list = (*list)->prev;
	(*list)->prev->next = NULL;
}
