/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jajuntti <jajuntti@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 16:56:53 by jajuntti          #+#    #+#             */
/*   Updated: 2024/01/06 15:49:42 by jajuntti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
