/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jajuntti <jajuntti@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 16:56:53 by jajuntti          #+#    #+#             */
/*   Updated: 2024/01/02 16:52:11 by jajuntti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_list **to, t_list **from)
{
	t_list	*node;

	node = *from;
	if (node->next)
		node->next->previous = node->previous;
	*from = node->next;
	dl_lstadd_front(to, node);
}

void	pa(t_list **a, t_list **b)
{
	push(a, b);
	ft_printf("pa\n");
}

void	pb(t_list **a, t_list **b)
{
	push(b, a);
	ft_printf("pb\n");
}
