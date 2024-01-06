/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rrotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jajuntti <jajuntti@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 17:06:21 by jajuntti          #+#    #+#             */
/*   Updated: 2024/01/06 15:53:24 by jajuntti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
