/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rrotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jajuntti <jajuntti@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 17:06:21 by jajuntti          #+#    #+#             */
/*   Updated: 2024/01/06 12:51:11 by jajuntti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rrotate(t_dlist **list)
{
	(*list)->prev->next = *list;
	*list = (*list)->prev;
	(*list)->prev->next = NULL;
}

void	rra(t_dlist **a)
{
	rrotate(a);
	ft_printf("rra\n");
}

void	rrb(t_dlist **b)
{
	rrotate(b);
	ft_printf("rrb\n");
}

void	rrr(t_dlist **a, t_dlist **b)
{
	rrotate(a);
	rrotate(b);
	ft_printf("rrr\n");
}
