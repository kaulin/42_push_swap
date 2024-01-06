/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jajuntti <jajuntti@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 17:07:17 by jajuntti          #+#    #+#             */
/*   Updated: 2024/01/06 12:51:11 by jajuntti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//
static void	swap(t_dlist **list)
{
	t_dlist	*node;

	node = (*list)->next;
	(*list)->next->next->prev = *list;
	(*list)->next = (*list)->next->next;
	dl_lstadd_front(list, node);
}

void	sa(t_dlist **a)
{
	swap(a);
	ft_printf("sa\n");
}

void	sb(t_dlist **b)
{
	swap(b);
	ft_printf("sb\n");
}

void	ss(t_dlist **a, t_dlist **b)
{
	swap(a);
	swap(b);
	ft_printf("ss\n");
}
