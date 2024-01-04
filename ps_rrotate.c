/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rrotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jajuntti <jajuntti@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 17:06:21 by jajuntti          #+#    #+#             */
/*   Updated: 2024/01/04 15:19:50 by jajuntti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rrotate(t_list **list)
{
	(*list)->previous->next = *list;
	*list = (*list)->previous;
	(*list)->previous->next = NULL;
}

void	rra(t_list **a)
{
	rrotate(a);
	ft_printf("rra\n");
}

void	rrb(t_list **b)
{
	rrotate(b);
	ft_printf("rrb\n");
}

void	rrr(t_list **a, t_list **b)
{
	rrotate(a);
	rrotate(b);
	ft_printf("rrr\n");
}
