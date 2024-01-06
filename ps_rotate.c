/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jajuntti <jajuntti@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 16:46:54 by jajuntti          #+#    #+#             */
/*   Updated: 2024/01/06 12:51:11 by jajuntti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_dlist **list)
{
	(*list)->prev->next = *list;
	*list = (*list)->next;
	(*list)->prev->next = NULL;
}

void	ra(t_dlist **a)
{
	rotate(a);
	ft_printf("ra\n");
}

void	rb(t_dlist **b)
{
	rotate(b);
	ft_printf("rb\n");
}

void	rr(t_dlist **a, t_dlist **b)
{
	rotate(a);
	rotate(b);
	ft_printf("rr\n");
}
