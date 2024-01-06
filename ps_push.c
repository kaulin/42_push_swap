/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jajuntti <jajuntti@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 16:56:53 by jajuntti          #+#    #+#             */
/*   Updated: 2024/01/06 12:51:11 by jajuntti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_dlist **to, t_dlist **from)
{
	t_dlist	*node;

	node = *from;
	if (node->next)
		node->next->prev = node->prev;
	*from = node->next;
	dl_lstadd_front(to, node);
}

void	pa(t_dlist **a, t_dlist **b)
{
	push(a, b);
	ft_printf("pa\n");
}

void	pb(t_dlist **a, t_dlist **b)
{
	push(b, a);
	ft_printf("pb\n");
}
