/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jajuntti <jajuntti@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 16:46:54 by jajuntti          #+#    #+#             */
/*   Updated: 2024/01/06 15:52:49 by jajuntti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
